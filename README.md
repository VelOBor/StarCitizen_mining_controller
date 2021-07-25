# StarCitizen_mining_controller
This is the repository for SaltyNUggeTZ's DIY mining controller for Star Citizen game
The wirng diagram is designed in fritzing, and the 3D model in Autodesk Fusion360 (startup license, free for non-profit),
code is written in VSCode PlatformIO.
The entire project is done in open source (or otherwise free for non-profit) software and hardware.
The controller is based on an Arduino Pro Micro board and joystick.h library by M. Heironimus and can be found at 
https://github.com/MHeironimus/ArduinoJoystickLibrary
This controller is intended for use with the game Star Citizen by Cloud Imperium Games and Roberts Space Industries.
You are free to replicate the controller as you wish, feel free to give credit to the original author. 
The functions layout and concept:
Axes: 2 (1 used, 1 reserve)
Buttons: 8 (momentary)
Toggles: 2 (one latching with cap and one ON position, one non-latching two ON positions) 

---Functions:
Toggle turret movement (relative/absolute)
Mining mode enable (button, in-game toggle action)
Increase/decrease mining laser (axis)
Activate consumable 1
Activate consumable 2
Activate consumable 3
Jettison cargo (capped toggle switch)
Scanning mode
Increase radar angle (two way non-latching toggle)
Decrease radar angle (two way non-latching toggle)
Re-center turret (hold)
Gyro mode

---Layout (actual placement of buttons and toggles up to design):

Button 1 (large, green) - toggle turret mode (in-game default Q, rel/abs)
Button 2 (large, yellow) - gyro mode (in-game default G)
Button 2 (large, red) - mining mode enable (in-game default M)
Button 3 (large, blue) - scanning mode enable (in-game default TAB)
Button 4 (large, green) - re-center turret (in-game default C)

Button 6 (small, red) - consumable 1
Button 7 (small, red) - consumable 2
Button 8 (small, red) - consumable 3

Axis 1 (left slide pot) - RESERVE
Axis 2 (right slide pot) - mining laser power (in-game default mouse wheel)

Toggle 1 (non-latching), contactor 1 - increase radar angle
Toggle 1 (non-latching), contactor 2 - decrease radar angle

Toggle 2 (capped, latching) - jettison cargo
<blockquote class="imgur-embed-pub" lang="en" data-id="a/ncCLJdH"  ><a href="//imgur.com/a/ncCLJdH">Star Citizen mining controller images</a></blockquote><script async src="//s.imgur.com/min/embed.js" charset="utf-8"></script>
