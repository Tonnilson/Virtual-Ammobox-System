#include "macro.sqf"
/*
	@version: 1.8
	@file_name: fn_filterMenu.sqf
	@file_author: TAW_Tonic
	@file_edit: 8/27/2013
	@file_description: When a filter is called it will give us the details and we shall sort her out!
*/
waitUntil {!isNull (findDisplay VAS_Main_Display)};
params [
	["_req",0,[0]],
	["_return",false,[true]],
	"_filter","_control","_details","_data","_myfilter"
];
disableSerialization;
_filter = uiNamespace getVariable "VAS_UI_FILTER";
uiNamespace setVariable["VAS_UI_FILTER_VAR",_req];

switch(_filter) do
{
	case "guns":
	{
		switch(_req) do
		{
			case 0: {_data = [_filter,1] call VAS_fnc_fetchCfg; _myfilter = 1;};
			case 1: {_data = [_filter,1] call VAS_fnc_fetchCfg; _myfilter = 1;};
			case 2: {_data = [_filter,5] call VAS_fnc_fetchCfg; _myfilter = 5;};
			case 3: {_data = [_filter,4] call VAS_fnc_fetchCfg; _myfilter = 4;};
			case 4: {_data = [_filter,2] call VAS_fnc_fetchCfg; _myfilter = 2;};
		};
	};
	
	case "items":
	{
		switch(_req) do
		{
			case 0: {_data = [_filter,801] call VAS_fnc_fetchCfg; _myfilter = 801;};
			case 1: {_data = [_filter,701] call VAS_fnc_fetchCfg; _myfilter = 701;};
			case 2: {_data = [_filter,605] call VAS_fnc_fetchCfg; _myfilter = 605;};
			case 3: 
			{
				_data = [_filter,[201,101,301,302]] call VAS_fnc_fetchCfg;
				_myfilter = [201,101,301,302];
			};
			case 4: {_data = [_filter,[0,616,621,619,620,401]] call VAS_fnc_fetchCfg; _myfilter = [0,616,621,619,620,401];};
		};
	};
};

if(_return) then
{
	_info = [([] call VAS_fnc_fetchPlayerGear),_myfilter] call VAS_fnc_filter;
	_info;
}
	else
{
	_control = VAS_getControl(VAS_Main_Display,VAS_virt_list);
	lbClear VAS_getControl(VAS_Main_Display,VAS_virt_list);
	lbClear VAS_getControl(VAS_Main_Display,VAS_unit_list);

	{
		_details = [_x] call VAS_fnc_fetchCfgDetails;
		if(count _details > 0) then
		{
			_control lbAdd format["%1", (_details select 1)]; //Displayname on list
			_control lbSetData [(lbSize _control)-1,(_details select 0)]; //Data for index is classname
			_control lbSetPicture [(lbSize _control)-1,(_details select 2)];
			lbSort _control;
		};
	} foreach _data;

	_control = VAS_getControl(VAS_Main_Display,VAS_unit_list);
	_info = [([] call VAS_fnc_fetchPlayerGear),_myfilter] call VAS_fnc_filter;
			
	{
		_details = [_x] call VAS_fnc_fetchCfgDetails;
		if(count _details > 0) then
		{
			_control lbAdd format["%1", (_details select 1)]; //Displayname on list
			_control lbSetData [(lbSize _control)-1,(_details select 0)]; //Data for index is classname
			_control lbSetPicture [(lbSize _control)-1,(_details select 2)];
			lbSort _control;
		};
	} foreach _info;
};