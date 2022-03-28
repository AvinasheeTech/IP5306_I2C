#include "IP5306_I2C.h"


/*@brief initialize i2c 
  @param sda and scl pin number
*/
IP5306::IP5306(uint8_t sda_pin ,uint8_t scl_pin){
	Wire.begin(sda_pin,scl_pin);

  /*initialize register data*/
	reg_SYS_CTL0_t.reg_byte = i2c_read(IP5306_ADDRESS,SYS_CTL0);
	reg_SYS_CTL1_t.reg_byte = i2c_read(IP5306_ADDRESS,SYS_CTL1);
	reg_SYS_CTL2_t.reg_byte = i2c_read(IP5306_ADDRESS,SYS_CTL2);

	reg_Charger_CTL0_t.reg_byte = i2c_read(IP5306_ADDRESS,Charger_CTL0);
	reg_Charger_CTL1_t.reg_byte = i2c_read(IP5306_ADDRESS,Charger_CTL1);
  reg_Charger_CTL2_t.reg_byte = i2c_read(IP5306_ADDRESS,Charger_CTL2);
  reg_Charger_CTL3_t.reg_byte = i2c_read(IP5306_ADDRESS,Charger_CTL3);

}

/*@brief  write data to register 
  @param  register address to write to,data to be written
          and i2c address of the device
  @retval None
*/
void IP5306::i2c_write(uint8_t slave_address,uint8_t register_address,uint8_t data){

    Wire.beginTransmission(slave_address);
    Wire.write(register_address);
    Wire.write(data);
    Wire.endTransmission();
}

/*@brief  read the register value 
  @param  register address to read,and i2c address of the device
  @retval current register data
*/
uint8_t IP5306::i2c_read(uint8_t slave_address,uint8_t register_address){

	  uint8_t c;
    Wire.beginTransmission(slave_address);
    Wire.write(register_address);
    Wire.endTransmission();

    Wire.requestFrom(slave_address, 1);

    while (Wire.available()) {     // slave may send less than requested
          c = Wire.read();         // receive a byte as character
    }

    return c;
}

/*@brief  select boost mode 
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void IP5306::boost_mode(uint8_t boost_en){
	reg_SYS_CTL0_t.bits.BOOST_ENABLE = boost_en;

	i2c_write(IP5306_ADDRESS,SYS_CTL0,reg_SYS_CTL0_t.reg_byte);
}

/*@brief  select charger mode 
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void IP5306::charger_mode(uint8_t charger_en){
	reg_SYS_CTL0_t.bits.CHARGER_ENABLE = charger_en;

	i2c_write(IP5306_ADDRESS,SYS_CTL0,reg_SYS_CTL0_t.reg_byte);
}

/*@brief  select auto power on once load detected
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void IP5306::power_on_load(uint8_t power_on_en){
	reg_SYS_CTL0_t.bits.POWER_ON_LOAD = power_on_en;

	i2c_write(IP5306_ADDRESS,SYS_CTL0,reg_SYS_CTL0_t.reg_byte);
}

/*@brief  boost o/p normally open function
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void IP5306::boost_output(uint8_t output_val){
	reg_SYS_CTL0_t.bits.SET_BOOST_OUTPUT_ENABLE = output_val;

	i2c_write(IP5306_ADDRESS,SYS_CTL0,reg_SYS_CTL0_t.reg_byte);
}

/*@brief  eneter shutdown mode using button
  @param  enable or disable bit
  @retval None
  @note   Default value - disable
*/
void IP5306::button_shutdown(uint8_t shutdown_val){
	reg_SYS_CTL0_t.bits.BUTTON_SHUTDOWN = shutdown_val;

	i2c_write(IP5306_ADDRESS,SYS_CTL0,reg_SYS_CTL0_t.reg_byte);
}

/*@brief  boost control mode using button  
  @param  enable or disable bit
  @retval None
  @note   Default value - disable
*/
void IP5306::boost_ctrl_signal(uint8_t press_val){
	reg_SYS_CTL1_t.bits.BOOST_CTRL_SIGNAL_SELECTION = press_val;

	i2c_write(IP5306_ADDRESS,SYS_CTL1,reg_SYS_CTL1_t.reg_byte);
}

/*@brief  flashlight control mode using button
  @param  enable or disable bit
  @retval None
  @note   Default value - disable
*/
void IP5306::flashlight_ctrl_signal(uint8_t press_val){
	reg_SYS_CTL1_t.bits.FLASHLIGHT_CTRL_SIGNAL_SELECTION = press_val;

	i2c_write(IP5306_ADDRESS,SYS_CTL1,reg_SYS_CTL1_t.reg_byte);
}
    
/*@brief  
  @param  enable or disable bit
  @retval None
  @note   Default value - disable
*/              
void IP5306::short_press_boost(uint8_t boost_en){
	reg_SYS_CTL1_t.bits.SHORT_PRESS_BOOST_SWITCH_ENABLE = boost_en;

	i2c_write(IP5306_ADDRESS,SYS_CTL1,reg_SYS_CTL1_t.reg_byte);
}
           
/*@brief  keep boost mode on after input supply removal
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/       
void IP5306::boost_after_vin(uint8_t val){
	reg_SYS_CTL1_t.bits.BOOST_AFTER_VIN = val;

	i2c_write(IP5306_ADDRESS,SYS_CTL1,reg_SYS_CTL1_t.reg_byte);
}

/*@brief  shutdown if battery voltage raches 3V
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/         
void IP5306::low_battery_shutdown(uint8_t shutdown_en){
	reg_SYS_CTL1_t.bits.LOW_BATTERY_SHUTDOWN_ENABLE = shutdown_en;

	i2c_write(IP5306_ADDRESS,SYS_CTL1,reg_SYS_CTL1_t.reg_byte);
}

/*@brief  set long press timing
  @param  long press time value - 0 for 2s , 1 for 3s
  @retval None
  @note   Default value - disable
*/
void IP5306::set_long_press_time(uint8_t press_time_val){
	reg_SYS_CTL2_t.bits.LONG_PRESS_TIME = press_time_val;

	i2c_write(IP5306_ADDRESS,SYS_CTL2,reg_SYS_CTL2_t.reg_byte);
}

/*@brief  set light load shutdown timing
  @param  shutdown time value - 0 for 8s, 1 for 32s, 2 for 16s and 3 for 64s
  @retval None
  @note   Default value - disable
*/
void IP5306::set_light_load_shutdown_time(uint8_t shutdown_time){
  reg_SYS_CTL2_t.bits.LIGHT_LOAD_SHUTDOWN_TIME = shutdown_time;

  i2c_write(IP5306_ADDRESS,SYS_CTL2,reg_SYS_CTL2_t.reg_byte);
}

/*@brief  set charging cutoff voltage range for battery 
  @param  voltage range value - 0 for 4.14/4.26/4.305/4.35  V
                                1 for 4.17/4.275/4.32/4.365 V
                                2 for 4.185/4.29/4.335/4.38 V
                                3 for 4.2/4.305/4.35/4.395  V
  @retval None
  @note   Default value - 2
*/
void IP5306::set_charging_stop_voltage(uint8_t voltage_val){
	reg_Charger_CTL0_t.bits.CHARGING_FULL_STOP_VOLTAGE = voltage_val;

	i2c_write(IP5306_ADDRESS,Charger_CTL0,reg_Charger_CTL0_t.reg_byte);
}

/*@brief  set charging complete current detection
  @param  current value - 3 : 600mA
                          2 : 500mA
                          1 : 400mA
                          0 : 200mA

  @retval None
  @note   Default value - 1
*/
void IP5306::end_charge_current(uint8_t current_val){
	reg_Charger_CTL1_t.bits.END_CHARGE_CURRENT_DETECTION = current_val;

	i2c_write(IP5306_ADDRESS,Charger_CTL1,reg_Charger_CTL1_t.reg_byte);
}

/*@brief  set voltage Vout for charging
  @param  voltage value - 111:4.8
                          110:4.75
                          101:4.7
                          100:4.65
                          011:4.6
                          010:4.55
                          001:4.5
                          000:4.45
  @retval None
  @note   Default value - 101
*/
void IP5306::charger_under_voltage(uint8_t voltage_val){
	reg_Charger_CTL1_t.bits.CHARGE_UNDER_VOLTAGE_LOOP = voltage_val;

	i2c_write(IP5306_ADDRESS,Charger_CTL1,reg_Charger_CTL1_t.reg_byte);
}

/*@brief  set battery voltage
  @param  voltage value - 00:4.2
                          01:4.3
                          02:4.35
                          03:4.4
  @retval None
  @note   Default value - 00
*/
void IP5306::set_battery_voltage(uint8_t voltage_val){
	reg_Charger_CTL2_t.bits.BATTERY_VOLTAGE = voltage_val;

	i2c_write(IP5306_ADDRESS,Charger_CTL2,reg_Charger_CTL2_t.reg_byte);
}

/*@brief  set constant voltage charging setting
  @param  voltage value - 11: Pressurized 42mV
                          10: Pressurized 28mV
                          01: Pressurized 14mV
                          00: Not pressurized
  @retval None
  @note   Default value - 01
  @note :4.30V/4.35V/4.4V It is recommended to pressurize 14mV
         4.2V It is recommended to pressurize 28mV
*/
void IP5306::set_voltage_pressure(uint8_t voltage_val){
	reg_Charger_CTL2_t.bits.VOLTAGE_PRESSURE = voltage_val;

	i2c_write(IP5306_ADDRESS,Charger_CTL2,reg_Charger_CTL2_t.reg_byte);
}

/*@brief  set constant current charging setting
  @param  value - 1:VIN end CC Constant current
                  0:BAT end CC Constant current
  @retval None
  @note   Default value - 1
*/
void IP5306::set_cc_loop(uint8_t current_val){
	reg_Charger_CTL3_t.bits.CHARGE_CC_LOOP = current_val;

	i2c_write(IP5306_ADDRESS,Charger_CTL3,reg_Charger_CTL3_t.reg_byte);
}

/*@brief  get current charging status 
  @param  None
  @retval integer representation of charging status(1 - charging is on and 0 if  charging is off)
*/
uint8_t IP5306::check_charging_status(void){
	reg_READ0_t.reg_byte = i2c_read(IP5306_ADDRESS,REG_READ0);

	return reg_READ0_t.bits.CHARGE_ENABLE;
}

/*@brief  get current battery status
  @param  None
  @retval integer representation of battery status(1 - fully charged and 0 if still charging)
*/
uint8_t IP5306::check_battery_status(void){
	reg_READ1_t.reg_byte = i2c_read(IP5306_ADDRESS,REG_READ1);

	return reg_READ1_t.bits.BATTERY_STATUS;
}

/*@brief  get output load level
  @param  None
  @retval integer representation of load status(1 - light load and 0 if heavy load)
*/
uint8_t IP5306::check_load_level(void){
	reg_READ2_t.reg_byte = i2c_read(IP5306_ADDRESS,REG_READ2);

	return reg_READ2_t.bits.LOAD_LEVEL;
}

/*@brief  detect if a short press occurred
  @param  None
  @retval button status
  @note clear this bit after reading by writing 1
*/
uint8_t IP5306::short_press_detect(void){
	reg_READ3_t.reg_byte = i2c_read(IP5306_ADDRESS,REG_READ3);

	return reg_READ3_t.bits.SHORT_PRESS_DETECT;
}

/*@brief  detect if a long press occurred
  @param  None
  @retval button status
  @note clear this bit after reading by writing 1
*/
uint8_t IP5306::long_press_detect(void){
	reg_READ3_t.reg_byte = i2c_read(IP5306_ADDRESS,REG_READ3);

	return reg_READ3_t.bits.LONG_PRESS_DETECT;
}

/*@brief  detect if a double press occurred
  @param  None
  @retval button status
  @note clear this bit after reading by writing 1
*/
uint8_t IP5306::double_press_detect(void){
	reg_READ3_t.reg_byte = i2c_read(IP5306_ADDRESS,REG_READ3);

	return reg_READ3_t.bits.DOUBLE_PRESS_DETECT;
}

