#include "macro.sqf"
/*
	@version: 2.0
	@file_name: fn_saveGear.sqf
	@file_author: TAW_Tonic
	@file_edit: 9/24/2013
	@file_description: Save to profileNamespace in old VAS format
*/
private["_title","_slot","_primary,_launcher","_handgun","_magazines","_uniform","_vest","_backpack","_items","_primitems","_secitems","_handgunitems","_uitems","_vitems","_bitems","_curWep"];
_title = ctrlText VAS_save_text;
_slot = lbCurSel VAS_save_list;
if(_slot isEqualTo -1) exitWith {hint localize"STR_VAS_Prompt_slotSelFail"};

//Old format / code
_primary = primaryWeapon player;
_launcher = secondaryWeapon player;
_handgun = handGunWeapon player;
_magazines = [];
_uniform = uniform player;
_vest = vest player;
_backpack = backpack player;
_items = assignedItems player;
_primitems = primaryWeaponItems player;
_secitems = secondaryWeaponItems player;
_handgunitems = handGunItems player;
_uitems = [];
_vitems = [];
_bitems = [];
if!(_uniform isEqualTo "") then {{_uitems pushBack _x;} foreach (uniformItems player);};
if!(_vest isEqualTo "") then {{_vitems pushBack _x;} foreach (vestItems player);};
if!(_backpack isEqualTo "") then {{_bitems pushBack _x;} foreach (backPackItems player);};

if!(goggles player isEqualTo "") then { _items pushBack goggles player; };
if!(headgear player isEqualTo "") then { _items pushBack headgear player; };
if(count (primaryWeaponMagazine player) > 0) then
{
	{
		_magazines pushBack _x;
	} foreach (primaryWeaponMagazine player);
};

if(count (secondaryWeaponMagazine player) > 0) then
{
	{
		_magazines pushBack _x;
	} foreach (secondaryWeaponMagazine player);
};

if(count (handgunMagazine player) > 0) then
{
	{
		_magazines pushBack _x;
	} foreach (handgunMagazine player);
};

//Hard code for Laser Desigantor batteries
_curWep = currentWeapon player;
if("Laserdesignator" in assignedItems player) then
{
	player selectWeapon "Laserdesignator";
	if!(currentMagazine player isEqualTo "") then {_magazines pushBack currentMagazine player;};
};

player selectWeapon _curWep;

if(vas_disableLoadSave) then
{
	SVAR_MNS [format["vas_gear_new_%1",_slot],[_title,_primary,_launcher,_handgun,_magazines,_uniform,_vest,_backpack,_items,_primitems,_secitems,_handgunitems,_uitems,_vitems,_bitems]];
}
	else
{
	SVAR_PNS [format["vas_gear_new_%1",_slot],[_title,_primary,_launcher,_handgun,_magazines,_uniform,_vest,_backpack,_items,_primitems,_secitems,_handgunitems,_uitems,_vitems,_bitems]];
	saveProfileNamespace;
};

[0,true] spawn VAS_fnc_SaveLoad;