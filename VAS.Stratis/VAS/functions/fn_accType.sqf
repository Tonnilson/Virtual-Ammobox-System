/*
	File: fn_accType.sqf
	Author: Bryan "Tonic" Boardwine
	
	Description:
	Checks what type of an attachment is passed and what it is compatible with.
	Should now be compatible with the new compatibleItems class structure... This was not a fun task but thankfully
	Robalo gave me some code that showed me the way. If it isn't 100% compatible then IDFK. The foreach in a foreach drove me nuts and
	not the best way to do things, I really don't know what I was thinking but doing PHP code for two weeks and playing GTA V tends to make you
	forget things.... Wow what a ramble... blah blah blah.
	
	Returns:
	0: Unknown Error
	1: Primary
	2: Secondary
	3: Handgun
*/
if(!params [
	["_item","",[""]],
	["_type",0,[0]],
	"_tmp",
	"_ret",
	"_weaponArray"
]) exitWith {0};
_ret = 0;

_weaponArray = [primaryWeapon player, secondaryWeapon player, handgunWeapon player];
{
	if(!(_ret isEqualTo 0)) exitWith {};
	if(!(_x isEqualTo "")) then
	{
		_weapon = _x;
		_cfgInfo = [_weapon,"CfgWeapons"] call VAS_fnc_fetchCfgDetails;
		_legacyItems = ((_cfgInfo select 10) + (_cfgInfo select 11) + (_cfgInfo select 12) + (_cfgInfo select 16));
		_newItems = _cfgInfo select 14;
		
		//Check Legacy Items first
		if(count _legacyItems > 0) then
		{
			for "_i" from 0 to (count _legacyItems)-1 do
			{
				_legacyItems set[_i,toLower(_legacyItems select _i)];
			};
			
			if((toLower _item) in _legacyItems) exitWith {_ret = switch(_weapon) do {case (primaryWeapon player): {1};case (secondaryWeapon player) : {2};case (handgunWeapon player): {3};default {0};};};
		};
		
		//Check new compatibleItems class structure
		if(count _newItems > 0) then
		{
			//This gets weird with foreach in foreach :\
			{
				if(_ret != 0) exitWith {};
				_cfg = getNumber(configFile >> "CfgWeapons" >> _weapon >> "WeaponSlotsInfo" >> _x >> "compatibleItems" >> _item);
				if(isNil "_cfg") then {_cfg = 0;};
				if(_cfg == 1) exitWith
				{
					_ret = switch(_weapon) do {case (primaryWeapon player): {1};case (secondaryWeapon player) : {2};case (handgunWeapon player): {3};default {0};};
				};
			} foreach _newItems;
			if(_ret != 0) exitWith {}; //Make sure we exit the loop
		};
	};
} foreach _weaponArray;

_ret;