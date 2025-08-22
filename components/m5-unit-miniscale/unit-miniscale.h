#pragma once
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include <Wire.h>
#include <UNIT_SCALES.h> // 来自 Arduino 库

namespace esphome {
namespace m5miniscale {

class M5MiniScale : public PollingComponent, public sensor::Sensor {
 public:
  M5MiniScale(uint8_t sda, uint8_t scl, uint8_t addr) 
    : sda_(sda), scl_(scl), addr_(addr) {}

  void setup() override {
    Wire.begin(this->sda_, this->scl_);
    scale_.begin(&Wire, this->sda_, this->scl_, this->addr_);
  }

  void update() override {
    float weight = scale_.getWeight();
    this->publish_state(weight);
  }

 protected:
  UNIT_SCALES scale_;
  uint8_t sda_;
  uint8_t scl_;
  uint8_t addr_;
};

}  // namespace m5miniscale
}  // namespace esphome