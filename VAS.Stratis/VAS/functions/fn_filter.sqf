/*
	@version: 1.9
	@file_name: fn_filter.sqf
	@file_author: TAW_Tonic
	@file_edit: 9/1/2013
	@file_description: Takes current array of items and filters it for what we need.
*/
params ["_items","_filter","_ret","_itemInfo","_type","_details"];
_ret = [];
{
	if!(_x isEqualTo "") then {
		_details = [_x] call VAS_fnc_fetchCfgDetails;
		if(count _details isEqualTo 0) exitWith {_ret};
		_type = _details select 4;
		_itemInfo = _details select 5;
		_AGMItem = _details select 15;
		
		switch (true) do {
			case ((_details select 6) isEqualTo "CfgMagazines"): {
				if(typeName _filter isEqualTo "STRING") then {
					if(_filter isEqualTo "mag") then {
						_ret pushBack _x;
					};
				};
			};
			
			case ((_details select 6) isEqualTo "CfgGlasses" && typeName _filter isEqualTo "STRING"): {
				if(_filter isEqualTo "glass") then {
					_ret pushBack _x;
				};
			};
			
			case (_type in [1,2,4,5,4096] && (!_AGMItem && _itemInfo in [0,-1])): {
				switch(typeName _filter) do {
					case "ARRAY": {
						if(_type in _filter) then {
							_ret pushBack _x;
						};
					};
					
					case "SCALAR": {
						if(_type isEqualTo _filter) then {
							_ret pushBack _x;
						};
					};
				};
			};
			
			case (_type in [4096,131072]) : {
				if(_type isEqualTo 4096 && !_AGMItem && _itemInfo isEqualTo 0) exitWith {};
				switch(typeName _filter) do {
					case "ARRAY": {
						if(_itemInfo in _filter) then {
							_ret pushBack _x;
						};
					};
					
					case "SCALAR": {
						switch (true) do {
							case (_itemInfo isEqualTo _filter) : {_ret pushBack _x;};
							case (_type isEqualTo _filter) : {_ret pushBack _x;};
						};
					};
					
					case "STRING": {
						if(_filter isEqualTo "items") then {
							_ret pushBack _x;
						};
					};
				};
			};
			
			case (typeName _type isEqualTo "STRING" && typeName _filter isEqualTo "STRING"): {
				if(_type isEqualTo "Backpacks" && _filter isEqualTo "packs") then {
					_ret pushBack _x;
				};
			};
		};
	};
} foreach _items;

_ret;