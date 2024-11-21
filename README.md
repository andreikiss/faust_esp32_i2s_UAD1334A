# faust_esp32_i2s_UAD1334A
Get the UDA1334a i2s DAC working with the new i2s implementation on esp idf

So the problem is that the i2s driver was updated, and now none of the examples that I wanted to try work out anymore

Stuff like Mozzi synth - https://github.com/sensorium/Mozzi/issues/261 , 

Starting point was this :
faust2esp32 - [Link to initial tutorial](https://faustdoc.grame.fr/tutorials/esp32/) 


Changes are then explained in the API reference - 
![i2s_statemachine](https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32/_images/i2s_state_machine.png "new statemachine")

And more info about it here - [i2s API](https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32/api-reference/peripherals/i2s.html)

Basically, before you just needed to define the channel and then the pinout. Now you need like 3 structures. 

The handler, the channel config and the the i2s type - std in my case with UDA1334a
Since I am using a simple esp32devkit_c and a separate UDA1334a, none of the examples I found online work out of the box. :(

Actually seen how to use the proper configuration with this i2s DAC

Here - [Link to a glorious repo](https://github.com/schreibfaul1/ESP32-audioI2S/blob/83a9370373924b5b099962de2d40e702ce1754e0/src/Audio.cpp#L187) 


