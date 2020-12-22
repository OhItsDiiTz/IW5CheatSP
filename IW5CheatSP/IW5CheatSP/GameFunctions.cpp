#include "GameFunctions.h"

template <typename T> T(*GameCall(unsigned int address))(...) {
	T(*func)(...) = (T(*)(...))address;
	return func;
}

void Scr_AddString(const char *value) {
	GameCall<void>(0x004A5600)(value);
}

void Scr_AddConstString(unsigned int value) {
	GameCall<void>(0x0040D610)(value);
}

void Scr_AddVector(const float *value) {
	GameCall<void>(0x004AF9A0)(value);
}

void Scr_AddInt(int value) {
	GameCall<void>(0x0042DE20)(value);
}

unsigned int SL_GetString(const char *str, unsigned int user) {
	return GameCall<unsigned int>(0x004860A0)(str, user);
}

void Scr_ClearOutParams() {
	GameCall<void>(0x004E4700)();
}

unsigned int Scr_GetSelf(unsigned int threadId) {
	return GameCall<unsigned int>(0x004D2FD0)(threadId);
}

const char * SL_ConvertToString(unsigned int stringValue) {
	return GameCall<const char *>(0x00414290)(stringValue);
}

gentity_s* GetEntity(int entNum) {
	return (gentity_s*)(0x01197AD8 + (0x270 * entNum));
}

unsigned int Add_Ammo(gentity_s* ent, int weapon, bool isAlternate, int count, int fillClip) {
	return GameCall<unsigned int>(0x00513E70)(ent, weapon, isAlternate, count, fillClip);
}

void G_SetModel(unsigned int ent, const char *modelName) {
	GameCall<void>(0x0047EE60)(ent, modelName);
}

int G_EntLinkTo(gentity_s* ent, gentity_s* parent, unsigned int tagName) {
	return GameCall<int>(0x00542E40)(ent, parent, tagName);
}

void G_InitPlayerLinkAngles(gentity_s* ent) {
	GameCall<void>(0x0054C0D0)(ent);
}

game_hudelem_s * HudElem_Alloc(int clientNum) {
	return GameCall<game_hudelem_s*>(0x00460C30)(clientNum);
}

void SV_GameSendServerCommand(int clientNum, const char *text) {
	GameCall<void>(0x00402130)(clientNum, text);
}
