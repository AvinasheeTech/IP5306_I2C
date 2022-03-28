# IP5306_I2C
IP5306 is a fully-integrated multi-function power management SoC. This library is helpful in-order to interact with IP5306 ic over I2C communication. 


select sda and scl pin number based on the board you choose. (Default SDA-21, SCL-22 for esp32).

#define SDA_PIN 21

#define SCL_PIN 22

list of i2c registers available : https://sharvielectronics.com/wp-content/uploads/2021/07/IP5306-I2C-registers.pdf

functions available:

                  void boost_mode(uint8_t boost_en);
                  void charger_mode(uint8_t charger_en);
                  void power_on_load(uint8_t power_on_en);
                  void boost_output(uint8_t output_val);
                  void button_shutdown(uint8_t shutdown_val);

                  void boost_ctrl_signal(uint8_t press_val);
                  void flashlight_ctrl_signal(uint8_t press_val);
                  void short_press_boost(uint8_t boost_en);
                  void boost_after_vin(uint8_t val);
                  void low_battery_shutdown(uint8_t shutdown_en);

                  void set_long_press_time(uint8_t press_time_val);
                  void set_light_load_shutdown_time(uint8_t shutdown_time);

                  void set_charging_stop_voltage(uint8_t voltage_val);
                  void end_charge_current(uint8_t current_val);
                  void charger_under_voltage(uint8_t voltage_val);

                  void set_battery_voltage(uint8_t voltage_val);
                  void set_voltage_pressure(uint8_t voltage_val);
                  void set_cc_loop(uint8_t current_val);

                  uint8_t check_charging_status(void);
                  uint8_t check_battery_status(void);
                  uint8_t check_load_level(void);
                  uint8_t short_press_detect(void);
                  uint8_t long_press_detect(void);
                  uint8_t double_press_detect(void);
