#include "GameHooks.h"

unsigned int explosive_ent;
 
void(*VM_Notify_Stub)(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);
void VM_Notify_Hook(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top) {
	int entNum = Scr_GetSelf(notifyListOwnerId);
	const char * notify = SL_ConvertToString(stringValue);
	unsigned int client = *(unsigned int*)(GetEntity(entNum) + 0x10C);
	unsigned int ent = GetEntity(entNum);

	if (entNum <= 2) {
		printf("ent %i notified %s\n", entNum, notify);

		if (!strcmp(notify, "weapon_fired") || !strcmp(notify, "grenade_fire")) {
			Add_Ammo(GetEntity(entNum), *(int*)(client + 0xAD6C), false, 999, 1);
			Add_Ammo(GetEntity(entNum), *(int*)(client + 0x324), false, 999, 1);
		}

		if (!strcmp(notify, "grenade_fire")) {
			printf("grenade %X\n", GetEntity(Scr_GetSelf(top->u.intValue)));
			explosive_ent = GetEntity(Scr_GetSelf(top->u.intValue));
		}
		
		if (!strcmp(notify, "missile_fire")) {
			printf("missile %X\n", GetEntity(Scr_GetSelf(top->u.intValue)));

			if (G_EntLinkTo(ent, GetEntity(Scr_GetSelf(top->u.intValue)), 0)) {
				G_InitPlayerLinkAngles(ent);
			}
		}

		if (!strcmp(notify, "end_explode")) {
			if (explosive_ent == GetEntity(Scr_GetSelf(top->u.intValue))) {
				printf("woah death\n");
			}
		}

	}
	VM_Notify_Stub(notifyListOwnerId, stringValue, top);
}

