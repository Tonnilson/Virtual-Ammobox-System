/*
	@version: 1.3
	@file_name: fn_fetchPlayerGear.sqf
	@file_author: TAW_Tonic
	@file_edit: 7/9/2013
	@file_description: Retrieves players current gear and returns it.
*/
private["_ret","_curWep"];
_ret = [];

//Fetch Weapons
if!(primaryWeapon player isEqualTo "") then {_ret pushBack primaryWeapon player;};
if!(secondaryWeapon player isEqualTo "") then {_ret pushBack secondaryWeapon player;};
if!(handgunWeapon player isEqualTo "") then {_ret pushBack handgunWeapon player;};

//Fetch Current Magazines
if(count (primaryWeaponMagazine player) > 0) then
{
	{
		_ret pushBack _x;
	} foreach (primaryWeaponMagazine player);
};

if(count (secondaryWeaponMagazine player) > 0) then
{
	{
		_ret pushBack _x;
	} foreach (secondaryWeaponMagazine player);
};

if(count (handgunMagazine player) > 0) then
{
	{
		_ret pushBack _x;
	} foreach (handgunMagazine player);
};

//Hard code for Laser Desigantor batteries
_curWep = currentWeapon player;

if("Laserdesignator" in assignedItems player) then
{
	player selectWeapon "Laserdesignator";
	if!(currentMagazine player isEqualTo "") then {_ret pushBack (currentMagazine player);};
};

player selectWeapon _curWep;

//Fetch rest of misc information.
if!(uniform player isEqualTo "") then 
{
	_ret pushBack uniform player; //Get uniform
	{_ret pushBack _x;} foreach (uniformItems player); //Get uniform items
};	

if!(vest player isEqualTo "") then 
{
	_ret pushBack vest player; //Get vest
	{_ret pushBack _x;} foreach (vestItems player); //Get vest items
};

if!(backpack player isEqualTo "") then 
{
	_ret pushBack backpack player; //Get Backpack
	{_ret pushBack _x;} foreach (backpackItems player); //Get Backpack Items
};

if(count (assignedItems player) > 0) then 
{
	{
		_ret pushBack _x;
	} foreach (assignedItems player);
};

if!(headGear player isEqualTo "") then
{
	_ret pushBack headGear player;
};

if!(goggles player isEqualTo "") then
{
	_ret pushBack goggles player;
};

//Fetch Primary weapon attachments
if!(primaryWeapon player isEqualTo "") then
{
	{
		if!(((primaryWeaponItems player) select _x) isEqualTo "") then
		{
			_ret pushBack ((primaryWeaponItems player) select _x);
		};
	} foreach [0,1,2];
};

if!(handgunWeapon player isEqualTo "") then
{
	{
		if!(((handgunItems player) select _x) isEqualTo "") then
		{
			_ret pushBack ((handgunItems player) select _x);
		};
	} foreach [0,1,2];
};

//Fetch secondary weapon attachments (placeholder)

_ret; //Return!