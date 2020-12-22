#include "BuiltinFunctions.h"



void GScr_notifyOnPlayerCommand(int clientNum, const char *commandString, const char *notifyString) {
	Scr_AddString(notifyString);
	Scr_AddString(commandString);
	scr_entref_t m = { clientNum, 0 };
	scrVmPub->outparamcount = 2;
	GameCall<void>(0x005BC9A0)(m);
	Scr_ClearOutParams();
}

gentity_s * GScr_Spawn(const char * classname, const float * origin) {
	Scr_AddVector(origin);
	Scr_AddConstString(SL_GetString(classname, 0));
	scrVmPub->outparamcount = 2;
	GameCall<void>(0x005D0680)();
	return GetEntity(Scr_GetSelf(scrVmPub->top->u.entityOffset));
}

gentity_s * GScr_Spawn(const char * classname, const float * origin, int spawnFlags) {
	Scr_AddInt(spawnFlags);
	Scr_AddVector(origin);
	Scr_AddConstString(SL_GetString(classname, 0));
	scrVmPub->outparamcount = 3;
	GameCall<void>(0x005D0680)();
	return GetEntity(Scr_GetSelf(scrVmPub->top->u.entityOffset));
}


