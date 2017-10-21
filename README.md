Arduino core for Linux UserSpace
===========================================

This project brings support Linux Program support to the Arduino environment.
It lets you write sketches using familiar Arduino functions and libraries, and run them directly, no external microcontroller required.

# Contents
- Installing options:
  - [Using Boards Manager](#installing-with-boards-manager)
  - [Using git version](#using-git-version)
- [Documentation](#documentation)
- [Issues and support](#issues-and-support)
- [Contributing](#contributing)  
- [License and credits](#license-and-credits)   

### Installing with Boards Manager ###

Starting with 1.6.4, Arduino allows installation of third-party platform packages using Boards Manager. We have packages available for Windows, Mac OS, and Linux (32 and 64 bit).

- Install Arduino 1.6.8 from the [Arduino website](http://www.arduino.cc/en/main/software).
- Start Arduino and open Preferences window.
- Enter ```TODO:path_to_package_linduio_index.json``` into *Additional Board Manager URLs* field. You can add multiple URLs, separating them with commas.
- Open Boards Manager from Tools > Board menu and install *Linduino* platform (and don't forget to select Linduino from Tools > Board menu after installation).

#### Available versions

##### Staging version
This is not stable.

There is not yet documentation.

### Using git version

- Install Arduino 1.8.5
- Go to Arduino directory
- Clone this repository into hardware/linduino/linduino-0.0.1 directory (or clone it elsewhere and create a symlink)
```bash
cd hardware
mkdir linduino
cd linduino
git clone https://github.com/rsaxvc/Linduino.git linduino-0.0.1
```
- Restart Arduino

### Documentation

Documentation for latest development version:

- [Reference](doc/reference.md)
- [Libraries](doc/libraries.md)
- [File system](doc/filesystem.md)
- [OTA update](doc/ota_updates/readme.md)
- [Supported boards](doc/boards.md)
- [Change log](doc/changes.md)

### Issues and support ###

If you encounter an issue, you are welcome to submit it here on Github: https://github.com/rsaxvc/Linduino/issues.
Please provide as much context as possible: version which you are using (you can check it in Boards Manager), your sketch code, serial output, board model, IDE settings (board selection, flash size, etc).

### Contributing

For minor fixes of code and documentation, go ahead and submit a pull request.

Check out [the list of issue](https://github.com/rsaxvc/Linduino/issues). Working on them is a great way to move the project forward.

Feature branches with lots of small commits (especially titled "oops", "fix typo", "forgot to add file", etc.) should be squashed before opening a pull request. At the same time, please refrain from putting multiple unrelated changes into a single pull request.

### License and credits ###

Arduino IDE is developed and maintained by the Arduino team. The IDE is licensed under GPL.

[ESP8266 core](github.com/esp8266/arduino) is a super awesome arduino core with WiFi, that has nothing to do with building Arduino sketches natively for Linux, other than it was the only core I had cloned with git on my laptop when I started writing Linduino. I'm also familiar with it from optimizing their SPI transmitter a little bit.

RSAXVC Linduino needs a new name, as Linear Tech named their Arduino board Linduino.

RSAXVC Linduino core files are licensed under LGPL.
