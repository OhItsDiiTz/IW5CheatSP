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

void ScrCmd_SetModel(int entNum, const char * model) {
	Scr_AddString(model);
	scrVmPub->outparamcount = 1;
	scr_entref_t m = { entNum, 0 };
	GameCall<void>(0x005D0600)(m);
	Scr_ClearOutParams();
}

void ScrCmd_PlayerLinkTo(int entNum, gentity_s * linktoent) {
	Scr_AddEntity(linktoent);
	scrVmPub->outparamcount = 1;
	scr_entref_t m = { entNum, 0 };
	GameCall<void>(0x005D1710)(m);
	Scr_ClearOutParams();
}

void ScrCmd_PlayerLinkTo(int entNum, gentity_s * linktoent, const char * tag) {
	Scr_AddConstString(SL_GetString(tag, 0));
	Scr_AddEntity(linktoent);
	scrVmPub->outparamcount = 2;
	scr_entref_t m = { entNum, 0 };
	GameCall<void>(0x005D1710)(m);
	Scr_ClearOutParams();
}

void ScriptEntCmd_MoveTo(gentity_s * ent, const float * point, float time) {
	Scr_AddFloat(time);
	Scr_AddVector(point);
	scrVmPub->outparamcount = 2;
	scr_entref_t m = { ent->s.number, 0 };
	GameCall<void>(0x00439500)(m);
	Scr_ClearOutParams();
}

void ScriptEntCmd_MoveTo(gentity_s * ent, const float * point, float time, float acceleration_time) {
	Scr_AddFloat(acceleration_time);
	Scr_AddFloat(time);
	Scr_AddVector(point);
	scrVmPub->outparamcount = 3;
	scr_entref_t m = { ent->s.number, 0 };
	GameCall<void>(0x00439500)(m);
	Scr_ClearOutParams();
}

void ScriptEntCmd_MoveTo(gentity_s * ent, const float * point, float time, float acceleration_time, float deceleration_time) {
	Scr_AddFloat(deceleration_time);
	Scr_AddFloat(acceleration_time);
	Scr_AddFloat(time);
	Scr_AddVector(point);
	scrVmPub->outparamcount = 4;
	scr_entref_t m = { ent->s.number, 0 };
	GameCall<void>(0x00439500)(m);
	Scr_ClearOutParams();
}

const float * Scr_AnglesToForward(const float * angles) {
	//Scr_AddVector(angles);
	//scrVmPub->outparamcount = 1;
	//GameCall<void>(0x005D4370)();
	//Scr_ClearOutParams();
	//return scrVmPub->top->u.vectorValue;
	float return_pos[3];
	AngleVectors(angles, return_pos, 0, 0);
	const float * ret = return_pos;
	return ret;
}

const float * Scr_AnglesToRight(const float * angles) {
	//Scr_AddVector(angles);
	//scrVmPub->outparamcount = 1;
	//GameCall<void>(0x005D4340)();
	//Scr_ClearOutParams();
	//return scrVmPub->top->u.vectorValue;
	float return_pos[3];
	AngleVectors(angles, 0, return_pos, 0);
	const float * ret = return_pos;
	return ret;
}

const float * PlayerCmd_getAngles(int clientNum) {
	scr_entref_t m = { clientNum, 0 };
	GameCall<void>(0x005B8ED0)(m);
	Scr_ClearOutParams();
	return scrVmPub->top->u.vectorValue;
}
