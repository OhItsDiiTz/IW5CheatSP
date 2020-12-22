#pragma once
#include "IW5CheatSP.h"

void GScr_notifyOnPlayerCommand(int clientNum, const char *commandString, const char *notifyString);
gentity_s * GScr_Spawn(const char * classname, const float * origin);
gentity_s * GScr_Spawn(const char * classname, const float * origin, int spawnFlags);

