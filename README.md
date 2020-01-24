# WeMos-D1-mini-DHT11-OLED6448
This project integrates a WeMos branded ESP8266 D1 Mini with the DHT11 sensor and the OLED Shield V1.1.0

I used a Dual Base that allows two units to be easily connected and added the OLED Shield on top of the ESP8266 shield on headers. The DHT11 self-heats by approximately 1.5C so I factored this in when taking readings.

The Temperature and Humidity readings calibrated using a quality thermometer and humidity monitor.

This first version uses the OLED Shield to display the calibrated Celsius and Fahrenheit values along with the uncalibrated Relative Humidity.

The readings are sampled every 6 seconds.

The operation assumes no power constraints.
