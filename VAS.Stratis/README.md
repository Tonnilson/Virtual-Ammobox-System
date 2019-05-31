<h1 align="center">Virtual Ammobox System</h1>
<p align="center">
  <a href="http://forums.bistudio.com/showthread.php?149077-Virtual-Ammobox-System-%28VAS%29">
    <img src="https://img.shields.io/badge/BIF-thread-lightgrey.svg?style=flat"
         alt="BIF Thread" />
  </a>
  <a href="https://raw.githubusercontent.com/Tonnilson/VAS/master/changelog.txt">
    <img src="http://img.shields.io/badge/Version-2.91-blue.svg?style=flat"
         alt="Changelog" />
  </a>
  <a href="http://www.armaholic.com/page.php?id=19134">
    <img src="http://img.shields.io/badge/Download-1_MB-green.svg?style=flat"
         alt="Download" />
  </a>
  <a href="https://github.com/Tonnilson/Virtual-Ammobox-System/issues">
    <img src="http://img.shields.io/github/issues-raw/Tonnilson/Virtual-Ammobox-System.svg?label=Issues&style=flat"
         alt="Issues" />
  </a>
  <a href="#license">
    <img src="http://img.shields.io/badge/License-Custom-red.svg?style=flat"
         alt="License" />
  </a>
</p>

Welcome and thank you for the interest in Virtual Ammobox System (VAS). This addon provides Arma 3 players with a user-friendly alternative to the default interface for handling of personal gear loadout —&nbsp;ammo, guns &amp; items.

VAS was written by [Tonic](https://github.com/Tonnilson), originally an an isolated script to compliment the release of a specific mission. However, after it reached the initial success and a wide adoption among Arma 3 community, the VAS author has decided to made the entire source code available publicly - for everyone to use, modify and contribute to its ongoing development.

### Goals
* Provide a viable alternative to [Arsenal](https://community.bistudio.com/wiki/Arsenal) — the native solution from [BIS](http://www.bistudio.com/)
* Save players the time spent browsing the in-game inventory, through focus on the speed and ease of UI interaction.
* Deal with possible network lag issues, related to the way inventory management is handled in code.

### Installation
The system is very easy to integrate into your own mission — simply, copy it to your mission folder and add the following lines to your **description.ext**:
```hpp
#include "VAS\menu.hpp"

class CfgFunctions
{
	#include "VAS\cfgfunctions.hpp"
};
```
This inclusion shouldn't conflict with any existing dialogs, neither custom nor default. perhaps only with the exception of Wasteland where the default class names are identical to VAS.

I would recommend attaching the VAS menu to a pre-existing ammunition box, so when you place an ammobox in map via editor, add the following into its initialization field:
```sqf
this addAction["<t color='#ff1111'>Virtual Ammobox</t>", "VAS\open.sqf"];
```
That's it! Now when you look at your new ammunition box in-game, the mouse-wheel menu will present you with the "Virtual Ammobox" item. The underlying interface is localized into 8 languages, and is intuitive enough to skip the introductions.

### License <a name="license"></a>
Use of Virtual Ammobox System (VAS) in missions published on [Steam Workshop](http://steamcommunity.com/app/107410/workshop/?l=english) is allowed. Republishing of the system is fine so long as original links are included.

VAS is intended for mission designers to be integrated into their own work, and is not to be released separately (as is) via the Workshop.

### Special Thanks
* [Dslyecxi](http://dslyecxi.com/) for his Paper Doll script, giving me insight on how to detect item types.
* [Kronzky](http://www.kronzky.info/) for his string function library.
* [Robalo](http://arma-sr.bzbit.com/) for providing code changes to help support the new compatibleItems class structure.
* [Tyrghen](http://veterans.armasites.com/) for the tip on CfgFunctions.
* [naong](http://www.armaholic.com/forums.php?m=posts&id=142583) for his code tweaks to the Load/Save display.
* [Sa-Matra](https://wasteland.arma.su/) for help with UI resources and Russian translation.
  * [PR9INICHEK](https://github.com/PR9INICHEK) & [Tourorist](https://github.com/Tourorist) for updates and additions to the Russian localization.
* [Coding](http://www.armaholic.com/forums.php?m=posts&id=149222) for translating VAS into German.
  * [MemphisBelle](https://twitter.com/MemphisBelle291) for tweaks to the German translation.
* [El nabot](http://www.armaholic.com/forums.php?m=posts&q=20990&d=105) for French translation.
* [czesiek77](http://instagram.com/czesiek77) for Polish translation.
* [Ficc](http://www.rifleonlyclan.com/) for Portuguese translation.
* [ramius86](https://github.com/ramius86) for Italian translation.
* [RabsRincon](http://www.armaholic.com/forums.php?m=posts&q=24317) for Spanish translation.
* [Bakarda](https://www.youtube.com/user/Bakarda/) for Czech translation.
* *The list goes on...*

My apologies if I left anyone out — please, let me know!
