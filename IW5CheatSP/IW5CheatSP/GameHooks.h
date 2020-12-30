#pragma once
#include "IW5CheatSP.h"


struct VariableValue;
struct DBFile;
struct UiContext;
struct menuDef_t;
struct usercmd_s;
struct scr_entref_t;

extern void(*VM_Notify_Stub)(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);
void VM_Notify_Hook(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);

extern bool(*Menu_Paint_Stub)(UiContext *dc, menuDef_t *menu);
bool Menu_Paint_Hook(UiContext *dc, menuDef_t *menu);

extern void(*SV_ClientThink_Stub)(int clientNum, usercmd_s *cmd);
void SV_ClientThink_Hook(int clientNum, usercmd_s *cmd);
