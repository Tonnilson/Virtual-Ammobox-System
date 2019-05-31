#include "macro.sqf"
/*
	@version: 1.1
	@file_name: fn_SaveLoad.sqf
	@file_author: TAW_Tonic
	@file_edit: 5/27/2013
	@file_description: Pulls up Save / Load Dialog
*/
params [
	["_type",0,[0]],
	["_show",false,[false]],
	"_control",
	"_slot"
];

disableSerialization;

switch (_type) do
{
	case 0: {_control = VAS_getControl(VAS_save_Display,VAS_save_list);};
	case 1: {_control = VAS_getControl(VAS_load_Display,VAS_load_list);};
};

lbClear _control; //Flush the control/list

if(vas_disableLoadSave) then
{
	for "_i" from 0 to vas_customslots do
	{
		if(!isNil {GVAR_MNS format["vas_gear_new_%1",_i]}) then
		{
			_control lbAdd format["%1",(GVAR_MNS format["vas_gear_new_%1",_i]) select 0];
		}
			else
		{
			_control lbAdd format["%1 %2",localize "STR_VAS_Main_CL", _i+1];
		};
	};
}
	else
{
	for "_i" from 0 to vas_customslots do
	{
		if(!isNil {GVAR_PNS format["vas_gear_new_%1",_i]}) then
		{
			_control lbAdd format["%1",(GVAR_PNS format["vas_gear_new_%1",_i]) select 0];
		}
			else
		{
			_control lbAdd format["%1 %2",localize "STR_VAS_Main_CL", _i+1];
		};
	};
};
if(_show) then
{
	[_type] spawn VAS_fnc_loadoutInfo;
};