#include "GameHooks.h"

gentity_s* noclip_ent;
 
void(*VM_Notify_Stub)(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);
void VM_Notify_Hook(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top) {
	int entNum = Scr_GetSelf(notifyListOwnerId);
	const char * notify = SL_ConvertToString(stringValue);
	gentity_s* ent = GetEntity(entNum);
	gclient_s * client = ent->client;

	if (entNum <= 2) {
		printf("ent %i notified %s\n", entNum, notify);

		if (!strcmp(notify, "weapon_fired") || !strcmp(notify, "grenade_fire")) {
			Add_Ammo(ent, client->pers.cmd.weapon, false, 999, 1);
			Add_Ammo(ent, client->ps.weapCommon.offHand, false, 999, 1);

			//com_plasticcase_friendly - 0x8030200 (solid flag)
			//for (int i = 0; i < 2048;i++) {
			//	if (g_entities[i].classname == *(unsigned __int16*)(0x015C6124)) {
			//		printf("content: 0x%X\n", g_entities[i].r.contents);
			//	}
			//}
			
			if (noclip_ent == NULL) {
				noclip_ent = GScr_Spawn("script_origin", ent->r.currentOrigin);
				ScrCmd_PlayerLinkTo(ent->s.number, noclip_ent);
			}
		}
		
		if (!strcmp(notify, "grenade_fire")) {
			//printf("grenade %X\n", GetEntity(Scr_GetSelf(top->u.intValue)));
		}
		
		if (!strcmp(notify, "missile_fire")) {
			//printf("missile %X\n", GetEntity(Scr_GetSelf(top->u.intValue)));

			if (G_EntLinkTo(ent, GetEntity(Scr_GetSelf(top->u.intValue)), 0)) {
				G_InitPlayerLinkAngles(ent);
			}
		}

		if (!strcmp(notify, "end_explode")) {

		}

	}
	VM_Notify_Stub(notifyListOwnerId, stringValue, top);
}

bool(*Menu_Paint_Stub)(UiContext *dc, menuDef_t *menu);
bool Menu_Paint_Hook(UiContext *dc, menuDef_t *menu) {
	unsigned int a1 = *(unsigned int*)( (&menu) + 0xA8);

	if (a1) {
		//printf("0x%X - %s\n", a1, (char*)(*(unsigned int*)(menu + 4)) );
	}

	bool ret = Menu_Paint_Stub(dc, menu);

	return ret;
}

void(*SV_ClientThink_Stub)(int clientNum, usercmd_s *cmd);
void SV_ClientThink_Hook(int clientNum, usercmd_s *cmd) {
	scrVmPub = (scrVmPub_t*)(0x01BF2580);
	g_entities = (gentity_s*)(0x01197AD8);
	gentity_s * ent = GetEntity(clientNum);

	if (noclip_ent != NULL) {
		const float * angles = ent->client->ps.viewangles;
		const float * forwardangles = Scr_AnglesToForward(angles);
		const float * rightangles = Scr_AnglesToRight(angles);
		float final_pos[3] = { ent->r.currentOrigin[0], ent->r.currentOrigin[1], ent->r.currentOrigin[2] };
		
		if (cmd->forwardmove == 0x7F) {
			final_pos[0] += (forwardangles[0] * ((cmd->buttons & BUTTON_SPRINT) ? 40 : 20));
			final_pos[1] += (forwardangles[1] * ((cmd->buttons & BUTTON_SPRINT) ? 40 : 20));
			final_pos[2] += (forwardangles[2] * ((cmd->buttons & BUTTON_SPRINT) ? 40 : 20));
			//ScriptEntCmd_MoveTo(noclip_ent, final_pos, 0.1);
			memcpy(noclip_ent->r.currentOrigin, final_pos, 12);
		}

		if ((cmd->forwardmove & 0xFF) == 0x81) {
			final_pos[0] -= (forwardangles[0] * ((cmd->buttons & BUTTON_SPRINT) ? 40 : 20));
			final_pos[1] -= (forwardangles[1] * ((cmd->buttons & BUTTON_SPRINT) ? 40 : 20));
			final_pos[2] -= (forwardangles[2] * ((cmd->buttons & BUTTON_SPRINT) ? 40 : 20));
			//ScriptEntCmd_MoveTo(noclip_ent, final_pos, 0.1);
			memcpy(noclip_ent->r.currentOrigin, final_pos, 12);
		}

		if (cmd->rightmove == 0x7F) {
			final_pos[0] += (rightangles[0] * ((cmd->buttons & BUTTON_SPRINT) ? 30 : 10));
			final_pos[1] += (rightangles[1] * ((cmd->buttons & BUTTON_SPRINT) ? 30 : 10));
			final_pos[2] += (rightangles[2] * ((cmd->buttons & BUTTON_SPRINT) ? 30 : 10));
			//ScriptEntCmd_MoveTo(noclip_ent, final_pos, 0.1);
			memcpy(noclip_ent->r.currentOrigin, final_pos, 12);
		}

		if ((cmd->rightmove & 0xFF) == 0x81) {
			final_pos[0] -= (rightangles[0] * ((cmd->buttons & BUTTON_SPRINT) ? 30 : 10));
			final_pos[1] -= (rightangles[1] * ((cmd->buttons & BUTTON_SPRINT) ? 30 : 10));
			final_pos[2] -= (rightangles[2] * ((cmd->buttons & BUTTON_SPRINT) ? 30 : 10));
			//ScriptEntCmd_MoveTo(noclip_ent, final_pos, 0.1);
			memcpy(noclip_ent->r.currentOrigin, final_pos, 12);
		}

	}
	
	//if (cmd->rightmove) {
	//	printf("rightmove: 0x%X\n", (cmd->rightmove & 0xFF));
	//}
	
	if (cmd->buttons) {
		//printf("cmd->buttons & 0x%X\n", cmd->buttons);
	}

	SV_ClientThink_Stub(clientNum, cmd);
}
