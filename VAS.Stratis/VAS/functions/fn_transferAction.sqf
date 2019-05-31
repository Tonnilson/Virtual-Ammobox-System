#include "macro.sqf"
/*
	File: fn_transferAction.sqf
	Author: Bryan "Tonic" Boardwine
	
	Description:
	Sends the transfer request to the selected user.
*/
private["_control","_targetUser"];
disableSerialization;
_control = VAS_getControl(VAS_transfer_MainMenu,VAS_transfer_UnitsList);
if(lbCurSel _control isEqualTo -1) exitWith {};
_targetUser = _control lbData (lbCurSel _control);
if(_targetUser isEqualTo "") exitWith {hint localize "STR_VAS_Transfer_BadUnit"};
{if(str(_x) isEqualTo _targetUser) exitWith {_targetUser = _x;}} foreach playableUnits; //Fetch the users actual object.
if(isNull _targetUser) exitWith {hint localize "STR_VAS_Transfer_BadUnit"};

[name player,VAS_Transfer_Loadout] remoteExec ["VAS_fnc_transferNetwork",_targetUser];
//[[name player,VAS_Transfer_Loadout],"VAS_fnc_transferNetwork",_targetUser,false] spawn BIS_fnc_MP;
closeDialog 0;