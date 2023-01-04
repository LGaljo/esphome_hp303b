#include "esphome.h"
#include "LOLIN_HP303B.h"

static const char *TAGhp = "hp303b";

using namespace esphome;

class HP303BSensor : public PollingComponent {
 public:
  LOLIN_HP303B hp;
  Sensor *temperature_sensor = new Sensor();
  Sensor *pressure_sensor = new Sensor();
  int32_t pressure;
  int32_t temperature;

  HP303BSensor() : PollingComponent(100000) { }

  void setup() override {
    ESP_LOGCONFIG(TAGhp, "Setting up HP303B...");
    hp.begin();
  }

  void dump_config() override {
    ESP_LOGCONFIG(TAGhp, "HP303B:");
    ESP_LOGCONFIG(TAGhp, "  Custom Sensor Active");
  }

  void update() override {
    hp.measurePressureOnce(pressure); // library returns value in in Pa, which equals 1/100 hPa
    hp.measureTempOnce(temperature);

    ESP_LOGD(TAGhp, "Got pressure=%.1f hPa", pressure / 100.0);
    ESP_LOGD(TAGhp, "Got temperature=%.1f °C", temperature);
    temperature_sensor->publish_state(pressure / 100.0); 
    temperature_sensor->publish_state(temperature); 
  }
};
