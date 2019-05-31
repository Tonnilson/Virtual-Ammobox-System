/*
	Limited Box, this is a example of the many ways that you can limit certain items to a ammobox.
	In this example only MX Rifles, their mags and attachments are available, this type of configuration is similiar to
	using the variables VAS_x (weapons,items,magazines,backpacks,goggles) but instead we are storing an array of allowed items
	on the ammobox its self.
	
	What should be noted, whatever variable you do not set will resume the default configuration you had set through the config.sqf
*/
if(!isServer) exitWith {}; //This was executed through the init field and only the server should fill this box.

//Set only MX Rifles.
_this setVariable["bis_weapons",["arifle_MX_F","arifle_MXC_f","arifle_MX_SW_F","arifle_MXM_F"],true]; //Set variable bis_weapons with only MX rifles and broadcast to all clients.

//Set only 6.5mm magazines compatible with the MX rifles to be shown.
_this setVariable["bis_magazines",["100Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag","30Rnd_65x39_caseless_mag_Tracer","100Rnd_65x39_caseless_mag_Tracer"],true];

//Show no items (Do not set variable if you want to show them all).
_this setVariable["bis_items",[],true];

//Get rid of backpacks.
_this setVariable["bis_backpacks",[],true];

//Get rid of goggles.
//_this setVariable["bis_goggles",[],true];