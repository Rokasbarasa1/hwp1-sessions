Makefile compiling method

This uses a makefile with defined sequence of compilation to build and flash the atmega2560.

Requirements for this
* Need environment path defined to avr-gcc and avr-objectcopy compiler.
* Need environment path defined to avrdude flasher.
* Need to download make with chocolatey (choco install make)
* Need to link current directory in the make file.

Limitations of this:
* Cant debug and cant run it with atmel ice

The draw back is that you need to link to all the libraries and specify the path each time you make new project.

The benefit is that you have more control and transparency of what is happening, something that atmel studio lacks completely. THere is also less clutter with invisible folders and stuff that you get in atmel studio and as well as being able to see what is happening in the folder. No hidden files.
