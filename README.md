
# Indica Blinker

Indica is an IOT based LED blinker,whereby using an android app you can turn on and off two LED's independently.


## Demo

![Prototype](documentation/demo.jpg?raw=true "Prototype")
![Android App](documentation/app.png?raw=true "Android AppAndroid App")
## Architecture

- Python (Web end - FLASK)
- C++    (MCU - ARDUINO CORE)
- Java   (Android App - COREJAVA)

## Circuit

Made in proteus consiting of a 3.7v regulator and an ESP-01 board, Supply 9v

![Circuit](documentation/circuit.bmp?raw=true "Circuit")

## Running

- Install the `android app` 
- Power up the board using a 9v battery 
- Toggle the switches to see the board in action

[Deployed webserver on pythonanywhere](https://pythonanywhere.com)


## Notes

Make sure there is a wifi hotspot of 2.5ghz before booting up the device,the hotspot should have:

`Wifi SSID: lasec
Wifi password: lasec@123`

The device would automatically connect to this wifi on startup and start querying details from the main IOT server.
Change the 9v batteries periodically ,expected runtime from a fresh 9v battery is 5mins.

## Contributing

Contributions are always welcome!

Please adhere to this project's `code of conduct` and give credit to the author.

