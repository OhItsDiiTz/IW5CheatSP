#pragma once
#include "IW5CheatSP.h"

void GScr_notifyOnPlayerCommand(int clientNum, const char *commandString, const char *notifyString);

gentity_s * GScr_Spawn(const char * classname, const float * origin);
gentity_s * GScr_Spawn(const char * classname, const float * origin, int spawnFlags);

void ScrCmd_SetModel(int entNum, const char * model);

void ScrCmd_PlayerLinkTo(int entNum, gentity_s * linktoent);
void ScrCmd_PlayerLinkTo(int entNum, gentity_s * linktoent, const char * tag);

void ScriptEntCmd_MoveTo(gentity_s * ent, const float * point, float time);
void ScriptEntCmd_MoveTo(gentity_s * ent, const float * point, float time, float acceleration_time);
void ScriptEntCmd_MoveTo(gentity_s * ent, const float * point, float time, float acceleration_time, float deceleration_time);

const float * Scr_AnglesToForward(const float * angles);
const float * Scr_AnglesToRight(const float * angles);

const float * PlayerCmd_getAngles(int clientNum);

