/*
	File: fn_configBuilder.sqf
	Author: Bryan "Tonic" Boardwine
	
	Description:
	Builds the VAS configs and saves them in the uiNamespace.
*/
private["_cfg","_type"];
_cfg = [_this,0,"",[""]] call BIS_fnc_param;
if(_cfg == "") exitWith {};

switch(_cfg) do
{
	case "CfgWeapons":
	{
		_temp = [];
		_weapons = [];
		_items = [];
		_master = configFile >> _cfg;
		for "_i" from 0 to (count _master)-1 do
		{
			_class = _master select _i;
			if(isClass _class) then {
				_class = configName _class;
				_details = [_class,_cfg] call VAS_fnc_fetchCfgDetails;
				if(count _details > 0) then {
					_displayName = _details select 1;
					_picture = _details select 2;
					_scope = _details select 3;
					_type = _details select 4;
					_itemInfo = _details select 5;
					
					_str = [_class,4] call VAS_fnc_KRON_StrLeft;
					if(_scope >= 2 && _str != "ACRE") then {
						switch (true) do
						{
							case (_type in [1,2,4,5,4096]):
							{
								if(_picture != "" && _displayName != "") then {
									if(_itemInfo == 616 && _type == 4096) then {
										_items set[count _items,_class];
									} else {
										if(!(_displayName in _temp)) then {
											_temp set[count _temp,_displayName];
											_weapons set[count _weapons,_class];
										};
									};
								};
							};
							
							case (_type == 131072):
							{
								if(_picture != "") then {
									_items set[count _items,_class];
								};
							};
						};
					};
				};
			};
		};
		
		//Set the namespace variables
		uiNamespace setVariable["VASP_weapons",_weapons];
		uiNamespace setVariable["VASP_items",_items];
	};
	
	case "CfgMagazines":
	{
		private["_magazines"];
		_temp = [];
		_magazines = [];
		_master = configFile >> _cfg;
		
		for "_i" from 0 to (count _master)-1 do
		{
			_class = _master select _i;
			if(isClass _class) then {
				_class = configName _class;
				_details = [_class,_cfg] call VAS_fnc_fetchCfgDetails;
				if(count _details > 0) then {
					_displayName = _details select 1;
					_picture = _details select 2;
					_scope = _details select 3;
					if(_scope >= 1 && _picture != "" && !(_displayName in _temp)) then {
						_str = [_class,4] call VAS_fnc_KRON_StrLeft;
						if(_str != "ACRE") then {
							_temp set[count _temp,_displayName];
							_magazines set[count _magazines,_class];
						};
					};
				};
			};
		};
		
		//Set the namespace variables
		uiNamespace setVariable["VASP_magazines",_magazines];
	};
	
	case "CfgVehicles":
	{
		_ret = [];
		_master = configFile >> _cfg;
		private["_base"];
		for "_i" from 0 to (count _master)-1 do
		{
			_class = _master select _i;
			if(isClass _class) then
			{
				_class = configName _class;
				_details = [_class,_cfg] call VAS_fnc_fetchCfgDetails;
				_displayName = _details select 1;
				_picture = _details select 2;
				_scope = _details select 3;
				_type = _details select 4;
				_base = inheritsFrom (configFile >> _cfg >> _class);
				if(_scope >= 2 && _type == "Backpacks" && _picture != "") then
				{
					_str = [_class,4] call VAS_fnc_KRON_StrLeft;
					if(_str != "ACRE") then
					{
						_ret set[count _ret,_class];
					};
				};
			};
		};
		
		uiNamespace setVariable["VASP_backpacks",_ret];
	};
	
	case "CfgGlasses":
	{
		_temp = [];
		_ret = [];
		_master = configFile >> _cfg;
		for "_i" from 0 to (count _master)-1 do
		{
			_class = _master select _i;
			if(isClass _class) then
			{
				_class = configName _class;
				_details = [_class,_cfg] call VAS_fnc_fetchCfgDetails;
				_displayName = _details select 1;
				_picture = _details select 2;
				
				if(_picture != "" && _displayName != "None" && !(_displayName in _temp)) then
				{
					_str = [_class,4] call VAS_fnc_KRON_StrLeft;
					if(_str != "ACRE") then
					{
						_temp set[count _temp,_displayName];
						_ret set[count _ret,_class];
					};
				};
			};
		};
		
		uiNamespace setVariable["VASP_glasses",_ret];
	};
};