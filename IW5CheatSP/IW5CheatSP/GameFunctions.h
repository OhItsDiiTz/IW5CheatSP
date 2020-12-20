#pragma once
#include "IW5CheatSP.h"

template <typename T> T(*GameCall(unsigned int address))(...);

struct game_hudelem_s;

unsigned int Scr_GetSelf(unsigned int threadId);
const char * SL_ConvertToString(unsigned int stringValue);
unsigned int GetEntity(int entNum);
unsigned int Add_Ammo(unsigned int ent, int weapon, bool isAlternate, int count, int fillClip);
void G_SetModel(unsigned int ent, const char *modelName);
int G_EntLinkTo(unsigned int ent, unsigned int parent, unsigned int tagName);
void G_InitPlayerLinkAngles(unsigned int ent);

game_hudelem_s * HudElem_Alloc(int clientNum);





