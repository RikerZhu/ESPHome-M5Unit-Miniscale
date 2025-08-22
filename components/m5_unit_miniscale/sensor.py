import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import UNIT_G, ICON_SCALE, CONF_SDA, CONF_SCL

CONF_ADDR = "address"

m5_unit_miniscale_ns = cg.esphome_ns.namespace("m5_unit_miniscale")
M5UnitMiniScale = m5_unit_miniscale_ns.class_(
    "M5UnitMiniScale", cg.Component, sensor.Sensor
)

M5UnitMiniScale = M5UnitMiniScale.method(
    "set_i2c_params", cg.void, [cg.uint8, cg.uint8, cg.uint8]
)


CONFIG_SCHEMA = (
    sensor.sensor_schema(unit_of_measurement=UNIT_G, icon=ICON_SCALE)
    .extend({
        cv.Required(CONF_SDA): cv.int_,
        cv.Required(CONF_SCL): cv.int_,
        cv.Optional(CONF_ADDR, default=0x64): cv.int_,
    })
    .extend(cv.polling_component_schema("1s"))
)

async def to_code(config):
    var = cg.new_Pvariable(config[cv.CONF_ID])
    cg.add(var.set_i2c_params(config[CONF_SDA], config[CONF_SCL], config[CONF_ADDR]))
    await sensor.register_sensor(var, config)

    cg.add_library("Wire", None)
    cg.add_library("https://github.com/m5stack/M5Unit-Miniscale.git", None)