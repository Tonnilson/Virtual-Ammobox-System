/*
	File: fn_initBuilder.sqf
	Author: Bryan "Tonic" Boardwine
	
	Description:
	Starts the VASP process.
*/
[] spawn
{
	private["_therad","_nsW","_nsI","_nsM","_nsB","_nsG"];
	hint "Starting the VASP process...";
	_thread = ["CfgWeapons"] spawn VAS_fnc_configBuilder;
	waitUntil{scriptDone _thread};
	_thread = ["CfgMagazines"] spawn VAS_fnc_configBuilder;
	waitUntil{scriptDone _thread};
	_thread = ["CfgVehicles"] spawn VAS_fnc_configBuilder;
	waitUntil{scriptDone _thread};
	_thread = ["CfgGlasses"] spawn VAS_fnc_configBuilder;
	waitUntil{scriptDone _thread};
	
	_nsW = uiNamespace getVariable "VASP_weapons"; _nsW = if(isNil "_nsW") then {"Failed"} else {"Good"};
	_nsI = uiNamespace getVariable "VASP_items"; _nsI = if(isNil "_nsI") then {"Failed"} else {"Good"};
	_nsM = uiNamespace getVariable "VASP_magazines"; _nsM = if(isNil "_nsM") then {"Failed"} else {"Good"};
	_nsB = uiNamespace getVariable "VASP_backpacks"; _nsB = if(isNil "_nsB") then {"Failed"} else {"Good"};
	_nsG = uiNamespace getVariable "VASP_glasses"; _nsG = if(isNil "_nsG") then {"Failed"} else {"Good"};
	hint format["Preloading Process Completed Verifying..\n\nWeapons: %1\nItems: %2\nMagazines: %3\nBackpacks: %4\nGlasses: %5\n\nIf everything is marked as 'Good' then you are ready.",_nsW,_nsI,_nsM,_nsB,_nsG];
};