#pragma once
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include <Wire.h>
#include <UNIT_SCALES.h>  // From Arduino library

namespace esphome {
namespace m5_unit_miniscale {

class M5UnitMiniScale : public PollingComponent, public sensor::Sensor {
 public:
  M5UnitMiniScale() = default;

  void set_i2c_params(uint8_t sda, uint8_t scl, uint8_t addr) {
    sda_ = sda;
    scl_ = scl;
    addr_ = addr;
  }

  void setup() override {
    Wire.begin(sda_, scl_);
    scale_.begin(&Wire, sda_, scl_, addr_);
  }

  void update() override {
    publish_state(scale_.getWeight());
  }

 protected:
  uint8_t sda_{0}, scl_{0}, addr_{0x64};
  UNIT_SCALES scale_;
};

}  // namespace m5_unit_miniscale
}  // namespace esphome