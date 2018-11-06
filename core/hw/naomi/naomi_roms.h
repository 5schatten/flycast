/*
	Created on: Nov 2, 2018

	Copyright 2018 flyinghead

	Rom information from mame (https://github.com/mamedev/mame)
	license:LGPL-2.1+
	copyright-holders: Samuele Zannoli, R. Belmont, ElSemi, David Haywood, Angelo Salese, Olivier Galibert, MetalliC

	This file is part of reicast.

    reicast is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    reicast is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with reicast.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#define MAX_GAME_FILES 40

enum BlobType {
	Normal = 0,
	SwapWordBytes = 0,
	InterleavedWord,
	Copy,
	M4Key
};

enum CartridgeType {
	M1,
	M2,
	M4,
	AW
};

struct BIOS_t
{
	const char* name;
	struct
	{
		const char* filename;
		u32 offset;
		u32 length;
		BlobType blob_type;
		u32 src_offset;		// For copy
	} blobs[MAX_GAME_FILES];
}
BIOS[] =
{
	{
		"airlbios.zip",
		{
			{ "epr-21802.ic27", 0x000000, 0x200000 },
			// or
			//{ "epr-21801.ic27", 0x000000, 0x200000 },
			{ NULL, 0, 0 },
		}
	},
	{
		"f355bios.zip",
		{
			{ "epr-22851.ic27", 0x000000, 0x200000 },
			//{ "epr-22850.ic27", 0x000000, 0x200000 },
			//{ "epr-22849.ic27", 0x000000, 0x200000 },
			{ NULL, 0, 0 },
		}
	},
	{
		"f355dlx.zip",
		{
			// Ferrari F355 Deluxe (Export)
			//{ "epr-21864.ic27", 0x000000, 0x200000 },
			// Ferrari F355 Deluxe (USA)
			{ "epr-21863.ic27", 0x000000, 0x200000 },
			// Ferrari F355 Deluxe (Japan)
			//{ "epr-21862.ic27", 0x000000, 0x200000 },
			// Ferrari F355 Deluxe (Export, prototype)
			//{ "epr-21864p.ic27", 0x000000, 0x200000 },
			// Ferrari F355 Deluxe (Japan, prototype)
			//{ "epr-21862p.ic27", 0x000000, 0x200000 },
			{ NULL, 0, 0 },
		}
	},
	{
		"naomi.zip",
		{
				//ROM_SYSTEM_BIOS( 0, "bios0",   "epr-21576h (Japan)" )
				{ "epr-21576h.ic27", 0x000000, 0x200000 },
				//ROM_SYSTEM_BIOS( 1, "bios1",   "epr-21576g (Japan)" )
//				{ "epr-21576g.ic27", 0x000000, 0x200000 },
				//ROM_SYSTEM_BIOS( 2, "bios2",   "epr-21576e (Japan)" )
//				{ "epr-21576e.ic27", 0x000000, 0x200000 },
				//ROM_SYSTEM_BIOS( 3, "bios3",   "epr-21576d (Japan)" )
//				{ "epr-21576d.ic27", 0x000000, 0x200000 },
//				ROM_SYSTEM_BIOS( 4, "bios4",   "epr-21576c (Japan)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 4,  "epr-21576c.ic27", 0x000000, 0x200000, BAD_DUMP CRC(4599ad13) SHA1(7e730e9452a792d76f210c33a955d385538682c7) ) \
//				ROM_SYSTEM_BIOS( 5, "bios5",   "epr-21576b (Japan)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 5,  "epr-21576b.ic27", 0x000000, 0x200000, CRC(755a6e07) SHA1(7e8b8ccfc063144d89668e7224dcd8a36c54f3b3) ) \
//				ROM_SYSTEM_BIOS( 6, "bios6",   "epr-21576a (Japan)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 6,  "epr-21576a.ic27", 0x000000, 0x200000, CRC(cedfe439) SHA1(f27798bf3d890863ef0c1d9dcb4e7782249dca27) ) \
//				ROM_SYSTEM_BIOS( 7, "bios7",   "epr-21576 (Japan)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 7,  "epr-21576.ic27",  0x000000, 0x200000, CRC(9dad3495) SHA1(5fb66f9a2b68d120f059c72758e65d34f461044a) ) \
//				ROM_SYSTEM_BIOS( 8, "bios8",   "epr-21578h (Export)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 8,  "epr-21578h.ic27", 0x000000, 0x200000, CRC(7b452946) SHA1(8e9f153bbada24b37066dc45b64a7bf0d4f26a9b) ) \
//				ROM_SYSTEM_BIOS( 9, "bios9",   "epr-21578g (Export)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 9,  "epr-21578g.ic27", 0x000000, 0x200000, CRC(55413214) SHA1(bd2748365a9fc1821c9369aa7155d7c41c4df43e) ) \
//				ROM_SYSTEM_BIOS( 10, "bios10", "epr-21578f (Export)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 10, "epr-21578f.ic27", 0x000000, 0x200000, CRC(628a27fd) SHA1(dae7add616b1a2478f00608823e88c3b82a0e78f) ) \
//				ROM_SYSTEM_BIOS( 11, "bios11", "epr-21578e (Export)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 11, "epr-21578e.ic27", 0x000000, 0x200000, CRC(087f09a3) SHA1(0418eb2cf9766f0b1b874a4e92528779e22c0a4a) ) \
//				ROM_SYSTEM_BIOS( 12, "bios12", "epr-21578d (Export)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 12, "epr-21578d.ic27", 0x000000, 0x200000, CRC(dfd5f42a) SHA1(614a0db4743a5e5a206190d6786ade24325afbfd) ) \
//				ROM_SYSTEM_BIOS( 13, "bios13", "epr-21578a (Export)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 13, "epr-21578a.ic27", 0x000000, 0x200000, CRC(6c9aad83) SHA1(555918de76d8dbee2a97d8a95297ef694b3e803f) ) \
				//ROM_SYSTEM_BIOS( 14, "bios14", "epr-21577h (USA)" )
//				{ "epr-21577h.ic27", 0x000000, 0x200000 },
//				ROM_SYSTEM_BIOS( 15, "bios15", "epr-21577g (USA)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 15, "epr-21577g.ic27", 0x000000, 0x200000, CRC(25f64af7) SHA1(99f9e6cc0642319bd2da492611220540add573e8) ) \
//				ROM_SYSTEM_BIOS( 16, "bios16", "epr-21577e (USA)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 16, "epr-21577e.ic27", 0x000000, 0x200000, CRC(cf36e97b) SHA1(b085305982e7572e58b03a9d35f17ae319c3bbc6) ) \
//				ROM_SYSTEM_BIOS( 17, "bios17", "epr-21577d (USA)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 17, "epr-21577d.ic27", 0x000000, 0x200000, CRC(60ddcbbe) SHA1(58b15096d269d6df617ca1810b66b47deb184958) ) \
//				ROM_SYSTEM_BIOS( 18, "bios18", "epr-21577a (USA)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 18, "epr-21577a.ic27", 0x000000, 0x200000, CRC(969dc491) SHA1(581d1eae328b87b67508a7586ffc60cee256f70f) ) \
//				ROM_SYSTEM_BIOS( 19, "bios19", "epr-21579d (Korea)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 19, "epr-21579d.ic27", 0x000000, 0x200000, CRC(33513691) SHA1(b1d8c7c516e1471a788fcf7a02a794ad2f05aeeb) ) \
//				ROM_SYSTEM_BIOS( 20, "bios20", "epr-21579 (Korea)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 20, "epr-21579.ic27",  0x000000, 0x200000, CRC(71f9c918) SHA1(d15af8b947f41eea7c203b565cd403e3f37a2017) ) \
//				ROM_SYSTEM_BIOS( 21, "bios21", "Set4 Dev BIOS" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 21, "boot_rom_64b8.ic606", 0x000000, 0x080000, CRC(7a50fab9) SHA1(ef79f448e0bf735d1264ad4f051d24178822110f) ) \
//				ROM_SYSTEM_BIOS( 22, "bios22", "Dev BIOS v1.10" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 22, "develop110.ic27", 0x000000, 0x200000, CRC(de7cfdb0) SHA1(da16800edc4d49f70481c124d487f544c2fa8ce7) ) \
//				ROM_SYSTEM_BIOS( 23, "bios23", "Dev BIOS (Nov 1998)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 23, "develop.ic27", 0x000000, 0x200000, CRC(309a196a) SHA1(409b50371feb648f10efd6b7ac420bf08d9a3b5a) ) \
//				ROM_SYSTEM_BIOS( 24, "bios24", "Development ROM Board" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 24, "zukinver0930.ic25", 0x000000, 0x200000, CRC(58e17c23) SHA1(19330f906accf1b859f56bbcedc2edff73747599) ) \
//				ROM_SYSTEM_BIOS( 25, "bios25", "epr-21576h (multi-region hack)" ) \
//				ROM_LOAD16_WORD_SWAP_BIOS( 25, "epr-21576h_multi.ic27", 0x000000, 0x200000, CRC(cce01f1f) SHA1(cca17119ad13e3a4ef7cb6902a37b65d6a844aee) ) \
//				ROM_REGION( 0x4000, "altera_pof", 0) \
//				ROM_LOAD("315-6188.ic31", 0x0000, 0x2034, CRC(7c9fea46) SHA1(f77c07ae65dfed18c1c4c632c8945be21d02ddaf) )
			{ NULL, 0, 0 },
		}
	},
	{
		NULL,
	}
};

struct Game
{
	const char* name;
	u32 size;
	u32 key;
	const char *bios;
	CartridgeType cart_type;
	struct
	{
		const char* filename;
		u32 offset;
		u32 length;
		BlobType blob_type;
		u32 src_offset;		// For copy
	} blobs[MAX_GAME_FILES];
}
Games[] =
{
	// 18 Wheeler (deluxe) (Rev A)
	{
		"18wheelr.zip",
		0x0a800000,
		0x2807cf54,
		NULL,
		M2,
		{
			{ "epr-22185a.ic22", 0x0000000, 0x400000 },
			{ "mpr-22164.ic1",   0x0800000, 0x800000 },
			{ "mpr-22165.ic2",   0x1000000, 0x800000 },
			{ "mpr-22166.ic3",   0x1800000, 0x800000 },
			{ "mpr-22167.ic4",   0x2000000, 0x800000 },
			{ "mpr-22168.ic5",   0x2800000, 0x800000 },
			{ "mpr-22169.ic6",   0x3000000, 0x800000 },
			{ "mpr-22170.ic7",   0x3800000, 0x800000 },
			{ "mpr-22171.ic8",   0x4000000, 0x800000 },
			{ "mpr-22172.ic9",   0x4800000, 0x800000 },
			{ "mpr-22173.ic10",  0x5000000, 0x800000 },
			{ "mpr-22174.ic11",  0x5800000, 0x800000 },
			{ "mpr-22175.ic12s", 0x6000000, 0x800000 },
			{ "mpr-22176.ic13s", 0x6800000, 0x800000 },
			{ "mpr-22177.ic14s", 0x7000000, 0x800000 },
			{ "mpr-22178.ic15s", 0x7800000, 0x800000 },
			{ "mpr-22179.ic16s", 0x8000000, 0x800000 },
			{ "mpr-22180.ic17s", 0x8800000, 0x800000 },
			{ "mpr-22181.ic18s", 0x9000000, 0x800000 },
			{ "mpr-22182.ic19s", 0x9800000, 0x800000 },
			{ "mpr-22183.ic20s", 0xa000000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Alien Front (Rev T)
	{
		"alienfnt.zip",
		0x05800000,
		0x28174343,
		NULL,
		M2,
		{
			{ "epr-23586t.ic22", 0x0000000, 0x0400000 },
			{ "mpr-23581.ic1",   0x0800000, 0x1000000 },
			{ "mpr-23582.ic2",   0x1800000, 0x1000000 },
			{ "mpr-23583.ic3",   0x2800000, 0x1000000 },
			{ "mpr-23584.ic4",   0x3800000, 0x1000000 },
			{ "mpr-23585.ic5",   0x4800000, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Akatsuki Blitzkampf Ausf. Achse (Japan)
	{
		"ausfache.zip",
		0x10000000,
		0x5504,
		"naomi.zip",
		M4,
		{
			{ "ic8.bin",    0x0000000, 0x4000000 },
			{ "ic9.bin",    0x4000000, 0x4000000 },
			// IC10 and IC11 Populated, Empty
			{ "317-05130-jpn.ic3", 0, 0x800, M4Key },
			{ NULL, 0, 0 },
		}
	},
	// Crackin' DJ
	{
		"crackndj.zip",
		0x0a800000,
		0x281c2347,
		NULL,
		M2,
		{
			{ "epr-23450.ic22", 0x0000000, 0x400000 },
			{ "mpr-23525.ic1",  0x0800000, 0x1000000 },
			{ "mpr-23526.ic2",  0x1800000, 0x1000000 },
			{ "mpr-23527.ic3",  0x2800000, 0x1000000 },
			{ "mpr-23528.ic4",  0x3800000, 0x1000000 },
			{ "mpr-23529.ic5",  0x4800000, 0x1000000 },
			{ "mpr-23530.ic6",  0x5800000, 0x1000000 },
			{ "mpr-23531.ic7",  0x6800000, 0x1000000 },
			{ "mpr-23532.ic8",  0x7800000, 0x1000000 },
			{ "mpr-23533.ic9",  0x8800000, 0x1000000 },
			{ "mpr-23534.ic10", 0x9800000, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Crackin' DJ Part 2 (Japan)
	{
		"crakndj2.zip",
		0x0a800000,
		0x28428247,
		NULL,
		M2,
		{
			{ "epr-23674.ic22", 0x000000, 0x400000 },
			{ "rom1.ic1s",    0x0800000, 0x800000 },
			{ "rom2.ic2s",    0x1000000, 0x800000 },
			{ "rom3.ic3s",    0x1800000, 0x800000 },
			{ "rom4.ic4s",    0x2000000, 0x800000 },
			{ "rom5.ic5s",    0x2800000, 0x800000 },
			{ "rom6.ic6s",    0x3000000, 0x800000 },
			{ "rom7.ic7s",    0x3800000, 0x800000 },
			{ "rom8.ic8s",    0x4000000, 0x800000 },
			{ "rom9.ic9s",    0x4800000, 0x800000 },
			{ "rom10.ic10s",  0x5000000, 0x800000 },
			{ "rom11.ic11s",  0x5800000, 0x800000 },
			{ "rom12.ic12s",  0x6000000, 0x800000 },
			{ "rom13.ic13s",  0x6800000, 0x800000 },
			{ "rom14.ic14s",  0x7000000, 0x800000 },
			{ "rom15.ic15s",  0x7800000, 0x800000 },
			{ "rom16.ic16s",  0x8000000, 0x800000 },
			{ "rom17.ic17s",  0x8800000, 0x800000 },
			{ "rom18.ic18s",  0x9000000, 0x800000 },
			{ "rom19.ic19s",  0x9800000, 0x800000 },
			{ "rom20.ic20s",  0xa000000, 0x800000 },
			//ROM_REGION(0x84, "some_eeprom", 0)
			//ROM_LOAD("sflash.ic37", 0x000000, 0x000084, CRC(08f27149) SHA1(3b8d53dcf2c09035b318022906c444cf8504d7fa) )
			{ NULL, 0, 0 },
		}
	},
	// Crazy Taxi
	{
		"crzytaxi.zip",
		0x08800000,
		0x280d2f45,
		NULL,
		M2,
		{
			{ "epr-21684.ic22",  0x0000000, 0x400000 },
			{ "mpr-21671.ic1",   0x0800000, 0x800000 },
			{ "mpr-21672.ic2",   0x1000000, 0x800000 },
			{ "mpr-21673.ic3",   0x1800000, 0x800000 },
			{ "mpr-21674.ic4",   0x2000000, 0x800000 },
			{ "mpr-21675.ic5",   0x2800000, 0x800000 },
			{ "mpr-21676.ic6",   0x3000000, 0x800000 },
			{ "mpr-21677.ic7",   0x3800000, 0x800000 },
			{ "mpr-21678.ic10",  0x5000000, 0x800000 },
			{ "mpr-21679.ic11",  0x5800000, 0x800000 },
			{ "mpr-21680.ic12s", 0x6000000, 0x800000 },
			{ "mpr-21681.ic13s", 0x6800000, 0x800000 },
			{ "mpr-21682.ic14s", 0x7000000, 0x800000 },
			{ "mpr-21683.ic15s", 0x7800000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Cosmic Smash (Rev A)
	{
		"csmash.zip",
		0x04800000,
		0x28103347,
		NULL,
		M2,
		{
			{ "epr-23428a.ic22", 0x0000000, 0x400000 },
			{ "mpr-23420.ic1",   0x0800000, 0x0800000 },
			{ "mpr-23421.ic2",   0x1000000, 0x0800000 },
			{ "mpr-23422.ic3",   0x1800000, 0x0800000 },
			{ "mpr-23423.ic4",   0x2000000, 0x0800000 },
			{ "mpr-23424.ic5",   0x2800000, 0x0800000 },
			{ "mpr-23425.ic6",   0x3000000, 0x0800000 },
			{ "mpr-23426.ic7",   0x3800000, 0x0800000 },
			{ "mpr-23427.ic8",   0x4000000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Cannon Spike / Gun Spike
	{
		"cspike.zip",
		0x06800000,
		0x000e2010,
		NULL,
		M2,
		{
			{ "epr-23210.ic22", 0x0000000, 0x0400000 },
			{ "mpr-23198.ic1",  0x0800000, 0x0800000 },
			{ "mpr-23199.ic2",  0x1000000, 0x0800000 },
			{ "mpr-23200.ic3",  0x1800000, 0x0800000 },
			{ "mpr-23201.ic4",  0x2000000, 0x0800000 },
			{ "mpr-23202.ic5",  0x2800000, 0x0800000 },
			{ "mpr-23203.ic6",  0x3000000, 0x0800000 },
			{ "mpr-23204.ic7",  0x3800000, 0x0800000 },
			{ "mpr-23205.ic8",  0x4000000, 0x0800000 },
			{ "mpr-23206.ic9",  0x4800000, 0x0800000 },
			{ "mpr-23207.ic10", 0x5000000, 0x0800000 },
			{ "mpr-23208.ic11", 0x5800000, 0x0800000 },
			{ "mpr-23209.ic12s",0x6000000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Death Crimson OX
	{
		"deathcoxo.zip",
		0x05800000,
		0x000b64d0,
		NULL,
		M2,
		{
			{ "epr-23524.ic22",0x0000000, 0x0400000 },
			{ "mpr-23514.ic1", 0x0800000, 0x0800000 },
			{ "mpr-23515.ic2", 0x1000000, 0x0800000 },
			{ "mpr-23516.ic3", 0x1800000, 0x0800000 },
			{ "mpr-23517.ic4", 0x2000000, 0x0800000 },
			{ "mpr-23518.ic5", 0x2800000, 0x0800000 },
			{ "mpr-23519.ic6", 0x3000000, 0x0800000 },
			{ "mpr-23520.ic7", 0x3800000, 0x0800000 },
			{ "mpr-23521.ic8", 0x4000000, 0x0800000 },
			{ "mpr-23522.ic9", 0x4800000, 0x0800000 },
			{ "mpr-23523.ic10",0x5000000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Dynamite Baseball NAOMI (Japan)
	{
		"dybbnao.zip",
		0x0b000000,
		0x280e6ae1,
		NULL,
		M2,
		{
			{ "epr-21575.ic22",  0x0000000, 0x0200000 },
			{ "epr-21575.ic22",  0x0200000, 0x0200000 },	// Reload
			{ "mpr-21554.ic1",   0x0800000, 0x0800000 },
			{ "mpr-21555.ic2",   0x1000000, 0x0800000 },
			{ "mpr-21556.ic3",   0x1800000, 0x0800000 },
			{ "mpr-21557.ic4",   0x2000000, 0x0800000 },
			{ "mpr-21558.ic5",   0x2800000, 0x0800000 },
			{ "mpr-21559.ic6",   0x3000000, 0x0800000 },
			{ "mpr-21560.ic7",   0x3800000, 0x0800000 },
			{ "mpr-21561.ic8",   0x4000000, 0x0800000 },
			{ "mpr-21562.ic9",   0x4800000, 0x0800000 },
			{ "mpr-21563.ic10",  0x5000000, 0x0800000 },
			{ "mpr-21564.ic11",  0x5800000, 0x0800000 },
			{ "mpr-21565.ic12s", 0x6000000, 0x0800000 },
			{ "mpr-21566.ic13s", 0x6800000, 0x0800000 },
			{ "mpr-21567.ic14s", 0x7000000, 0x0800000 },
			{ "mpr-21568.ic15s", 0x7800000, 0x0800000 },
			{ "mpr-21569.ic16s", 0x8000000, 0x0800000 },
			{ "mpr-21570.ic17s", 0x8800000, 0x0800000 },
			{ "mpr-21571.ic18s", 0x9000000, 0x0800000 },
			{ "mpr-21572.ic19s", 0x9800000, 0x0800000 },
			{ "mpr-21573.ic20s", 0xa000000, 0x0800000 },
			{ "mpr-21574.ic21s", 0xa800000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Mobile Suit Gundam: Federation Vs. Zeon
	{
		"gundmct.zip",
		0x0a800000,
		0x000e8010,
		NULL,
		M2,
		{
			{ "epr-23638.ic22", 0x0000000, 0x0400000 },
			{ "mpr-23628.ic1",  0x0800000, 0x1000000 },
			{ "mpr-23629.ic2",  0x1800000, 0x1000000 },
			{ "mpr-23630.ic3",  0x2800000, 0x1000000 },
			{ "mpr-23631.ic4",  0x3800000, 0x1000000 },
			{ "mpr-23632.ic5",  0x4800000, 0x1000000 },
			{ "mpr-23633.ic6",  0x5800000, 0x1000000 },
			{ "mpr-23634.ic7",  0x6800000, 0x1000000 },
			{ "mpr-23635.ic8",  0x7800000, 0x1000000 },
			{ "mpr-23636.ic9",  0x8800000, 0x1000000 },
			{ "mpr-23637.ic10", 0x9800000, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Giga Wing 2
	{
		"gwing2.zip",
		0x05800000,
		0x000b25d0,
		NULL,
		M2,
		{
			{ "epr-22270.ic22", 0x0000000, 0x0200000 },
			{ "epr-22270.ic22", 0x0200000, 0x0200000 },	// Reload
			{ "mpr-22271.ic1", 0x0800000, 0x1000000 },
			{ "mpr-22272.ic2", 0x1800000, 0x1000000 },
			{ "mpr-22273.ic3", 0x2800000, 0x1000000 },
			{ "mpr-22274.ic4", 0x3800000, 0x1000000 },
			{ "mpr-22275.ic5", 0x4800000, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Jambo! Safari (Rev A)
	{
		"jambo.zip",
		0x08800000,
		0x280fab95,
		NULL,
		M2,
		{
			{ "epr-22826a.ic22", 0x0000000, 0x400000 },
			{ "mpr-22818.ic1",  0x0800000, 0x800000 },
			{ "mpr-22819.ic2",  0x1000000, 0x800000 },
			{ "mpr-22820.ic3",  0x1800000, 0x800000 },
			{ "mpr-22821.ic4",  0x2000000, 0x800000 },
			{ "mpr-22822.ic5",  0x2800000, 0x800000 },
			{ "mpr-22823.ic6",  0x3000000, 0x800000 },
			{ "mpr-22824.ic7",  0x3800000, 0x800000 },
			{ "mpr-22825.ic8",  0x4000000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Melty Blood Actress Again (Japan)
	{
		"mbaao.zip",
		0x18000000,
		0x5506,
		"naomi.zip",	// Needs BIOS version h
		M4,
		{
			{ "ic8.bin",      0x00000000, 0x4000000 },
			{ "ic9.bin",      0x04000000, 0x4000000 },
			{ "ic10.bin",     0x08000000, 0x4000000 },
			{ "ic11.bin",     0x0c000000, 0x4000000 },
			{ "ic12.bin",     0x10000000, 0x4000000 },
			{ "ic13.bin",     0x14000000, 0x4000000 },
			{ "317-5133-jpn.ic3", 0, 0x800, M4Key },	// pic_readout
			{ NULL, 0, 0 },
		}
	},
	// Melty Blood Actress Again Version A (Japan, Rev A)
	{
		"mbaa.zip",
		0x18000000,
		0x5586,
		"naomi.zip",	// Needs BIOS version h
		M4,
		{
			{ "ic8.bin",      0x00000000, 0x4000000 },
			{ "epr-24455.ic7",0x00000000, 0x0400000 }, // EPR mode, overwrite FPR data
			{ "ic9.bin",      0x04000000, 0x4000000 },
			{ "ic10.bin",     0x08000000, 0x4000000 },
			{ "ic11.bin",     0x0c000000, 0x4000000 },
			{ "ic12.bin",     0x10000000, 0x4000000 },
			{ "ic13.bin",     0x14000000, 0x4000000 },
			{ "317-5133-jpn.ic3", 0, 0x800, M4Key },	// pic_readout
			{ NULL, 0, 0 },
		}
	},
	// Marvel Vs. Capcom 2 New Age of Heroes (Export, Korea, Rev A)
	{
		"mvsc2.zip",
		0x08800000,
		0xc18b6e7c,
		NULL,
		M1,
		{
			{ "epr-23085a.ic11", 0x0000000, 0x0400000 },
			{ "mpr-23048.ic17s", 0x0800000, 0x0800000 },
			{ "mpr-23049.ic18",  0x1000000, 0x0800000 },
			{ "mpr-23050.ic19s", 0x1800000, 0x0800000 },
			{ "mpr-23051.ic20",  0x2000000, 0x0800000 },
			{ "mpr-23052.ic21s", 0x2800000, 0x0800000 },
			{ "mpr-23053.ic22",  0x3000000, 0x0800000 },
			{ "mpr-23054.ic23s", 0x3800000, 0x0800000 },
			{ "mpr-23055.ic24",  0x4000000, 0x0800000 },
			{ "mpr-23056.ic25s", 0x4800000, 0x0800000 },
			{ "mpr-23057.ic26",  0x5000000, 0x0800000 },
			{ "mpr-23058.ic27s", 0x5800000, 0x0800000 },
			{ "mpr-23059.ic28",  0x6000000, 0x0800000 },
			{ "mpr-23060.ic29",  0x6800000, 0x0800000 },
			{ "mpr-23061.ic30s", 0x7000000, 0x0800000 },
			{ "mpr-23083.ic31",  0x7800000, 0x0400000 },
			// 32 bit area starts here
			{ "mpr-23083.ic31",  0x8000000, 0x0400000, InterleavedWord },
			{ "mpr-23084.ic32s", 0x8000002, 0x0400000, InterleavedWord },

			{ "copy",			0x400000,  0x400000, Copy, 0x1200000 },

			//ROM_REGION(0x200, "some_eeprom", 0)	// TODO
			//{  "25lc040.ic13s", 0x000000, 0x200, CRC(dc449637) SHA1(6cab09f61be1498271a36bff6a114a4eeeb00e1a) )
			{ NULL, 0, 0 },
		}
	},
	// Marvel Vs. Capcom 2 New Age of Heroes (USA, Rev A)
	{
		"mvsc2u.zip",
		0x07800000,
		0x0002c840,
		NULL,
		M2,
		{
			{ "epr-23062a.ic22", 0x0000000, 0x0400000 },
			{ "mpr-23048.ic1",   0x0800000, 0x0800000 },
			{ "mpr-23049.ic2",   0x1000000, 0x0800000 },
			{ "mpr-23050.ic3",   0x1800000, 0x0800000 },
			{ "mpr-23051.ic4",   0x2000000, 0x0800000 },
			{ "mpr-23052.ic5",   0x2800000, 0x0800000 },
			{ "mpr-23053.ic6",   0x3000000, 0x0800000 },
			{ "mpr-23054.ic7",   0x3800000, 0x0800000 },
			{ "mpr-23055.ic8",   0x4000000, 0x0800000 },
			{ "mpr-23056.ic9",   0x4800000, 0x0800000 },
			{ "mpr-23057.ic10",  0x5000000, 0x0800000 },
			{ "mpr-23058.ic11",  0x5800000, 0x0800000 },
			{ "mpr-23059.ic12s", 0x6000000, 0x0800000 },
			{ "mpr-23060.ic13s", 0x6800000, 0x0800000 },
			{ "mpr-23061.ic14s", 0x7000000, 0x0800000 },

			//ROM_REGION(0x84, "some_eeprom", 0)
			//ROM_LOAD("sflash.ic37", 0x000000, 0x000084, CRC(37a66f3c) SHA1(df6cd2cdc2813caa5da4dc9f171998485bcbdc44))
			{ NULL, 0, 0 },
		}
	},
	// Power Stone
	{
		"pstone.zip",
		0x04800000,
		0x000e69c1,
		NULL,
		M2,
		{
			{ "epr-21597.ic22",0x0000000, 0x0200000 },
			{ "epr-21597.ic22",0x0200000, 0x0200000 },	// Reload
			{ "mpr-21589.ic1", 0x0800000, 0x0800000 },
			{ "mpr-21590.ic2", 0x1000000, 0x0800000 },
			{ "mpr-21591.ic3", 0x1800000, 0x0800000 },
			{ "mpr-21592.ic4", 0x2000000, 0x0800000 },
			{ "mpr-21593.ic5", 0x2800000, 0x0800000 },
			{ "mpr-21594.ic6", 0x3000000, 0x0800000 },
			{ "mpr-21595.ic7", 0x3800000, 0x0800000 },
			{ "mpr-21596.ic8", 0x4000000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Power Stone 2
	{
		"pstone2.zip",
		0x05000000,
		0x000b8dc0,
		NULL,
		M2,
		{
			{ "epr-23127.ic22", 0x0000000, 0x0400000 },
			{ "mpr-23118.ic1", 0x0800000, 0x0800000 },
			{ "mpr-23119.ic2", 0x1000000, 0x0800000 },
			{ "mpr-23120.ic3", 0x1800000, 0x0800000 },
			{ "mpr-23121.ic4", 0x2000000, 0x0800000 },
			{ "mpr-23122.ic5", 0x2800000, 0x0800000 },
			{ "mpr-23123.ic6", 0x3000000, 0x0800000 },
			{ "mpr-23124.ic7", 0x3800000, 0x0800000 },
			{ "mpr-23125.ic8", 0x4000000, 0x0800000 },
			{ "mpr-23126.ic9", 0x4800000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Puyo Puyo Da! (Japan)
	{
		"puyoda.zip",
		0x0a800000,
		0x000acd40,
		NULL,
		M2,
		{
			{ "epr-22206.ic22", 0x0000000, 0x400000 },
			{ "mpr-22186.ic1",   0x0800000, 0x800000 },
			{ "mpr-22187.ic2",   0x1000000, 0x800000 },
			{ "mpr-22188.ic3",   0x1800000, 0x800000 },
			{ "mpr-22189.ic4",   0x2000000, 0x800000 },
			{ "mpr-22190.ic5",   0x2800000, 0x800000 },
			{ "mpr-22191.ic6",   0x3000000, 0x800000 },
			{ "mpr-22192.ic7",   0x3800000, 0x800000 },
			{ "mpr-22193.ic8",   0x4000000, 0x800000 },
			{ "mpr-22194.ic9",   0x4800000, 0x800000 },
			{ "mpr-22195.ic10",  0x5000000, 0x800000 },
			{ "mpr-22196.ic11",  0x5800000, 0x800000 },
			{ "mpr-22197.ic12s", 0x6000000, 0x800000 },
			{ "mpr-22198.ic13s", 0x6800000, 0x800000 },
			{ "mpr-22199.ic14s", 0x7000000, 0x800000 },
			{ "mpr-22200.ic15s", 0x7800000, 0x800000 },
			{ "mpr-22201.ic16s", 0x8000000, 0x800000 },
			{ "mpr-22202.ic17s", 0x8800000, 0x800000 },
			{ "mpr-22203.ic18s", 0x9000000, 0x800000 },
			{ "mpr-22204.ic19s", 0x9800000, 0x800000 },
			{ "mpr-22205.ic20s", 0xa000000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Ring Out 4x4 (Rev A)
	{
		"ringout.zip",
		0x05800000,
		0x280b1e40,
		NULL,
		M2,
		{
			{ "epr-21779a.ic22", 0x0000000, 0x400000 },
			{ "mpr-21761.ic1",  0x0800000, 0x800000 },
			{ "mpr-21762.ic2",  0x1000000, 0x800000 },
			{ "mpr-21763.ic3",  0x1800000, 0x800000 },
			{ "mpr-21764.ic4",  0x2000000, 0x800000 },
			{ "mpr-21765.ic5",  0x2800000, 0x800000 },
			{ "mpr-21766.ic6",  0x3000000, 0x800000 },
			{ "mpr-21767.ic7",  0x3800000, 0x800000 },
			{ "mpr-21768.ic8",  0x4000000, 0x800000 },
			{ "mpr-21769.ic9",  0x4800000, 0x800000 },
			{ "mpr-21770.ic10", 0x5000000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Samba De Amigo (Rev B)
	{
		"samba.zip",
		0x08800000,
		0x280a8b5d,
		NULL,
		M2,
		{
			{ "epr-22966b.ic22",0x0000000, 0x0400000 }, // was also found in cartridge with Rev.A case label
			{ "mpr-22950.ic1",  0x0800000, 0x0800000 },
			{ "mpr-22951.ic2",  0x1000000, 0x0800000 },
			{ "mpr-22952.ic3",  0x1800000, 0x0800000 },
			{ "mpr-22953.ic4",  0x2000000, 0x0800000 },
			{ "mpr-22954.ic5",  0x2800000, 0x0800000 },
			{ "mpr-22955.ic6",  0x3000000, 0x0800000 },
			{ "mpr-22956.ic7",  0x3800000, 0x0800000 },
			{ "mpr-22957.ic8",  0x4000000, 0x0800000 },
			{ "mpr-22958.ic9",  0x4800000, 0x0800000 },
			{ "mpr-22959.ic10", 0x5000000, 0x0800000 },
			{ "mpr-22960.ic11", 0x5800000, 0x0800000 },
			{ "mpr-22961.ic12s",0x6000000, 0x0800000 },
			{ "mpr-22962.ic13s",0x6800000, 0x0800000 },
			{ "mpr-22963.ic14s",0x7000000, 0x0800000 },
			{ "mpr-22964.ic15s",0x7800000, 0x0800000 },
			{ "mpr-22965.ic16s",0x8000000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	//Samba de Amigo ver. 2000 (Japan)
	{
		"samba2k.zip",
		0x0b800000,
		0x281702cf,
		NULL,
		M2,
		{
			{ "epr-23600.ic22", 0x00000000, 0x0400000 },
			{ "mpr-23589.ic1",  0x00800000, 0x1000000 },
			{ "mpr-23590.ic2",  0x01800000, 0x1000000 },
			{ "mpr-23591.ic3",  0x02800000, 0x1000000 },
			{ "mpr-23592.ic4",  0x03800000, 0x1000000 },
			{ "mpr-23593.ic5",  0x04800000, 0x1000000 },
			{ "mpr-23594.ic6",  0x05800000, 0x1000000 },
			{ "mpr-23595.ic7",  0x06800000, 0x1000000 },
			{ "mpr-23596.ic8",  0x07800000, 0x1000000 },
			{ "mpr-23597.ic9",  0x08800000, 0x1000000 },
			{ "mpr-23598.ic10", 0x09800000, 0x1000000 },
			{ "mpr-23599.ic11", 0x0a800000, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Sega Tetris
	{
		"sgtetris.zip",
		0x03800000,
		0x2808ae51,
		NULL,
		M2,
		{
			{  "epr-22909.ic22", 0x000000, 0x200000 },
			{  "epr-22909.ic22", 0x200000, 0x200000 },	// Reload
			{  "mpr-22910.ic1", 0x0800000, 0x800000 },
			{  "mpr-22911.ic2", 0x1000000, 0x800000 },
			{  "mpr-22912.ic3", 0x1800000, 0x800000 },
			{  "mpr-22913.ic4", 0x2000000, 0x800000 },
			{  "mpr-22914.ic5", 0x2800000, 0x800000 },
			{  "mpr-22915.ic6", 0x3000000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Slashout
	{
		"slasho.zip",
		0x09000000,
		0x281a66ca,
		NULL,
		M2,
		{
			{ "epr-23341.ic22", 0x0000000, 0x0400000 },
			{ "mpr-23324.ic1",  0x0800000, 0x0800000 },
			{ "mpr-23325.ic2",  0x1000000, 0x0800000 },
			{ "mpr-23326.ic3",  0x1800000, 0x0800000 },
			{ "mpr-23327.ic4",  0x2000000, 0x0800000 },
			{ "mpr-23328.ic5",  0x2800000, 0x0800000 },
			{ "mpr-23329.ic6",  0x3000000, 0x0800000 },
			{ "mpr-23330.ic7",  0x3800000, 0x0800000 },
			{ "mpr-23331.ic8",  0x4000000, 0x0800000 },
			{ "mpr-23332.ic9",  0x4800000, 0x0800000 },
			{ "mpr-23333.ic10", 0x5000000, 0x0800000 },
			{ "mpr-23334.ic11", 0x5800000, 0x0800000 },
			{ "mpr-23335.ic12s",0x6000000, 0x0800000 },
			{ "mpr-23336.ic13s",0x6800000, 0x0800000 },
			{ "mpr-23337.ic14s",0x7000000, 0x0800000 },
			{ "mpr-23338.ic15s",0x7800000, 0x0800000 },
			{ "mpr-23339.ic16s",0x8000000, 0x0800000 },
			{ "mpr-23340.ic17s",0x8800000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Sega Marine Fishing
	{
		"smarinef.zip",
		0x06800000,
		0xffffffff,
		NULL,
		M2,
		{
			{ "epr-22221.ic22",  0x0000000, 0x0400000 },
			{ "mpr-22208.ic1",   0x0800000, 0x0800000 },
			{ "mpr-22209.ic2",   0x1000000, 0x0800000 },
			/* IC3 empty */
			/* IC4 empty */
			{ "mpr-22212.ic5",   0x2800000, 0x0800000 },
			{ "mpr-22213.ic6",   0x3000000, 0x0800000 },
			{ "mpr-22214.ic7",   0x3800000, 0x0800000 },
			{ "mpr-22215.ic8",   0x4000000, 0x0800000 },
			{ "mpr-22216.ic9",   0x4800000, 0x0800000 },
			{ "mpr-22217.ic10",  0x5000000, 0x0800000 },
			{ "mpr-22218.ic11",  0x5800000, 0x0800000 },
			{ "mpr-22219.ic12s", 0x6000000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Sega Strike Fighter (Rev A)
	{
		"sstrkfgt.zip",
		0x0b000000,
		0x28132303,
		NULL,
		M2,
		{
			{ "epr-23323a.ic22", 0x0000000, 0x400000 },
			{ "mpr-23302.ic1",   0x0800000, 0x800000 },
			{ "mpr-23303.ic2",   0x1000000, 0x800000 },
			{ "mpr-23304.ic3",   0x1800000, 0x800000 },
			{ "mpr-23305.ic4",   0x2000000, 0x800000 },
			{ "mpr-23306.ic5",   0x2800000, 0x800000 },
			{ "mpr-23307.ic6",   0x3000000, 0x800000 },
			{ "mpr-23308.ic7",   0x3800000, 0x800000 },
			{ "mpr-23309.ic8",   0x4000000, 0x800000 },
			{ "mpr-23310.ic9",   0x4800000, 0x800000 },
			{ "mpr-23311.ic10",  0x5000000, 0x800000 },
			{ "mpr-23312.ic11",  0x5800000, 0x800000 },
			{ "mpr-23313.ic12s", 0x6000000, 0x800000 },
			{ "mpr-23314.ic13s", 0x6800000, 0x800000 },
			{ "mpr-23315.ic14s", 0x7000000, 0x800000 },
			{ "mpr-23316.ic15s", 0x7800000, 0x800000 },
			{ "mpr-23317.ic16s", 0x8000000, 0x800000 },
			{ "mpr-23318.ic17s", 0x8800000, 0x800000 },
			{ "mpr-23319.ic18s", 0x9000000, 0x800000 },
			{ "mpr-23320.ic19s", 0x9800000, 0x800000 },
			{ "mpr-23321.ic20s", 0xa000000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Touch de Uno! 2 (Japan)
	{
		"tduno2.zip",
		0x4000000,
		0x2f6f0f8d,
		NULL,
		M1,
		{
			{ "epr-23071.ic11",  0x0000000, 0x0200000 },
			{ "epr-23071.ic11",  0x0200000, 0x0200000 },	// Reload
			{ "mpr-23063.ic17s", 0x1000000, 0x0800000, InterleavedWord },
			{ "mpr-23064.ic18",  0x1000002, 0x0800000, InterleavedWord },
			{ "mpr-23065.ic19s", 0x2000000, 0x0800000, InterleavedWord },
			{ "mpr-23066.ic20",  0x2000002, 0x0800000, InterleavedWord },
			{ "mpr-23067.ic21s", 0x3000000, 0x0800000, InterleavedWord },
			{ "mpr-23068.ic22",  0x3000002, 0x0800000, InterleavedWord },

			{ "copy", 0x400000, 0xc00000, Copy, 0x1000000 },
			//ROM_REGION(0x200, "some_eeprom", 0)
			//ROM_LOAD( "25lc040.ic13s", 0, 0x200, CRC(6291605c) SHA1(44f757da4814b08108d1a4f431c9a39c38acecb2) )
			{ NULL, 0, 0 },
		}
	},
	// The Typing of the Dead (Rev A)
	{
		"totd.zip",
		0x0b000000,
		0xffffffff,
		NULL,
		M2,
		{
			{ "epr-23021a.ic22", 0x0000000, 0x0400000 },

			{ "mpr-23001.ic1",   0x0800000, 0x0800000 },
			{ "mpr-23002.ic2",   0x1000000, 0x0800000 },
			{ "mpr-23003.ic3",   0x1800000, 0x0800000 },
			{ "mpr-23004.ic4",   0x2000000, 0x0800000 },
			{ "mpr-23005.ic5",   0x2800000, 0x0800000 },
			// IC6 not populated
			{ "mpr-23007.ic7",   0x3800000, 0x0800000 },
			{ "mpr-23008.ic8",   0x4000000, 0x0800000 },
			{ "mpr-23009.ic9",   0x4800000, 0x0800000 },
			{ "mpr-23010.ic10",  0x5000000, 0x0800000 },
			{ "mpr-23011.ic11",  0x5800000, 0x0800000 },
			{ "mpr-23012.ic12s", 0x6000000, 0x0800000 },
			// IC13S not populated
			{ "mpr-23014.ic14s", 0x7000000, 0x0800000 },
			{ "mpr-23015.ic15s", 0x7800000, 0x0800000 },
			{ "mpr-23016.ic16s", 0x8000000, 0x0800000 },
			{ "mpr-23017.ic17s", 0x8800000, 0x0800000 },
			{ "mpr-23018.ic18s", 0x9000000, 0x0800000 },
			{ "mpr-23019.ic19s", 0x9800000, 0x0800000 },
			{ "mpr-23020.ic20s", 0xa000000, 0x0800000 },
			// IC21s not populated
			{ NULL, 0, 0 },
		}
	},
	// Toy Fighter
	{
		"toyfight.zip",
		0x08000000,
		0x2802ca85,
		NULL,
		M2,
		{
			{ "epr-22035.ic22",0x0000000, 0x0400000 },
			{ "mpr-22025.ic1", 0x0800000, 0x0800000 },
			{ "mpr-22026.ic2", 0x1000000, 0x0800000 },
			{ "mpr-22027.ic3", 0x1800000, 0x0800000 },
			{ "mpr-22028.ic4", 0x2000000, 0x0800000 },
			{ "mpr-22029.ic5", 0x2800000, 0x0800000 },
			{ "mpr-22030.ic6", 0x3000000, 0x0800000 },
			{ "mpr-22031.ic7", 0x3800000, 0x0800000 },
			{ "mpr-22032.ic8", 0x4000000, 0x0800000 },
			{ "mpr-22033.ic9", 0x4800000, 0x0800000 },
			{ "mpr-22034.ic10",0x5000000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Virtua NBA (USA)
	{
		"virnba.zip",
		0x0b000000,
		0xffffffff,
		NULL,
		M2,
		{
			{ "epr-23073.ic22",  0x0000000, 0x0400000 },
			{ "mpr-22928.ic1",   0x0800000, 0x0800000 },
			{ "mpr-22929.ic2",   0x1000000, 0x0800000 },
			{ "mpr-22930.ic3",   0x1800000, 0x0800000 },
			{ "mpr-22931.ic4",   0x2000000, 0x0800000 },
			{ "mpr-22932.ic5",   0x2800000, 0x0800000 },
			{ "mpr-22933.ic6",   0x3000000, 0x0800000 },
			{ "mpr-22934.ic7",   0x3800000, 0x0800000 },
			{ "mpr-22935.ic8",   0x4000000, 0x0800000 },
			{ "mpr-22936.ic9",   0x4800000, 0x0800000 },
			{ "mpr-22937.ic10",  0x5000000, 0x0800000 },
			{ "mpr-22938.ic11",  0x5800000, 0x0800000 },
			{ "mpr-22939.ic12s", 0x6000000, 0x0800000 },
			{ "mpr-22940.ic13s", 0x6800000, 0x0800000 },
			{ "mpr-22941.ic14s", 0x7000000, 0x0800000 },
			{ "mpr-22942.ic15s", 0x7800000, 0x0800000 },
			{ "mpr-22943.ic16s", 0x8000000, 0x0800000 },
			{ "mpr-22944.ic17s", 0x8800000, 0x0800000 },
			{ "mpr-22945.ic18s", 0x9000000, 0x0800000 },
			{ "mpr-22946.ic19s", 0x9800000, 0x0800000 },
			{ "mpr-22947.ic20s", 0xa000000, 0x0800000 },
			{ "mpr-22948.ic21s", 0xa800000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	// Virtua Tennis 2 / Power Smash 2 (Rev A)
	{
		"vtenis2c.zip",
		0x0a000000,
		0x2d2d4743,
		NULL,
		M1,
		{
			{ "epr-22327a.ic11", 0x000000, 0x400000 },
			{ "mpr-22307.ic17s",  0x1000000, 0x800000, InterleavedWord },
			{ "mpr-22308.ic18",   0x1000002, 0x800000, InterleavedWord },
			{ "mpr-22309.ic19s",  0x2000000, 0x800000, InterleavedWord },
			{ "mpr-22310.ic20",   0x2000002, 0x800000, InterleavedWord },
			{ "mpr-22311.ic21s",  0x3000000, 0x800000, InterleavedWord },
			{ "mpr-22312.ic22",   0x3000002, 0x800000, InterleavedWord },
			{ "mpr-22313.ic23s",  0x4000000, 0x800000, InterleavedWord },
			{ "mpr-22314.ic24",   0x4000002, 0x800000, InterleavedWord },
			{ "mpr-22315.ic25s",  0x5000000, 0x800000, InterleavedWord },
			{ "mpr-22316.ic26",   0x5000002, 0x800000, InterleavedWord },
			{ "mpr-22317.ic27s",  0x6000000, 0x800000, InterleavedWord },
			{ "mpr-22318.ic28",   0x6000002, 0x800000, InterleavedWord },
			{ "mpr-22319.ic29",   0x7000000, 0x800000, InterleavedWord },
			{ "mpr-22320.ic30s",  0x7000002, 0x800000, InterleavedWord },
			{ "mpr-22321.ic31",   0x8000000, 0x800000, InterleavedWord },
			{ "mpr-22322.ic32s",  0x8000002, 0x800000, InterleavedWord },
			{ "mpr-22323.ic33",   0x9000000, 0x800000, InterleavedWord },
			{ "mpr-22324.ic34s",  0x9000002, 0x800000, InterleavedWord },

			{ "copy",			0x400000,  0xc00000, Copy, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Virtual On Oratorio Tangram M.S.B.S. ver5.66 2000 Edition
	{
		"vonot.zip",
		0x07000000,
		0x28010715,
		NULL,
		M2,
		{
			{ "epr-23198.ic22",  0x0000000, 0x400000 },
			{ "mpr-23182.ic1",   0x0800000, 0x800000 },
			{ "mpr-23183.ic2",   0x1000000, 0x800000 },
			{ "mpr-23184.ic3",   0x1800000, 0x800000 },
			{ "mpr-23185.ic4",   0x2000000, 0x800000 },
			{ "mpr-23186.ic5",   0x2800000, 0x800000 },
			{ "mpr-23187.ic6",   0x3000000, 0x800000 },
			{ "mpr-23188.ic7",   0x3800000, 0x800000 },
			{ "mpr-23189.ic8",   0x4000000, 0x800000 },
			{ "mpr-23190.ic9",   0x4800000, 0x800000 },
			{ "mpr-23191.ic10",  0x5000000, 0x800000 },
			{ "mpr-23192.ic11",  0x5800000, 0x800000 },
			{ "mpr-23193.ic12s", 0x6000000, 0x800000 },
			{ "mpr-23194.ic13s", 0x6800000, 0x800000 },
			{ NULL, 0, 0 },
		}
	},
	// Wave Runner GP
	{
		"wrungp.zip",
		0x06800000,
		0xffffffff,
		NULL,
		M2,
		{
			{ "epr-24059.ic22", 0x0000000, 0x400000 },
			{ "mpr-23719.ic1",  0x0800000, 0x1000000 },
			{ "mpr-23720.ic2",  0x1800000, 0x1000000 },
			{ "mpr-23721.ic3",  0x2800000, 0x1000000 },
			{ "mpr-23722.ic4",  0x3800000, 0x1000000 },
			{ "mpr-23723.ic5",  0x4800000, 0x1000000 },
			{ "mpr-23724.ic6",  0x5800000, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Zero Gunner 2
	{
		"zerogu2.zip",
		0x05800000,
		0x0007c010,
		NULL,
		M2,
		{
			{ "epr-23689.ic22", 0x0000000, 0x0400000 },
			{ "mpr-23684.ic1",  0x0800000, 0x1000000 },
			{ "mpr-23685.ic2",  0x1800000, 0x1000000 },
			{ "mpr-23686.ic3",  0x2800000, 0x1000000 },
			{ "mpr-23687.ic4",  0x3800000, 0x1000000 },
			{ "mpr-23688.ic5",  0x4800000, 0x1000000 },
			{ NULL, 0, 0 },
		}
	},
	// Zombie Revenge
	{
		"zombrvno.zip",
		0x0a000000,
		0x28012b41,
		NULL,
		M2,
		{
			{ "epr-21707.ic22",0x0000000, 0x0200000 },
			{ "epr-21707.ic22",0x0200000, 0x0200000 },	// Reload
			{ "mpr-21708.ic1",  0x0800000, 0x0800000 },
			{ "mpr-21709.ic2",  0x1000000, 0x0800000 },
			{ "mpr-21710.ic3",  0x1800000, 0x0800000 },
			{ "mpr-21711.ic4",  0x2000000, 0x0800000 },
			{ "mpr-21712.ic5",  0x2800000, 0x0800000 },
			{ "mpr-21713.ic6",  0x3000000, 0x0800000 },
			{ "mpr-21714.ic7",  0x3800000, 0x0800000 },
			{ "mpr-21715.ic8",  0x4000000, 0x0800000 },
			{ "mpr-21716.ic9",  0x4800000, 0x0800000 },
			{ "mpr-21717.ic10", 0x5000000, 0x0800000 },
			{ "mpr-21718.ic11", 0x5800000, 0x0800000 },
			{ "mpr-21719.ic12s",0x6000000, 0x0800000 },
			{ "mpr-21720.ic13s",0x6800000, 0x0800000 },
			{ "mpr-21721.ic14s",0x7000000, 0x0800000 },
			{ "mpr-21722.ic15s",0x7800000, 0x0800000 },
			{ "mpr-21723.ic16s",0x8000000, 0x0800000 },
			{ "mpr-21724.ic17s",0x8800000, 0x0800000 },
			{ "mpr-21725.ic18s",0x9000000, 0x0800000 },
			{ "mpr-21726.ic19s",0x9800000, 0x0800000 },
			{ NULL, 0, 0 },
		}
	},
	{
		NULL
	}
};

