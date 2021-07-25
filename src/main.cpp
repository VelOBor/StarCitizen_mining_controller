/*
This is the code for the Star Citizen Mining Controller by Salty NUggeTZ (AKA Helgar_Fenrir) VelOBor.
The wirng diagram is designed in fritzing, and the 3D model in Autodesk Fusion360 (startup license, free for non-profit),
code is written in VSCode PlatformIO.
The entire project is done in open source (or otherwise free for non-profit) software and hardware.
The controller is based on an Arduino Pro Micro board and joystick.h library by M. Heironimus and can be found at 
https://github.com/MHeironimus/ArduinoJoystickLibrary
This controller is intended for use with the game Star Citizen by Cloud Imperium Games and Roberts Space Industries.
You are free to replicate the controller as you wish, feel free to give credit to the original author. 
*/

#include <Arduino.h> //make sure VSCode understands that this is an arduino sketch
#include <Joystick.h> //include the Joystick library

Joystick_ joystick; //create a joystick instance called "joystick"... Pretty inventive, huh...

//define input pins for the pots
int leftpotpin = A0; //RESERVE 
int rightpotpin = A1; //used for laser output power control

//define the pins for the buttons
int but1pin = 2; //top left button, green (turret mode "Q", rel/abs)
int but2pin = 3; //secod from top left, yellow (gyro mode "G")
int but3pin = 6; //first row, first button, red (mining mode enable "M")
int but4pin = 5; //first row, second button, blue (scanning mode "TAB")
int but5pin = 4; //first row, third button, green (recenter turret "C")
int but6pin = 9; //second row, first button, red (comsumable 1)
int but7pin = 8; //second row, second button, red (consumable 2)
int but8pin = 7; //second row, third button, red (comsumable 3)

int tog1uppin = 14; //left toggle, non-latching, up position (radar angle decrease)
int tog1downpin = 15; //left toggle, non-latching, down position (radar angle increase)

int tog2uppin = 16; //right toggle, latching, capped, up position (jettison cargo)

//define variables to hold the state of buttons and value of pots
byte but1state = 0;
byte but2state = 0;
byte but3state = 0;
byte but4state = 0;
byte but5state = 0;
byte but6state = 0;
byte but7state = 0;
byte but8state = 0;
byte tog1upstate = 0;
byte tog1downstate = 0;
byte tog2upstate = 0;

//bytes to hold the button states to send to joystick library after debounce
byte but1laststate = 0;
byte but2laststate = 0;
byte but3laststate = 0;
byte but4laststate = 0;
byte but5laststate = 0;
byte but6laststate = 0;
byte but7laststate = 0;
byte but8laststate = 0;
byte tog1uplaststate = 0;
byte tog1downlaststate = 0;
byte tog2uplaststate = 0;

//slider pot values
int leftpotval = 0; //UNUSED
int rightpotval = 0;



//setup part of code, runs once at microcontroller boot time
void setup() 
{
rightpotval = 0;

joystick.begin();

//set pin modes for the local button pins
pinMode(but1pin, INPUT_PULLUP);
pinMode(but2pin, INPUT_PULLUP);
pinMode(but3pin, INPUT_PULLUP);
pinMode(but4pin, INPUT_PULLUP);
pinMode(but5pin, INPUT_PULLUP);
pinMode(but6pin, INPUT_PULLUP);
pinMode(but7pin, INPUT_PULLUP);
pinMode(but8pin, INPUT_PULLUP);
pinMode(tog1uppin, INPUT_PULLUP);
pinMode(tog1downpin, INPUT_PULLUP);
pinMode(tog2uppin, INPUT_PULLUP);

//Serial.begin(115200); //initialize serial comms for debugging
}
//main part of the code, repeats as long as the controller is running
void loop() 
{

  //read pot
  rightpotval = map(analogRead(rightpotpin), 0, 1023, 1023, 0); //reads and reverses the value

  //read buttons (use the ! to invert the logic because of using PULLUP)
  but1state = !digitalRead(but1pin);
  but2state = !digitalRead(but2pin);
  but3state = !digitalRead(but3pin);
  but4state = !digitalRead(but4pin);
  but5state = !digitalRead(but5pin);
  but6state = !digitalRead(but6pin);
  but7state = !digitalRead(but7pin);
  but8state = !digitalRead(but8pin);
  tog1upstate = !digitalRead(tog1uppin);
  tog1downstate = !digitalRead(tog1downpin);
  tog2upstate = !digitalRead(tog2uppin);

  //tell the joystick library where to get the values for the axis
  joystick.setYAxis(rightpotval);
  
  //tell the joystick library state of buttons
	if (but1state != but1laststate)
	{
	joystick.setButton(0, but1state);
	but1laststate = but1state;
	}
  if (but2state != but2laststate)
	{
	joystick.setButton(1, but2state);
	but2laststate = but2state;
	}
  if (but3state != but3laststate)
	{
	joystick.setButton(2, but3state);
	but3laststate = but3state;
	}
  if (but4state != but4laststate)
	{
	joystick.setButton(3, but4state);
	but4laststate = but4state;
	}
  if (but5state != but5laststate)
	{
	joystick.setButton(4, but5state);
	but5laststate = but5state;
	}
  if (but6state != but6laststate)
	{
	joystick.setButton(5, but6state);
	but6laststate = but6state;
	}
  if (but7state != but7laststate)
	{
	joystick.setButton(6, but7state);
	but7laststate = but7state;
	}
  if (but8state != but8laststate)
	{
	joystick.setButton(7, but8state);
	but8laststate = but8state;
	}
  if (tog1upstate != tog1uplaststate)
	{
	joystick.setButton(8, tog1upstate);
	tog1uplaststate = tog1upstate;
	}
  if (tog1downstate != tog1downlaststate)
	{
	joystick.setButton(9, tog1downstate);
	tog1downlaststate = tog1downstate;
	}
  if (tog2upstate != tog2uplaststate)
	{
	joystick.setButton(10, tog2upstate);
	tog2uplaststate = tog2upstate;
	}
    
delay(5);
/*
//debugging - print pot value to screen...
  Serial.print("rightpot: "); Serial.print(rightpotval); 
//debugging - print button and toggle states to screen...
  Serial.print(" b1s: "); Serial.print(but1state);
  Serial.print(" b2s: "); Serial.print(but2state); 
  Serial.print(" b3s: "); Serial.print(but3state);
  Serial.print(" b4s: "); Serial.print(but4state);
  Serial.print(" b5s: "); Serial.print(but5state); 
  Serial.print(" b6s: "); Serial.print(but6state);
  Serial.print(" b7s: "); Serial.print(but7state);
  Serial.print(" b8s: "); Serial.print(but8state); 
  Serial.print(" t1ups: "); Serial.print(tog1upstate);
  Serial.print(" t1ds: "); Serial.print(tog1downstate);
  Serial.print(" t2ups: "); Serial.println(tog2upstate);  
*/
}