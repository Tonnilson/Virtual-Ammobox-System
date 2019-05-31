#include "macro.sqf"
/*
	@version: 1.7
	@file_name: fn_removeGear.sqf
	@file_author: TAW_Tonic
	@file_edit: 8/2/2013
	@file_description: Removes an item selected.
*/
params [
	["_all",false,[false]],
	"_fil",
	"_data"
];

_fil = uiNamespace getVariable "VAS_UI_FILTER";
disableSerialization;
_data = VAS_getSelData(VAS_unit_list);

if(_all) then {
	switch (_fil) do
	{
		case "mags": {player removeMagazines _data};
		case "items": {player removeItems _data};
	};
} else {
	[_data,false,false,false,false] call VAS_fnc_handleItem;
};

[] call VAS_fnc_updateLoad;
[] spawn VAS_fnc_playerDisplay;