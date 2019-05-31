/* ** v2.91 **
	Author: Bryan "Tonic" Boardwine
	Website: www.iamtonic.co
*/
#include "common.hpp"

class VAS_Diag
{
	idd = 2500;
	name= "Virtual_Ammobox_Sys";
	movingEnable = 1;
	enableSimulation = true;
	onLoad = "";
	onUnload = "VAS_box_weapons = nil; VAS_box_magazines = nil; VAS_box_items = nil; VAS_box_backpacks = nil; VAS_box_goggles = nil;"; //When the dialog is gone set these back to nil.
	
	class ControlsBackground
	{
		class VAS_RscTitleBackground : VAS_RscText 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26;
			y = safeZoneY + safeZoneH * 0.18777778;
			w = safeZoneW * 0.48;
			h = safeZoneH * 0.02222223;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			
		};
		class MainBackground : VAS_RscText 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26;
			y = safeZoneY + safeZoneH * 0.21222223;
			w = safeZoneW * 0.48;
			h = safeZoneH * 0.403;
			colorBackground[] = {0,0,0,0.7};
			
		};
		class vasText : VAS_RscText 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.268125;
			y = safeZoneY + safeZoneH * 0.22666667;
			w = safeZoneW * 0.16375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_VirtGear;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			sizeEx = 0.04;
			
		};
		class vasgText : VAS_RscText 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.56625;
			y = safeZoneY + safeZoneH * 0.22666667;
			w = safeZoneW * 0.16375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_YCG;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			sizeEx = 0.04;
			
		};
		class VAS_ContainerBG : VAS_RscText 
		{
			idc = 2950;
			x = safeZoneX + safeZoneW * 0.741875;
			y = safeZoneY + safeZoneH * 0.21222223;
			w = safeZoneW * 0.036875;
			h = safeZoneH * 0.08111112;
			colorBackground[] = {0,0,0,0.7};
			
		};
		class VAS_VestBG : VAS_ContainerBG 
		{
			idc = 2951;
			y = safeZoneY + safeZoneH * 0.29444445;
			
		};
		class VAS_BackpackBG : VAS_ContainerBG 
		{
			idc = 2952;
			y = safeZoneY + safeZoneH * 0.37666667;
			
		};
		class VAS_UniformPicSlot : VAS_ActiveTextPicture 
		{
			idc = 2960;
			x = safeZoneX + safeZoneW * 0.741875;
			y = safeZoneY + safeZoneH * 0.21555556;
			w = safeZoneW * 0.036875;
			h = safeZoneH * 0.06555556;
			
		};
		class VAS_VestPicSlot : VAS_UniformPicSlot 
		{
			idc = 2961;
			y = safeZoneY + safeZoneH * 0.29555556;
			
		};
		class VAS_BackpackPicSlot : VAS_UniformPicSlot 
		{
			idc = 2962;
			y = safeZoneY + safeZoneH * 0.38;
			
		};
		class VAS_loadBarP : VAS_RscProgress 
		{
			idc = 2970;
			x = safeZoneX + safeZoneW * 0.743125;
			y = safeZoneY + safeZoneH * 0.28222223;
			w = safeZoneW * 0.035625;
			h = safeZoneH * 0.00777778;
			colorBar[] = {0.9,0.9,0.9,0.9};
			colorFrame[] = {1,1,1,1};
			texture = "";
			
		};
		class VAS_VestLoad : VAS_loadBarP 
		{
			idc = 2971;
			y = safeZoneY + safeZoneH * 0.36333334;
			
		};
		class VAS_BackpackLoad : VAS_loadBarP 
		{
			idc = 2972;
			y = safeZoneY + safeZoneH * 0.44666667;
			
		};
		
	};
	class Controls
	{
		class gundetailsbg : VAS_RscText 
		{
			idc = 2507;
			x = safeZoneX + safeZoneW * 0.084375;
			y = safeZoneY + safeZoneH * 0.21222223;
			w = safeZoneW * 0.17375;
			h = safeZoneH * 0.19333334;
			text = "";
			colorBackground[] = {0,0,0,0.7};
			
		};
		class AttachmentsBG : gundetailsbg 
		{
			idc = 2850;
			x = safeZoneX + safeZoneW * 0.084375;
			y = safeZoneY + safeZoneH * 0.43333334;
			w = safeZoneW * 0.17375;
			h = safeZoneH * 0.17666667;
		};
		class AttachmentsList : VAS_RscListBox 
		{
			idc = 2851;
			x = safeZoneX + safeZoneW * 0.08625;
			y = safeZoneY + safeZoneH * 0.43333334;
			w = safeZoneW * 0.169375;
			h = safeZoneH * 0.17666667;
			colorBackground[] = {0,0,0,0};
			sizeEx = 0.035;
			rowHeight = 0.06;
			onLBDblClick = "_this call VAS_fnc_quickAttachment";
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class gundetails : VAS_RscStructuredText 
		{
			idc = 2508;
			x = safeZoneX + safeZoneW * 0.084375;
			y = safeZoneY + safeZoneH * 0.21777778;
			w = safeZoneW * 0.165;
			h = safeZoneH * 0.03333334;
			text = "";
			style = 16;
			shadow = 1;
			colorBackground[] = {1,1,1,0};
			class Attributes
			{
				font = "PuristaMedium";
				//color = "#ffffff";
				//align = "left";
			};
		};
		class gundetailslist : VAS_RscListBox 
		{
			idc = 2509;
			x = safeZoneX + safeZoneW * 0.08625;
			y = safeZoneY + safeZoneH * 0.24333334;
			w = safeZoneW * 0.169375;
			h = safeZoneH * 0.16111112;
			colorBackground[] = {0,0,0,0};
			sizeEx = 0.030;
			rowHeight = 0.06;
			onLBDblClick = "_this spawn VAS_fnc_quickMag;";
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class vasGear : VAS_RscListBox 
		{
			idc = 2501;
			x = safeZoneX + safeZoneW * 0.268125;
			y = safeZoneY + safeZoneH * 0.24777778;
			w = safeZoneW * 0.16375;
			h = safeZoneH * 0.30888889;
			sizeEx = 0.032;
			rowHeight = 0.06;
			onLBDblClick = "_this spawn VAS_fnc_quickItem;";
			onLBSelChanged = "_this spawn VAS_fnc_details";
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class vasPGear : VAS_RscListBox 
		{
			idc = 2502;
			x = safeZoneX + safeZoneW * 0.56625;
			y = safeZoneY + safeZoneH * 0.24777778;
			w = safeZoneW * 0.16375;
			h = safeZoneH * 0.30888889;
			sizeEx = 0.032;
			rowHeight = 0.06;
			onLBDblClick = "_this spawn VAS_fnc_qRemoveItem;";
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class WeaponsBtn : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.466875;
			y = safeZoneY + safeZoneH * 0.24333334;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_Weapons;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			onButtonClick = "['guns',false] spawn VAS_fnc_mainDisplay";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class MagazinesBtn : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.466875;
			y = safeZoneY + safeZoneH * 0.27;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_Magazines;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			onButtonClick = "['mags',false] spawn VAS_fnc_mainDisplay";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class ItemsBtn : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.466875;
			y = safeZoneY + safeZoneH * 0.29777778;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_Items;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			onButtonClick = "['items',false] spawn VAS_fnc_mainDisplay";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class BackpacksBtn : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.466875;
			y = safeZoneY + safeZoneH * 0.32555556;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_Backpacks;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			onButtonClick = "['packs',false] spawn VAS_fnc_mainDisplay";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class GogglesBtn : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.466875;
			y = safeZoneY + safeZoneH * 0.35333334;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_Goggles;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			onButtonClick = "['glass',false] spawn VAS_fnc_mainDisplay";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class Filter1 : VAS_RscActiveText 
		{
			idc = 2580;
			text = "$STR_VAS_Main_Uniforms";
			action = "[0] spawn VAS_fnc_filterMenu";
			x = safeZoneX + safeZoneW * 0.47125;
			y = safeZoneY + safeZoneH * 0.38;
			w = safeZoneW * 0.11375;
			h = safeZoneH * 0.02222223;
			
		};
		class Filter2 : VAS_RscActiveText 
		{
			idc = 2581;
			text = "$STR_VAS_Main_Vests";
			action = "[1] spawn VAS_fnc_filterMenu";
			x = safeZoneX + safeZoneW * 0.47125;
			y = safeZoneY + safeZoneH * 0.39666667;
			w = safeZoneW * 0.11375;
			h = safeZoneH * 0.02222223;
			
		};
		class Filter3 : VAS_RscActiveText 
		{
			idc = 2582;
			text = "$STR_VAS_Main_Headgear";
			action = "[2] spawn VAS_fnc_filterMenu";
			x = safeZoneX + safeZoneW * 0.47125;
			y = safeZoneY + safeZoneH * 0.41333334;
			w = safeZoneW * 0.11375;
			h = safeZoneH * 0.02222223;
			
		};
		class Filter4 : VAS_RscActiveText 
		{
			idc = 2583;
			text = "$STR_VAS_Main_Attachments";
			action = "[3] spawn VAS_fnc_filterMenu";
			x = safeZoneX + safeZoneW * 0.47125;
			y = safeZoneY + safeZoneH * 0.43;
			w = safeZoneW * 0.11375;
			h = safeZoneH * 0.02222223;
			
		};
		class Filter5 : VAS_RscActiveText 
		{
			idc = 2584;
			text = "$STR_VAS_Main_Misc";
			action = "[4] spawn VAS_fnc_filterMenu";
			x = safeZoneX + safeZoneW * 0.47125;
			y = safeZoneY + safeZoneH * 0.44666667;
			w = safeZoneW * 0.11375;
			h = safeZoneH * 0.02222223;
			
		};
		class Title : VAS_RscTitle 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26;
			y = safeZoneY + safeZoneH * 0.186;
			w = safeZoneW * 0.480625;
			h = safeZoneH * 0.02222223;
			text = "Virtual Ammobox System";
			colorBackground[] = {0,0,0,0};
			
		};
		class VersionNumber : Title
		{
			idc = 2404;
			style = 1;
			text = "v2.95";
			
		};
		class ButtonAddG : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.2725;
			y = safeZoneY + safeZoneH * 0.56888889;
			w = safeZoneW * 0.153125;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_btnAdd;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			onButtonClick = "[] spawn VAS_fnc_addGear";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class ButtonRemoveG : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.570625;
			y = safeZoneY + safeZoneH * 0.56888889;
			w = safeZoneW * 0.153125;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_btnRemove;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
			onButtonClick = "[false] spawn VAS_fnc_removeGear;";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class ButtonClose : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26;
			y = safeZoneY + safeZoneH * 0.61777778;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_btnClose;
			onButtonClick = "closeDialog 0;";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class ButtonSaveGear : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.325625;
			y = safeZoneY + safeZoneH * 0.61777778;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_btnSave;
			onButtonClick = "createDialog ""VAS_Save_Diag"";";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class ButtonLoadGear : VAS_RscButtonMenu 
		{
			idc = -1;
			x = safeZoneX + safeZoneW * 0.39125;
			y = safeZoneY + safeZoneH * 0.61777778;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_btnLoad;
			onButtonClick = "createDialog ""VAS_Load_Diag"";";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		class ButtonRemoveAll : VAS_RscButtonMenu 
		{
			idc = 2999;
			x = safeZoneX + safeZoneW * 0.457;
			y = safeZoneY + safeZoneH * 0.61777778;
			w = safeZoneW * 0.064375;
			h = safeZoneH * 0.02222223;
			text = $STR_VAS_Main_btnRemoveAll;
			onButtonClick = "[true] spawn VAS_fnc_removeGear;";
			class HitZone
			{
				top = 0.0;
				right = 0.0;
				bottom = 0.0;
				left = 0.0;
				
			};
			class ShortcutPos
			{
				top = 0.005;
				left = (6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005;
				w = 0.0225;
				h = 0.03;
				
			};
			class TextPos
			{
				top = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0.0;
				left = 0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40);
				
			};
			
		};
		
	};
	
};


class VAS_Load_Diag {
	idd = 2520;
	name= "Virtual_Ammobox_Sys Load";
	movingEnable = false;
	enableSimulation = true;
	onLoad = "[1] spawn VAS_fnc_SaveLoad";
	onUnload = "['guns',false] spawn VAS_fnc_mainDisplay";

	class controlsBackground {
		class VAS_RscTitleBackground:VAS_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 0.1;
			y = 0.2;
			w = 0.6;
			h = (1 / 25);
		};

		class MainBackground:VAS_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.1;
			y = 0.2 + (11 / 250);
			w = 0.6;
			h = 0.6 - (22 / 250);
		};
	};

	class controls {


		class Title : VAS_RscTitle {
			colorBackground[] = {0, 0, 0, 0};
			idc = -1;
			text = "$STR_VAS_Load_Title";
			x = 0.1;
			y = 0.2;
			w = 0.6;
			h = (1 / 25);
		};

		class LoadLoadoutList : VAS_RscListBox
		{
			idc = 2521;
			text = "";
			sizeEx = 0.035;
			onLBSelChanged = "[1] spawn VAS_fnc_loadoutInfo";

			x = 0.12; y = 0.26;
			w = 0.230; h = 0.360;
		};

		class LoadFetchList : VAS_RscListBox
		{
			idc = 2522;
			colorBackground[] = {0,0,0,0};
			text = "";
			sizeEx = 0.030;

			x = 0.35; y = 0.26;
			w = 0.330; h = 0.360;
		};


		class CloseLoadMenu : VAS_RscButtonMenu {
			idc = -1;
			text = "$STR_VAS_Main_btnClose";
			onButtonClick = "closeDialog 0;";
			x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.8 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class LoadOnRespawnMenu : VAS_RscButtonMenu {
			idc = -1;
			text = "$STR_VAS_Load_LOR";
			onButtonClick = "if(vas_onRespawn) then {[] call VAS_fnc_onRespawn;} else {hint ""Disabled""};";
			x = 0.10 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.8 - (1 / 25);
			w = (9 / 40);
			h = (1 / 25);
		};

		class TransBtn : VAS_RscButtonMenu
		{
			idc = -1;
			text = "$STR_VAS_Load_TransferBtn";
			onButtonClick = "[] call VAS_fnc_transferMenu";
			x = 0.33 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.8 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class GearLoadMenu : VAS_RscButtonMenu {
			idc = -1;
			text = "$STR_VAS_Load_btnLoad";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[] spawn VAS_fnc_loadGear";
			x = 0.05 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.73 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class GearDeleteMenu : VAS_RscButtonMenu
		{
			idc = -1;
			text = "$STR_VAS_Load_btnDelete";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[] spawn VAS_fnc_deleteGear";
			x = 0.25 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.73 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};
	};
};

class VAS_TransferMenu
{
	idd = 2560;
	name = "Virtual_Ammobox_sys_transfermenu";
	movingEnabled = false;
	enableSimulation = true;

	class Controls
	{
		class MainMenu : VAS_RscControlsGroup
		{
			idc = 2600;

			class Controls
			{
				class VAS_RscTitleBackground : VAS_RscText
				{
					idc = -1;
					colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
					x = 0.25;
					y = 0.2;
					w = 0.5;
					h = (1 / 25);
				};

				class MainBackground : VAS_RscText
				{
					colorBackground[] = {0,0,0,0.7};
					idc = -1;
					x = 0.25;
					y = 0.2 + (11 / 250);
					w = 0.5;
					h = 0.6 - (22 / 250);
				};

				class Title : VAS_RscTitle
				{
					idc = -1;
					text = "$STR_VAS_Transfer_MainMenu";
					x = 0.25;
					y = 0.2;
					w = 0.5;
					h = (1 / 25);
				};

				class UnitsList : VAS_RscListBox
				{
					idc = 2601;
					text = "";
					sizeEx = 0.045;
					canDrag = 1;
					x = 0.26; y = 0.26;
					w = 0.47; h = 0.45;
				};

				class TransBtn : VAS_RscButtonMenu
				{
					idc = -1;
					text = "$STR_VAS_Load_TransferBtn";
					onButtonClick = "[] call VAS_fnc_transferAction";
					x = 0.26 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
					y = 0.8 - (1 / 25);
					w = (6.25 / 40);
					h = (1 / 25);
				};
			};
		};

		class TransferSaveMenu : VAS_RscControlsGroup
		{
			idc = 2700;

			class Controls
			{
				class VAS_RscTitleBackground:VAS_RscText
				{
					colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
					idc = -1;
					x = 0.1;
					y = 0.2;
					w = 0.6;
					h = (1 / 25);
				};

				class MainBackground:VAS_RscText {
					colorBackground[] = {0, 0, 0, 0.7};
					idc = -1;
					x = 0.1;
					y = 0.2 + (11 / 250);
					w = 0.6;
					h = 0.6 - (22 / 250);
				};

				class Title : VAS_RscTitle {
					colorBackground[] = {0, 0, 0, 0};
					idc = -1;
					text = "$STR_VAS_Save_Title";
					x = 0.1;
					y = 0.2;
					w = 0.6;
					h = (1 / 25);
				};

				class SaveLoadoutList : VAS_RscListBox
				{
					idc = 2711;
					text = "";
					sizeEx = 0.035;

					x = 0.12; y = 0.26;
					w = 0.230; h = 0.360;
				};

				class SaveFetchList : VAS_RscListBox
				{
					idc = 2513;
					colorBackground[] = {0,0,0,0};
					text = "";
					sizeEx = 0.030;

					x = 0.35; y = 0.26;
					w = 0.330; h = 0.360;
				};

				class SaveLoadEdit : VAS_RscEdit
				{
					idc = 2712;
					text = "$STR_VAS_Save_CLN";

					x = -0.05 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
					y = 0.73 - (1 / 25);
					w = (13 / 40);
					h = (1 / 25);
				};

				class GearSaveMenu : VAS_RscButtonMenu
				{
					idc = -1;
					text = "$STR_VAS_Save_btnSave";
					colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
					onButtonClick = "[] call VAS_fnc_transferSaveGear";
					x = 0.35 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
					y = 0.73 - (1 / 25);
					w = (6.25 / 40);
					h = (1 / 25);
				};
			};
		};
	};
};

class VAS_Save_Diag {
	idd = 2510;
	name= "Virtual_Ammobox_Sys Save";
	movingEnable = false;
	enableSimulation = true;
	onLoad = "[0] spawn VAS_fnc_SaveLoad";

	class controlsBackground {
		class VAS_RscTitleBackground:VAS_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 0.1;
			y = 0.2;
			w = 0.6;
			h = (1 / 25);
		};

		class MainBackground:VAS_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.1;
			y = 0.2 + (11 / 250);
			w = 0.6;
			h = 0.6 - (22 / 250);
		};
	};

	class controls
	{
		class Title : VAS_RscTitle {
			colorBackground[] = {0, 0, 0, 0};
			idc = -1;
			text = "$STR_VAS_Save_Title";
			x = 0.1;
			y = 0.2;
			w = 0.6;
			h = (1 / 25);
		};

		class SaveLoadoutList : VAS_RscListBox
		{
			idc = 2511;
			text = "";
			sizeEx = 0.035;
			onLBSelChanged = "[0] spawn VAS_fnc_loadoutInfo";

			x = 0.12; y = 0.26;
			w = 0.230; h = 0.360;
		};

		class SaveFetchList : VAS_RscListBox
		{
			idc = 2513;
			colorBackground[] = {0,0,0,0};
			text = "";
			sizeEx = 0.030;

			x = 0.35; y = 0.26;
			w = 0.330; h = 0.360;
		};

		class SaveLoadEdit : VAS_RscEdit
		{
			idc = 2512;
			text = "$STR_VAS_Save_CLN";

			x = -0.05 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.73 - (1 / 25);
			w = (13 / 40);
			h = (1 / 25);
		};

		class CloseSaveMenu : VAS_RscButtonMenu {
			idc = -1;
			text = "$STR_VAS_Main_btnClose";
			onButtonClick = "closeDialog 0;";
			x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.8 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class GearSaveMenu : VAS_RscButtonMenu {
			idc = -1;
			text = "$STR_VAS_Save_btnSave";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[] call VAS_fnc_saveGear";
			x = 0.35 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.73 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};
	};
};

class VAS_prompt
{
	idd = 2550;
	name = "Virtual_Ammobox_sys_prompt";
	movingEnabled = false;
	enableSimulation = true;

	class controlsBackground {
		class VAS_RscTitleBackground:VAS_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 0.3;
			y = 0.2;
			w = 0.47;
			h = (1 / 25);
		};

		class MainBackground:VAS_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.3;
			y = 0.2 + (11 / 250);
			w = 0.47;
			h = 0.22 - (22 / 250);
		};
	};

	class controls
	{
		class InfoMsg : VAS_RscStructuredText
		{
			idc = 2551;
			sizeEx = 0.020;
			text = "";
			x = 0.287;
			y = 0.2 + (11 / 250);
			w = 0.5; h = 0.12;
		};

		class addtogun : VAS_RscButtonMenu {
			idc = 2552;
			text = "$STR_VAS_Prompt_addToWeapon";
			//colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "vas_prompt_choice = true; closeDialog 0;";
			x = 0.145 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.42 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class addtogear : VAS_RscButtonMenu {
			idc = 2553;
			text = "$STR_VAS_Prompt_addToInv";
			//colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "vas_prompt_choice = false; closeDialog 0;";
			x = 0.455 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.42 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class blankPHVAS : VAS_RscText
		{
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.304 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.42 - (1 / 25);
			w = (5.9 / 40);
			h = (1 / 25);
		};
	};
};
