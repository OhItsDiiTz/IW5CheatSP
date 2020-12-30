#pragma once
#include "IW5CheatSP.h"

template <typename T> T(*GameCall(unsigned int address))(...);

struct game_hudelem_s;
struct gentity_s;
struct scr_entref_t;

void Scr_AddString(const char *value);
void Scr_AddConstString(unsigned int value);
void Scr_AddVector(const float *value);
void Scr_AddInt(int value);
void Scr_AddEntity(gentity_s *ent);
void Scr_AddFloat(float value);

unsigned int SL_GetString(const char *str, unsigned int user);

void Scr_ClearOutParams();

void AngleVectors(const float *angles, float *forward, float *right, float *up);

unsigned int Scr_GetSelf(unsigned int threadId);
const char * SL_ConvertToString(unsigned int stringValue);
gentity_s* GetEntity(int entNum);
unsigned int Add_Ammo(gentity_s* ent, int weapon, bool isAlternate, int count, int fillClip);
void G_SetModel(unsigned int ent, const char *modelName);
int G_EntLinkTo(gentity_s* ent, gentity_s* parent, unsigned int tagName);
void G_InitPlayerLinkAngles(gentity_s* ent);

game_hudelem_s * HudElem_Alloc(int clientNum);

void SV_GameSendServerCommand(int clientNum, const char *text);

