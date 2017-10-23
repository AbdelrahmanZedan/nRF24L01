# nRF24L01 module (Arduino)
Delivering a 2 ready-made functions (one for transmitting and the other for receiving) for nRF24L01 2.4GHZ module to establish a bi-directional wireless communication between any two Arduino boards.
*******************************************************************************
# Overview
- this module is a transceiver (the same board could send and receive simultaneously).
- it uses SPI protocol to communicate with any microcontroller in our case the MC will be Arduino.
- to keep the module able to excute the Arduino commands, the nRF module pins must be connected to the SPI pins of the Arduino.
- each distribution of arduino has a different SPI pins, so you must know them first.
- the SPI pins are: MOSI, MISO and SCK.
- the MISO of the nRF is connected to the MOSI of Arduino and vice versa.
- finally that module is very sensitive to noise, to avoid any noise you must solder a 10uF Capacitor.
  close to the power terminals of the module (the VCC and the GND).
- you must download the [RF24](https://github.com/maniacbug/RF24) library and add its files to the libraries folders of Arduino.
*******************************************************************************
# Pin Connections
### you should use this [image](https://img.banggood.com/images/upload/2012/lidanpo/SKU082436z.jpg) to know the numbers of the nRF module pins.
- **Module --- Arduino**
- pin 1  --- GND
- Pin 2  --- 3.3V
- Pin 3  --- D9
- Pin 4  --- D10
- Pin 5  --- D13
- Pin 6  --- D11
- Pin 7  --- D12
- Pin 8  --- nothing(left free)
*******************************************************************************
# Getting Started
-- you don't have to do any thing only copy the 2 functions on my code to any project and enjoy your wireless communication
-- you could send and receive integers or chars

# Contact me
abdelrahman1zedan@gmail.com
