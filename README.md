# esphome_hp303b
An ESPHome custom sensor component for the HP303B barometric pressure sensor.

An example of how to use this file is below:

But first move the hp303b.h file to the esphome folder in HA.

```yaml
esphome:
  name: esp-environment
  libraries:
    - Wire
    - SPI
    - "epshome=https://github.com/wemos/LOLIN_HP303B_Library.git"
  includes:
    - hp303b.h

esp8266:
  board: d1_mini_pro

# Here is other config for esphome

sensor:
  - platform: custom
    lambda: |-
      auto my_sensor = new HP303BSensor(20000);
      App.register_component(my_sensor);
      return {my_sensor->temperature_sensor, my_sensor->pressure_sensor};
    sensors:
    - name: "Temperature 2"
      unit_of_measurement: °C
      accuracy_decimals: 2
    - name: "Barometric Pressure"
      icon: "mdi:gauge"
      unit_of_measurement: hPa
      accuracy_decimals: 2

```
