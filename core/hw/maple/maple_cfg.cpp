#include "types.h"
#include "maple_if.h"
#include "maple_helper.h"
#include "maple_devs.h"
#include "maple_cfg.h"

#define HAS_VMU
/*
bus_x=0{p0=1{config};p1=2{config};config;}
Plugins:
	Input Source
		EventMap -- 'Raw' interface, source_name[seid]:mode
		KeyMap -- translated chars ( no re-mapping possible)
	Output
		Image
		
*/
/*
	MapleConfig:
		InputUpdate(&fmt);
		ImageUpdate(data);
*/
void UpdateInputState(u32 port);
void UpdateVibration(u32 port, u32 value);

extern u16 kcode[4];
extern u32 vks[4];
extern s8 joyx[4],joyy[4];
extern u8 rt[4],lt[4];
extern bool enable_purupuru;

const char* VMU_SCREEN_COLOR_NAMES[VMU_NUM_COLORS] = {
		"DEFAULT_ON",
		"DEFAULT_OFF",
		"BLACK",
		"BLUE",
		"LIGHT_BLUE",
		"GREEN",
		"GREEN_BLUE",
		"GREEN_LIGHT_BLUE",
		"LIGHT_GREEN",
		"LIGHT_GREEN_BLUE",
		"LIGHT_GREEN_LIGHT_BLUE",
		"RED",
		"RED_BLUE",
		"RED_LIGHT_BLUE",
		"RED_GREEN",
		"RED_GREEN_BLUE",
		"RED_GREEN_LIGHT_BLUE",
		"RED_LIGHT_GREEN",
		"RED_LIGHT_GREEN_BLUE",
		"RED_LIGHT_GREEN_LIGHT_BLUE",
		"LIGHT_RED",
		"LIGHT_RED_BLUE",
		"LIGHT_RED_LIGHT_BLUE",
		"LIGHT_RED_GREEN",
		"LIGHT_RED_GREEN_BLUE",
		"LIGHT_RED_GREEN_LIGHT_BLUE",
		"LIGHT_RED_LIGHT_GREEN",
		"LIGHT_RED_LIGHT_GREEN_BLUE",
		"WHITE"
};
const rgb_t VMU_SCREEN_COLOR_MAP[VMU_NUM_COLORS] = {
		{ DEFAULT_VMU_PIXEL_ON_R,   DEFAULT_VMU_PIXEL_ON_G ,   DEFAULT_VMU_PIXEL_ON_B  },
		{ DEFAULT_VMU_PIXEL_OFF_R,  DEFAULT_VMU_PIXEL_OFF_G ,  DEFAULT_VMU_PIXEL_OFF_B  },
		{ 0x00, 0x00, 0x00 },
		{ 0x00, 0x00, 0x7F },
		{ 0x00, 0x00, 0xFF },
		{ 0x00, 0x7F, 0x00 },
		{ 0x00, 0x7F, 0x7F },
		{ 0x00, 0x7F, 0xFF },
		{ 0x00, 0xFF, 0x00 },
		{ 0x00, 0xFF, 0x7F },
		{ 0x00, 0xFF, 0xFF },
		{ 0x7F, 0x00, 0x00 },
		{ 0x7F, 0x00, 0x7F },
		{ 0x7F, 0x00, 0xFF },
		{ 0x7F, 0x7F, 0x00 },
		{ 0x7F, 0x7F, 0x7F },
		{ 0x7F, 0x7F, 0xFF },
		{ 0x7F, 0xFF, 0x00 },
		{ 0x7F, 0xFF, 0x7F },
		{ 0x7F, 0xFF, 0xFF },
		{ 0xFF, 0x00, 0x00 },
		{ 0xFF, 0x00, 0x7F },
		{ 0xFF, 0x00, 0xFF },
		{ 0xFF, 0x7F, 0x00 },
		{ 0xFF, 0x7F, 0x7F },
		{ 0xFF, 0x7F, 0xFF },
		{ 0xFF, 0xFF, 0x00 },
		{ 0xFF, 0xFF, 0x7F },
		{ 0xFF, 0xFF, 0xFF }
};

vmu_screen_params_t vmu_screen_params[4] ;

MapleDeviceType maple_devices[MAPLE_PORTS] =
   { MDT_SegaController, MDT_SegaController, MDT_SegaController, MDT_SegaController };
bool use_lightgun = false;	// Naomi only

u8 GetBtFromSgn(s8 val)
{
	return val+128;
}

struct MapleConfigMap : IMapleConfigMap
{
	maple_device* dev;

	MapleConfigMap(maple_device* dev)
	{
		this->dev=dev;
	}

   void SetVibration(u32 value)
   {
      UpdateVibration(dev->bus_id, value);
   }

	void GetInput(PlainJoystickState* pjs)
	{
		UpdateInputState(dev->bus_id);

		pjs->kcode=kcode[dev->bus_id] | 0xF901;
		pjs->joy[PJAI_X1]=GetBtFromSgn(joyx[dev->bus_id]);
		pjs->joy[PJAI_Y1]=GetBtFromSgn(joyy[dev->bus_id]);
		pjs->trigger[PJTI_R]=rt[dev->bus_id];
		pjs->trigger[PJTI_L]=lt[dev->bus_id];
	}
	void SetImage(void* img)
	{
		vmu_screen_params[dev->bus_id].vmu_screen_needs_update = true ;
	}
};

void mcfg_Create(MapleDeviceType type,u32 bus,u32 port)
{
	maple_device* dev=maple_Create(type);
	dev->Setup(maple_GetAddress(bus,port));
	dev->config = new MapleConfigMap(dev);
	dev->OnSetup();
	MapleDevices[bus][port]=dev;
}

void mcfg_CreateDevices()
{
   int bus ;

   for ( bus = 0 ; bus < MAPLE_PORTS; bus++)
      vmu_screen_params[bus].vmu_lcd_screen = NULL ;


   if (settings.System == DC_PLATFORM_DREAMCAST)
   {
	  for (bus = 0; bus < MAPLE_PORTS; ++bus)
	  {
		 switch (maple_devices[bus])
		 {
		 case MDT_SegaController:
			mcfg_Create(MDT_SegaController, bus, 5);
			mcfg_Create(MDT_SegaVMU, bus, 0);

			if (enable_purupuru)
			   mcfg_Create(MDT_PurupuruPack, bus, 1);
			else
			   mcfg_Create(MDT_SegaVMU, bus, 1);
			break;

		 case MDT_Keyboard:
			 mcfg_Create(MDT_Keyboard, bus, 5);
			 break;

		 case MDT_Mouse:
			 mcfg_Create(MDT_Mouse, bus, 5);
			 break;

		 case MDT_LightGun:
			 mcfg_Create(MDT_LightGun, bus, 5);
			 if (enable_purupuru)
				mcfg_Create(MDT_PurupuruPack, bus, 0);
			 else
				mcfg_Create(MDT_SegaVMU, bus, 0);
			 break;
		 }
	  }
   }
   else
   {
      use_lightgun = false;
	  for (int i = 0; i < MAPLE_PORTS; i++)
		 if (maple_devices[i] == MDT_LightGun)
			use_lightgun = true;

	  bus = 0;
      mcfg_Create(MDT_NaomiJamma, bus++, 5);
	  for (int i = 0; i < MAPLE_PORTS; i++)
	  {
		 switch (maple_devices[i])
		 {
		 case MDT_Keyboard:
			mcfg_Create(MDT_Keyboard, bus++, 5);
			break;
		 default:
			break;
		 }
	  }
   }
}


void mcfg_DestroyDevices()
{
	for (int i = 0; i < MAPLE_PORTS; i++)
		for (int j=0;j<=5;j++)
		{
			delete MapleDevices[i][j];
			MapleDevices[i][j] = NULL;
		}
}

void mcfg_DestroyDevice(int i, int j)
{
	delete MapleDevices[i][j];
	MapleDevices[i][j] = NULL;
}

void mcfg_SerializeDevices(void **data, unsigned int *total_size)
{
	for (int i = 0; i < MAPLE_PORTS; i++)
		for (int j = 0; j < 6; j++)
		{
			u8 **p = (u8 **)data;
			if (MapleDevices[i][j] != NULL)
			{
				if (*p != NULL)
				{
					**p = MapleDevices[i][j]->get_device_type();
					*p = *p + 1;
				}
				MapleDevices[i][j]->maple_serialize(data, total_size);
			}
			else if (*p != NULL)
			{
				**p = MDT_None;
				*p = *p + 1;
			}
			*total_size = *total_size + 1;
		}
}

void mcfg_UnserializeDevices(void **data, unsigned int *total_size)
{
	mcfg_DestroyDevices();

	for (int i = 0; i < MAPLE_PORTS; i++)
		for (int j = 0; j < 6; j++)
		{
			u8 **p = (u8 **)data;
			MapleDeviceType device_type = (MapleDeviceType)**p;
			*p = *p + 1;
			*total_size = *total_size + 1;
			if (device_type != MDT_None)
			{
				mcfg_Create(device_type, i, j);
				MapleDevices[i][j]->maple_unserialize(data, total_size);
			}
		}
}
