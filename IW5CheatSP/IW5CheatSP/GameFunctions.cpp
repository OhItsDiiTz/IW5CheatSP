#include "GameFunctions.h"

template <typename T> T(*GameCall(unsigned int address))(...) {
	T(*func)(...) = (T(*)(...))address;
	return func;
}

unsigned int Scr_GetSelf(unsigned int threadId) {
	return GameCall<unsigned int>(0x004D2FD0)(threadId);
}

const char * SL_ConvertToString(unsigned int stringValue) {
	return GameCall<const char *>(0x00414290)(stringValue);
}

unsigned int GetEntity(int entNum) {
	return (0x01197AD8 + (0x270 * entNum));
}

unsigned int Add_Ammo(unsigned int ent, int weapon, bool isAlternate, int count, int fillClip) {
	return GameCall<unsigned int>(0x00513E70)(ent, weapon, isAlternate, count, fillClip);
}

void G_SetModel(unsigned int ent, const char *modelName) {
	GameCall<void>(0x0047EE60)(ent, modelName);
}

int G_EntLinkTo(unsigned int ent, unsigned int parent, unsigned int tagName) {
	return GameCall<int>(0x00542E40)(ent, parent, tagName);
}

void G_InitPlayerLinkAngles(unsigned int ent) {
	GameCall<void>(0x0054C0D0)(ent);
}

game_hudelem_s * HudElem_Alloc(int clientNum) {
	return GameCall<game_hudelem_s*>(0x00460C30)(clientNum);
}

