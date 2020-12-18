#pragma once
#include "IW5CheatSP.h"


struct VariableValue;

extern void(*VM_Notify_Stub)(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);
void VM_Notify_Hook(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);


