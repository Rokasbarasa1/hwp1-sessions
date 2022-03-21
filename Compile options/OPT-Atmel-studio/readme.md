Atmel studio compiling method

This uses a atmel studio to perform compilation and flashing of the atmega2560.

Requirements for this
* Need to add external tools (in tools->external tools) which basicaly run avrdude with some specific options.
* Need to select tool in project properties of JTAG atmel ice

The drawback of this is that atmel studio is a shit ide and youre gonna have an awful time using it.

The benefit is that it doesn't require much setup.