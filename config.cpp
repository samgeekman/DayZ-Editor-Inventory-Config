////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 10.13
//https://mikero.bytex.digital/Downloads
//'now' is Wed Aug 19 15:53:11 2026 : 'file' last modified on Wed Aug 19 15:24:21 2026
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class DayzEditorInventoryConfig
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"Editor_Scripts"};
	};
};
class CfgMods
{
	class DayzEditorInventoryConfig
	{
		name = "Dayz Editor Inventory Config";
		dir = "DayzEditorInventoryConfig";
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				files[] = {"DayzEditorInventoryConfig/Scripts/4_World"};
			};
		};
	};
};
