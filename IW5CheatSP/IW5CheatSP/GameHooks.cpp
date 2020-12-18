#include "GameHooks.h"


void(*VM_Notify_Stub)(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);
void VM_Notify_Hook(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top) {
	int entNum = Scr_GetSelf(notifyListOwnerId);
	if (entNum <= 2) {
		printf("ent %i notified\n", entNum);
	}
	VM_Notify_Stub(notifyListOwnerId, stringValue, top);
}

