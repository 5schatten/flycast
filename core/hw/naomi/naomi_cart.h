#include "types.h"

bool naomi_cart_Read(u32 offset, u32 size, void* dst);
bool naomi_cart_Write(u32 offset, u32 size, u32 data);
void* naomi_cart_GetPtr(u32 offset, u32 size);
bool naomi_cart_SelectFile(char *s, size_t len);

extern char naomi_game_id[];
