Fireplace Controller via Amazon Echo & ESP8266/Arduino
===

Overview
---
The purpose of this project is to control a gas fireplace via an Amazon Echo. This is done by mimicking the codes sent from the fireplace remote with an Arduino-like device, sending the signals using an RF transmitter module. I wanted to develop a voice-enabled solution where no changes to the fireplace's existing ignition and control system was required.

This solution was developed and tested against a Heat & Glo gas fireplace with [Skytech Smart-Stat II fireplace remote control](http://amzn.to/2jRKULh).

Tools
---
- [Amazon Echo](http://amzn.to/2iFdL7G) (or [Dot](http://amzn.to/2ivlQ0k))
- [HiLetgo ESP8266](http://amzn.to/2jsNHgY)
- [NooElec NESDR](http://amzn.to/2jRVXEm) (for listening to RF codes)
- [303.825 MHz transmitter module](https://www.appliedwireless.com/index.cfm?fuseaction=product.display&product_ID=42&ParentCat=5)

Software
---
- SDR Software ([SDRSharp](http://airspy.com) for Windows, [GQRX](http://gqrx.dk) for Mac)
- [Audacity](http://www.audacityteam.org)
- [RCSwitch](https://github.com/sui77/rc-switch)

Frequency
---
The Smart Stat II controller is rated to emit on a frequency of 303.8 MHz (actual: 303.74 MHz). The closest transmitter module I've found is 303.825 MHz, which falls in the Skytech receiver's listening range. If the frequencies between your transmitter and receiver don't line up, your receiver may require manual adjustment.

Remote States
---
The remote has three states: ON, OFF, and OFF w/ thermostat. For the purposes of this project, the OFF w/ thermostat state was not used.

Using GQRX and Audacity, the Skytech remote was found to emit the following codes:

State          | Code
---------------|---------
On             | `1111011110100011101100010`
Off            | `1111011110100011101100110`
Off w/ thermo: | `1111011110100011101100100`

Pulse Length
---
The Skytech receiver seemed sensitive to the pulse length as set by the `RCSwitch` library (defaults around `320`). Setting the pulse length to `430` seemed to alleviate this. If you're having difficulty getting the receiver to respond to your mimicked transmissions, I recommend testing those signals with Audacity and checking that the overall transmission lengths match closely to those emitted by the original controller.

Pinout
---

ESP8266 (12E) | TX303A
--------------|----------
3.3v          | 1 - Vcc
GND           | 2 - GND
D6 (GPIO12)   | 3 - RF In
GND           | 4 - GND
              | 5 - RF Out (loose wire)

Credits
---
Thanks to:

- The RCSwitch team
- Contributors to the [Fauxmo](https://github.com/makermusings/fauxmo)   project
- Aruna Tennakoon for [bringing together Fauxmo and ESP8266](https://github.com/kakopappa/arduino-esp8266-alexa-wemo-switch)
