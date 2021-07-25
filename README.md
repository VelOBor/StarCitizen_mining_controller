# StarCitizen_mining_controller  
This is the repository for SaltyNUggeTZ's DIY mining controller for Star Citizen game  
The wirng diagram is designed in fritzing, and the 3D model in Autodesk Fusion360 (startup license, free for non-profit),  
code is written in VSCode PlatformIO.  
The entire project is done in open source (or otherwise free for non-profit) software and hardware.  
The controller is based on an Arduino Pro Micro board and joystick.h library by M. Heironimus and can be found at   
https://github.com/MHeironimus/ArduinoJoystickLibrary  
This controller is intended for use with the game Star Citizen by Cloud Imperium Games and Roberts Space Industries.  
You are free to replicate the controller as you wish, feel free to give credit to the original author.  
Images of the project are located at www.imgur.com/a/ncCLJdH  
The schematics in fritzing are located within the root directory of this repository. File is named "SC mining controller schematic (fritzing)"  
I decided to use an off the shelf available housing that's intended as a crane remote control, and I made the model of it in Fusion360,  
You could print this housing (may want to close up the holes in one of the clamshells) or find a better housing, or even design your own.  
The 3D model (in Fusion360) can be found here: https://a360.co/3kVoCuL (unfortunately due to limitations of the non-commercial license you can't download the model)  
You can however find the STL file in the root directory of this repository under the filename "Mining Controller assembly v21"  
Feel free to ping me at https://www.reddit.com/user/Salty_NUggeTZ if you have any questions or need help replicating this design  

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
