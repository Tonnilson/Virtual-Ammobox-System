/*
	File: fn_VASP.sqf
	Author: Bryan "Tonic" Boardwine
	
	Description:
	Separate 'buildConfig' file, specifically designed for 'VASP'.
*/
params [
	["_cfg","",[""]],
	"_arr",
	["_weapons",[]],
	["_items",[]],
	["_magazines",[]],
	["_backpacks",[]],
	["_glasses",[]],
	"_details",
	"_type",
	"_itemInfo",
	"_base"
];
if(_cfg isEqualTo "") exitWith {};

diag_log format["VASP: %1",_cfg];

switch(_cfg) do
{
	case "CfgWeapons":
	{
		_arr = uiNamespace getVariable["VASP_weapons",[]];
		_arr = _arr + (uiNamespace getVariable["VASP_items",[]]);
		if(count _arr isEqualTo 0) exitWith {hint "The VASP weapons config is broke?"; uiNamespace setVariable["VASP_weapons",nil]; ["CfgWeapons"] spawn VAS_fnc_buildConfig;}; //Safety check
		
		{
			_details = [_x,"CfgWeapons"] call VAS_fnc_fetchCfgDetails;
			_type = _details select 4;
			_itemInfo = _details select 5;
			_base = configName(inheritsFrom (configFile >> "CfgWeapons" >> _x));
			
			switch(true) do
			{
				case (_type in [1,2,4,5,4096]):
				{
					if(!(_base in VAS_r_weapons) && !(_x in VAS_r_weapons)) then {
						if(_itemInfo isEqualTo 616 && _type isEqualTo 4096) then {
							_items pushBack _x;
						} else {
							_weapons pushBack _x;
						};
					};
				};
				
				case (_type == 131072):
				{
					if(!(_base in VAS_r_items) && !(_x in VAS_r_items)) then {
						_items pushBack _x;
					};
				};
			};
		} foreach _arr;
		
		VAS_pre_weapons = _weapons;
		VAS_pre_items = _items;
	};
	
	case "CfgMagazines":
	{
		_arr = uiNamespace getVariable["VASP_magazines",[]];
		if(count _arr isEqualTo 0) exitWith {hint "The VASP magazines config is broke?"; uiNamespace setVariable["VASP_magazines",nil]; ["CfgMagazines"] spawn VAS_fnc_buildConfig;}; //Safety check
		
		{
			if(!(_x in VAS_R_magazines)) then {
				_magazines pushBack _x;
			};
		} foreach _arr;
		
		VAS_pre_magazines = _magazines;
	};
	
	case "CfgVehicles":
	{
		_arr = uiNamespace getVariable["VASP_backpacks",[]];
		if(count _arr isEqualTo 0) exitWith {hint "The VASP backpacks config is broke?"; uiNamespace setVariable["VASP_backpacks",nil]; ["CfgVehicles"] spawn VAS_fnc_buildConfig;}; //Safety check
		
		{
			_base = inheritsFrom (configFile >> _cfg >> _x);
			if(!(_base in VAS_r_backpacks) && !(_x in VAS_r_backpacks)) then {
				_backpacks pushBack _x;
			};
		} foreach _arr;
		
		VAS_pre_backpacks = _backpacks;
	};
	
	case "CfgGlasses":
	{
		_arr = uiNamespace getVariable["VASP_glasses",[]];
		if(count _arr isEqualTo 0) exitWith {hint "The VASP glasses config is broke?"; uiNamespace setVariable["VASP_glasses",nil]; ["CfgGlasses"] spawn VAS_fnc_buildConfig;}; //Safety check
		
		{
			if(!(_x in VAS_R_glasses)) then {
				_glasses pushBack _x;
			};
		} foreach _arr;
		
		VAS_pre_glasses = _glasses;
	};
};