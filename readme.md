# Robot Bjorn - an Arduino based open source robot #
By [Ramoonus](http://www.ramoonus.nl)

RobotBjorn is a Arduino based 4 wheel drive robot. 
It uses basic Arduino Shields and open source firmware (writting in C++, [Wiring](http://wiring.org.co/) and [Processing](http://www.processing.org/))
The Robot costs approx. 100 EURO to build and requires little expertise.

Compatibility with third-party shields and platforms is described in the [Compatibility](compatibility.md) document.

Future development is specified in a [Todo](todo.md)

# Donate #
The Robot itself costs approx. 100 Euro but modifications and tutorial material costs much more.
Please sponsor this project by donating via PayPal using the link: 
[Donate](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=RZ2HK2NADF4DC "Donate through PayPal")

## Software Toolkit ##
I used the following software for the development:

* [Arduino IDE](http://arduino.cc/en/Main/Software "Download Arduino IDE") 1.0.5 and 1.5.2
* [MarkdownPad](http://markdownpad.com/ "Download MarkdownPad") (for Windows)
* [Fritzing](http://fritzing.org/ "Download Fritzing") 0.7.12
* [Processing](http://processing.org/download/ "Download Processing") 2.0 Beta 8

## Release Notes ##
### 1.4 dev ###
*

### 1.3 - 10-2-2013 ###
* Improved Documentation (see [Relative links in markup files - GitHub blog](https://github.com/blog/1395-relative-links-in-markup-files) )
* Primary development platform is now Arduino 1.5
* Started development of Processing client
* Replaced #define with const (improved code styling)
* Rewritten sensor reading, now with dynamic port mapping (SensorLeftPort etc)
* Added function Horn (claxon, beep) function and port (HornPort)
* Enabled lights for turning left and right
* Reverse Lights
* Brake Lights

### 1.2 12-1-2013 ###
* Engine Current Reading in mA for both channels A and B (hardware mod)

### 1.1 - 30-12-2012 ###
* Updated Schematics
* Pinconfiguration list
* Extra functions for 1.2-2.0 released
* Auto Start-Stop condition for use with 1 sensor
* Readme

### 1.0 - 22-12-2012 ###
* Created drive and brake functions to simplify controls, aswell as per channel control
* Test function to test drive and brake functions
* Documented the code (see source)
* Drawing Schematics (using Fritzing)

