# Robot Bjorn - an Arduino based open source robot #
By [Ramoonus](http://www.ramoonus.nl)

RobotBjorn is a Arduino based 4 wheel drive robot. 
It uses basic Arduino Shields and open source firmware (writting in C++, [Wiring](http://wiring.org.co/) and the client in [Processing](http://www.processing.org/))

Compatibility with third-party shields and platforms is described in the [Compatibility](compatibility.md) document.

RobotBjorn is named Bjorn, after [Asbjørn A Mikkelsen](https://twitter.com/neslekkim)

## Donate ##
The Robot itself costs approx. 100 Euro but modifications and tutorial material costs much more.
Please sponsor me and this project by donating via PayPal using the link: 
[Donate](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=RZ2HK2NADF4DC "Donate through PayPal")

## Software Toolkit ##
I used the following software for the development:

* Robot Firmware: [Arduino IDE](http://arduino.cc/en/Main/Software "Download Arduino IDE") 1.6.0
* Documents: [MarkdownPad](http://markdownpad.com/ "Download MarkdownPad") (for Windows)
* Schematics: [Fritzing](http://fritzing.org/ "Download Fritzing") 
* Client: [Processing](http://processing.org/download/ "Download Processing") 2.0

Should be fully compatible with
* [Atmel Studio 6.1 update 2.0](http://www.atmel.com/microsite/atmel_studio6/ "Atmel Studio 6")  +  [Visual Micro](http://www.visualmicro.com/ "Visual Micro")
* [Arduino IDE](http://arduino.cc/en/Main/Software "Download Arduino IDE") 1.0.x
* Eclipse IDE for C/C++ Developers + AVR
* * Robot Firmware: [Arduino IDE](http://arduino.cc/en/Main/Software "Download Arduino IDE") 1.5.x


## Release Notes ##
### Dev: 1.5 / 2.0 ###
* Added function: Gearbox(int gear) to modify PWM on a scale 1-10
* Added function: AutoPilot (under construction)
* Added function KeyboardControl to replace the functionality added in version 1.4
* [Readme.md](README.md) improvements.
* Added support for Atmel Studio 6.1 + Visual Micro
* Added support for Eclipse IDE
* Fix GitHub version taggging for releases 1.2-1.4  
* Updated Compatibility list

### 1.4 - 25-7-2013 ###
* Updated readme.md
* Removed software version numbers. Preferred version: latest stable
* Updated schematics to use official Arduino shields
* Documents now use [GitHub Flavored Markdown](https://help.github.com/articles/github-flavored-markdown)
* Todo list now in GitHub Flavored Markdown
* Added keyboard controls using serial input. WSAD to move. X to stop. Z to check activity.
 
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

### 1.2 - 12-1-2013 ###
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
