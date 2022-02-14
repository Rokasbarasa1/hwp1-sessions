Makefile compilling method

This uses a makefile with defined sequence of compilation to build and flash the atmega2560.

Requirements for this
* Need environment path defined to avr-gcc and avr-objectcopy compiler.
* Need environment path defined to avrdude flasher.
* Need to download make with chocolatey (choco install make)
* Need to link current directory in the make file.

Limitations of this:
* Cant debug and cant run it with atmel ice
