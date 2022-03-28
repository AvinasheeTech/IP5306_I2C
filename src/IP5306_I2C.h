/*@brief  library to interact with IP5306 over I2C communication
*/

#ifndef _IP5306_I2C_H_
#define _IP5306_I2C_H_

#include <Wire.h> //I2C library
#include "Arduino.h"
#include <stdint.h> 

/*macros definition*/
#define ENABLE    1
#define DISABLE   0

#define IP5306_ADDRESS   0x75             //7 bit slave address


/******************************************************************
*****************************Registers*****************************
*******************************************************************
*/
#define SYS_CTL0       0x00
#define SYS_CTL1       0x01
#define SYS_CTL2       0x02

#define Charger_CTL0   0x20
#define Charger_CTL1   0x21
#define Charger_CTL2   0x22
#define Charger_CTL3   0x23

#define CHG_DIG_CTL0   0x24

#define REG_READ0      0x70
#define REG_READ1      0x71
#define REG_READ2      0x72
#define REG_READ3      0x77


/******************************************************************
*************************bit definitions***************************
*******************************************************************
*/

/*SYS_CTL0*/
union{
    struct{
     uint8_t BUTTON_SHUTDOWN             : 1;
     uint8_t SET_BOOST_OUTPUT_ENABLE     : 1;
     uint8_t POWER_ON_LOAD               : 1;
     uint8_t RSVD                        : 1;
     uint8_t CHARGER_ENABLE              : 1;
     uint8_t BOOST_ENABLE                : 1;
     uint8_t RSVD2                       : 2;
       
    }bits;

    uint8_t reg_byte;

}reg_SYS_CTL0_t;



/*SYS_CTL1*/
union{
    struct{
       uint8_t LOW_BATTERY_SHUTDOWN_ENABLE          : 1;
       uint8_t RSVD                                 : 1;
       uint8_t BOOST_AFTER_VIN                      : 1;
       uint8_t RSVD2                                : 2;
       uint8_t SHORT_PRESS_BOOST_SWITCH_ENABLE      : 1;
       uint8_t FLASHLIGHT_CTRL_SIGNAL_SELECTION     : 1;
       uint8_t BOOST_CTRL_SIGNAL_SELECTION          : 1;   
    }bits;

    uint8_t reg_byte;

}reg_SYS_CTL1_t;


/*SYS_CTL2*/
union{
    struct{
       uint8_t RSVD                              : 2;
       uint8_t LIGHT_LOAD_SHUTDOWN_TIME          : 2;
       uint8_t LONG_PRESS_TIME                   : 1;
       uint8_t RSVD2                             : 3;  
    }bits;

    uint8_t reg_byte;
}reg_SYS_CTL2_t;


/*SHUTDOWN_TIME_VALUE*/
#define SHUTDOWN_8s                                 0
#define SHUTDOWN_32s                                1
#define SHUTDOWN_16s                                2
#define SHUTDOWN_64s                                3



/*Charger_CTL0*/
union{
     struct{
       uint8_t CHARGING_FULL_STOP_VOLTAGE      : 2;
       uint8_t RSVD                            : 6;
     }bits;

     uint8_t reg_byte;
}reg_Charger_CTL0_t;


/*CUT-OFF VOLTAGE RANGE*/
#define CUT_OFF_VOLTAGE_0                                   0     // 4.14/4.26/4.305/4.35  V
#define CUT_OFF_VOLTAGE_1                                   1     // 4.17/4.275/4.32/4.365 V
#define CUT_OFF_VOLTAGE_2                                   2     // 4.185/4.29/4.335/4.38 V
#define CUT_OFF_VOLTAGE_3                                   3     // 4.2/4.305/4.35/4.395  V



/*Charger_CTL1*/
union{
    struct{
       uint8_t RSVD                             : 2;
       uint8_t CHARGE_UNDER_VOLTAGE_LOOP        : 3;
       uint8_t RSVD2                            : 1;
       uint8_t END_CHARGE_CURRENT_DETECTION     : 2;
    }bits;

    uint8_t reg_byte;
}reg_Charger_CTL1_t;


/*BATTERY STOP CHARGING CURRENT*/
#define CURRENT_200                                 0
#define CURRENT_400                                 1
#define CURRENT_500                                 2
#define CURRENT_600                                 3

/*VOLTAGE SETTING FOR CHARGING*/
#define VOUT_0                                0   //4.45   
#define VOUT_1                                1   //4.5  
#define VOUT_2                                2   //4.55 
#define VOUT_3                                3   //4.6
#define VOUT_4                                4   //4.65
#define VOUT_5                                5   //4.7 
#define VOUT_6                                6   //4.75
#define VOUT_7                                7   //4.8 



/*Charger_CTL2*/
union{
     struct{
       uint8_t  VOLTAGE_PRESSURE              : 2;
       uint8_t  BATTERY_VOLTAGE               : 2;
       uint8_t  RSVD                          : 4;
     }bits;

     uint8_t reg_byte;
}reg_Charger_CTL2_t;

/*Battery Voltage */
#define BATT_VOLTAGE_3                        3  //4.4
#define BATT_VOLTAGE_2                        2  //4.35
#define BATT_VOLTAGE_1                        1  //4.3
#define BATT_VOLTAGE_0                        0  //4.2

/*Voltage Pressure setting*/
#define Pressurized_42                          3 
#define Pressurized_28                          2
#define Pressurized_14                          1
#define Not_pressurized                         0

/*Charger_CTL3*/     
union{
     struct{
       uint8_t  RSVD                          : 5;
       uint8_t  CHARGE_CC_LOOP                : 1;
       uint8_t  RSVD2                         : 2;
     }bits;

     uint8_t reg_byte; 
}reg_Charger_CTL3_t;           


/*CHG_DIG_CTL0*/
union{
     struct{
       uint8_t  VIN_CURRENT                   : 5;
       uint8_t  RSVD                          : 3;
     }bits;

     uint8_t reg_byte;
}reg_CHG_DIG_CTL0_t;


/*REG_READ0*/
union{ 
      struct{
       uint8_t   RSVD                         : 3;
       uint8_t   CHARGE_ENABLE                : 1;
       uint8_t   RSVD2                        : 4;
      }bits;

      uint8_t  reg_byte;
}reg_READ0_t;

/*REG_READ1*/
union{ 
      struct{
       uint8_t   RSVD                          : 3;
       uint8_t   BATTERY_STATUS                : 1;
       uint8_t   RSVD2                         : 4;
      }bits;

      uint8_t  reg_byte;
}reg_READ1_t;


/*REG_READ2*/
union{ 
      struct{
       uint8_t   RSVD                         : 2;
       uint8_t   LOAD_LEVEL                   : 1;
       uint8_t   RSVD2                        : 5;
      }bits;

      uint8_t  reg_byte;
}reg_READ2_t;

/*REG_READ3*/
union{ 
      struct{
       uint8_t   SHORT_PRESS_DETECT           : 1;
       uint8_t   LONG_PRESS_DETECT            : 1;
       uint8_t   DOUBLE_PRESS_DETECT          : 1;
       uint8_t   RSVD                         : 5;
      }bits;

      uint8_t  reg_byte;
}reg_READ3_t;




class IP5306{
           
           
           public:

           	      IP5306(uint8_t sda_pin=21 ,uint8_t scl_pin=22);           //value initialization constructor for i2c pins
           	      

                  /*i2c_functions*/
           	      void i2c_write(uint8_t slave_address,uint8_t register_address,uint8_t data);
           	      uint8_t i2c_read(uint8_t slave_address,uint8_t register_address);

                  /*general functions*/
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

};


#endif
