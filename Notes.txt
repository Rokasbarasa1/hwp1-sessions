16000000
115200

C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe

C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avrdude.exe

C:\Program Files (x86)\Arduino\hardware\tools\avr\etc\avrdude.conf

-C"C:\Program Files (x86)\Arduino\hardware\tools\avr\etc\avrdude.conf" 
-p atmega2560 
-c wiring 
-P \\.\COM3 
-b 115200 
-D 
-U flash:w:"$(ProjectDir)Debug\$(TargetName).hex":i