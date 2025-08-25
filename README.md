
yaml:
<br>
```
esphome:
  name: atoms3r-m12
  friendly_name: AtomS3R-M12
    
esp32:
  board: esp32-s3-devkitc-1
  framework:
    type: arduino

external_components:
  - source: github://RikerZhu/ESPHome-M5Unit-Miniscale
    components: [m5_unit_miniscale]
    refresh: always

# Enable logging
logger:

# Enable Home Assistant API
api:
  encryption:
    key: "**********"

ota:
  - platform: esphome
    password: "**********"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Atoms3R-M12 Fallback Hotspot"
    password: "********"

captive_portal:

i2c:
  sda: 2
  scl: 1
  scan: true

sensor:
  - platform: m5_unit_miniscale
    sda: 2
    scl: 1
    address: 0x26
    name: "MiniScale"
```
