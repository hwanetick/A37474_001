#ifndef __A37474_CONFIG_H
#define __A37474_CONFIG_H

//-----------------------Specific board selections---------------------


//#define __A37474_000_TEST_GUN
//#define __A37474_001
//#define __A37474_002
#define __A37474_450


// Make sure that at least one board is selected
#ifndef __A37474_450
#ifndef __A37474_001
#ifndef __A37474_002
#error "No Specific Board Selected"
#endif
#endif
#endif


#ifdef __A37474_001
#define __MODE_ETHERNET_INTERFACE
#define __MODE_MODBUS_MONITOR
#define __OPTION_ENABLE_CAN
#define OLL_PIN_CPU_HV_ENABLE_HV_ENABLED        1
#define HEATER_RAMP_TIME                        21000        // 3.5min
#define RAMP_TIME_INTERVAL                      30           // 300ms
#define MAX_PROGRAM_HTR_VOLTAGE                 8000         // 8.0 V
#define MAX_RAMP_HTR_I                          1650         // 1.650 Amps
#define HTR_OC_ABS                              1750         // 1.750 Amps
#define HV_MAX_SET_BOARD_SPEC                   20000        // -20KV
#define HV_MIN_SET_BOARD_SPEC                   0            // 0KV
#define TOP_MAX_SET_BOARD_SPEC                  22000        // 140V
#define TOP_MIN_SET_BOARD_SPEC                  0            // -80V
#define BIAS_OVER_VOLTAGE                       18000        // -180V
#define BIAS_UNDER_VOLTAGE                      14000        // -140V
#define BOARD_DASH_NUMBER                       001
#ifdef  __A37474_450
#error "Multiple boards selected"
#endif
#ifdef  __A37474_002
#error "Multiple boards selected"
#endif
#endif

#ifdef __A37474_002
#define __MODE_ETHERNET_INTERFACE
#define __MODE_MODBUS_MONITOR
#define __OPTION_ENABLE_CAN
#define OLL_PIN_CPU_HV_ENABLE_HV_ENABLED        1
#define HEATER_RAMP_TIME                        21000        // 3.5min
#define RAMP_TIME_INTERVAL                      30           // 300ms
#define MAX_PROGRAM_HTR_VOLTAGE                 8000         // 8.0 V
#define MAX_RAMP_HTR_I                          3750         // 3.750 Amps
#define HTR_OC_ABS                              4500         // 4.500 Amps
#define HV_MAX_SET_BOARD_SPEC                   20000        // -20KV
#define HV_MIN_SET_BOARD_SPEC                   5000         // -5KV
#define TOP_MAX_SET_BOARD_SPEC                  22000        // 140V
#define TOP_MIN_SET_BOARD_SPEC                  0            // -80V
#define BIAS_OVER_VOLTAGE                       18000        // -180V
#define BIAS_UNDER_VOLTAGE                      14000        // -140V
#define BOARD_DASH_NUMBER                       002          // for A37474-002Z
#ifdef  __A37474_450
#error "Multiple boards selected"
#endif
#endif


#ifdef __A37474_450
#define __MODE_ETHERNET_INTERFACE
#define __MODE_MODBUS_MONITOR
#define __OPTION_ENABLE_CAN
#define OLL_PIN_CPU_HV_ENABLE_HV_ENABLED        1
#define HEATER_RAMP_TIME                        21000        // 3.5min
#define RAMP_TIME_INTERVAL                      30           // 300ms
#define MAX_PROGRAM_HTR_VOLTAGE                 8300         // 8.3 V
#define MAX_RAMP_HTR_I                          4700         // 3.750 Amps
#define HTR_OC_ABS                              5500         // 5.500 Amps
#define HV_MAX_SET_BOARD_SPEC                   20000        // -20KV
#define HV_MIN_SET_BOARD_SPEC                   0            // -0KV
#define TOP_MAX_SET_BOARD_SPEC                  40000        // 320V
#define TOP_MIN_SET_BOARD_SPEC                  0            // -80V
#define BIAS_OVER_VOLTAGE                       18000        // -180V
#define BIAS_UNDER_VOLTAGE                      14000        // -140V
#define BOARD_DASH_NUMBER                       450          // for A37474-450Z
#endif


/*----------------------------------------------------------------------*/
/*
  We have a couple of compile time options (selected by board option):
  __MODE_CAN_INTERFACE        
    In this mode, the gun driver is controlled over the CAN interface.
    The descrete digital/analog is not used.


  __MODE_DISCRETE_INTERFACE
    In this mode, the gun driver is controlled by discrete fiber or signal lines.
    The pulse top, high voltage, and heater references are generated from the external interface
  
  
  __MODE_MODBUS_INTERFACE
    In this mode, the gun driver is controlled by discrete fiber or signal lines.
    The pulse top, high voltage, and heater references are generated from the external interface
  
 
  __MODE_ETHERNET_INTERFACE
    In this mode, the gun driver is controlled by discrete fiber or signal lines.
    The pulse top, high voltage, and heater references are generated from the external interface
 

  __OPTION_ENABLE_CAN
    This is only valid for __MODE_DISCRETE_INTERFACE
    This allows the CAN port to be used for test and debugging while operating in one of these modes

 */


// Make sure that at least one mode is selected
#ifndef __MODE_CAN_INTERFACE
#ifndef __MODE_DISCRETE_INTERFACE
#ifndef __MODE_MODBUS_INTERFACE
#ifndef __MODE_ETHERNET_INTERFACE
#error "No reference Source Selected"
#endif
#endif
#endif
#endif


// Create and check compile time options based on configuration above
#ifdef __MODE_CAN_INTERFACE
#define __CAN_CONTROLS
#define __CAN_ENABLED
#define __CAN_REFERENCE
#ifdef __OPTION_ENABLE_CAN
#error "OPTION_ENABLE_CAN not valid modifier to MODE_CAN_INTERFACE"
#endif
#endif


#ifdef __MODE_DISCRETE_INTERFACE
#define __DISCRETE_CONTROLS
#ifdef  __CAN_REFERENCE
#error "Multiple references selected"
#endif
#ifdef  __MODBUS_REFERENCE
#error "Multiple references selected"
#endif
#endif


#ifdef __MODE_MODBUS_INTERFACE
#define __MODBUS_REFERENCE
#define __MODBUS_CONTROLS
#define __MODBUS_MONITOR
#endif

#ifdef __MODE_ETHERNET_INTERFACE
#define __ETHERNET_REFERENCE
#define __ETHERNET_CONTROLS
#endif

#ifdef __OPTION_ENABLE_CAN
#define __CAN_ENABLED
#endif



// -------------- Interface board Configuration ---------------------

#define SELECT_HV_ENABLE_FIBER                0xFF
#define SELECT_HV_ENABLE_DISCRETE             0xFE
#define SELECT_HV_ENABLE_SERIAL               0xFD
#define SELECT_HV_DISABLE                     0xFC


#define SELECT_BEAM_ENABLE_FIBER              0xFF
#define SELECT_BEAM_ENABLE_DISCRETE           0xFB
#define SELECT_BEAM_ENABLE_SERIAL             0xF7
#define SELECT_BEAM_DISABLE                   0xF3


#define SELECT_HV_ILOCK_ENABLE_FIBER          0xFF
#define SELECT_HV_ILOCK_ENABLE_DISCRETE       0xEF
#define SELECT_HV_ILOCK_ENABLE_SERIAL         0xDF
#define SELECT_HV_ILOCK_EXTERNAL_CONTROL      0xCF


#define PULSE_GATE_FIBER                      0xBF
#define PULSE_GATE_DISCRETE                   0xFF


#ifdef A37474_000

#define CONFIG_SELECT_PIN_BYTE               (SELECT_HV_ENABLE_SERIAL & SELECT_BEAM_ENABLE_SERIAL & SELECT_HV_ILOCK_EXTERNAL_CONTROL & PULSE_GATE_DISCRETE)

#endif

// for test
#define CONFIG_SELECT_PIN_BYTE               (SELECT_HV_ENABLE_SERIAL & SELECT_BEAM_ENABLE_SERIAL & SELECT_HV_ILOCK_EXTERNAL_CONTROL & PULSE_GATE_DISCRETE)



// ----------- Timers configurations - ALL Times are in 10ms Units --------------------
#define LED_STARTUP_FLASH_TIME                500      // Time LEDs will flash at startup
#define MAX_HEATER_RAMP_UP_TIME               HEATER_RAMP_TIME    // (3.5min) If the heater does not reach it's programed voltage in this time a fault will be generated
#define HEATER_AUTO_RESTART_TIME              500      // Time delay between a heater fault and when the heater gets restarted
#define HEATER_RAMP_UP_TIME_PERIOD            RAMP_TIME_INTERVAL  // (300ms) During heater ramp up, the heater voltage will be increased every N 10ms (see HEATER_RAMP_UP_INCREMENT)
#define GUN_DRIVER_POWER_SUPPLY_STARTUP_TIME  100      // Wait this long between enabling High Voltage / Pulse Top / Bias and cheching that they are at correct values

#define HEATER_REGULATION_TIME_PERIOD         5        // (50ms) This is the period that the regulation of the heater voltage takes between increments

// System control Parameters
#define MAX_HEATER_CURRENT_DURING_RAMP_UP     MAX_RAMP_HTR_I    //1650     // mA Units.  Whenever the heater voltage is increased (ramp-up or increasing the set point).  The voltage will be current limited by this current
#define MAX_CONVERTER_LOGIC_ADC_READ_ERRORS   20       // If the ADC read exceeds this number a fault will be created
#define MAX_HEATER_START_UP_ATTEMPTS          5        // If the heater ramp up process does not succeed in this many attempts, a fault will be generated that requires power cycle
#define MAX_DAC_TX_ATTEMPTS                   10       // The pic will attempt to write to the Converter Logic DAC this many times before giving up
#define HEATER_RAMP_UP_INCREMENT              10       // mV Units.  When ramping up the heater voltage it is increased by this amount each HEATER_RAMP_UP_TIME_PERIOD

#define HEATER_REGULATION_INCREMENT           50       // (50mV) This is the regulation increment for the heater voltage



#define HEATER_VOLTAGE_CURRENT_LIMITED_FAULT_TIME   500 // 5 Seconds

#define CURRENT_LIMITED_FAULT_HOLDOFF_TIME    10      // 10 seconds at the start of heater warmup before current limit fault is timed
#define FAULT_HOLDOFF_STATE                   22


#ifdef __CAN_CONTROLS
#define HEATER_WARM_UP_TIME 100       //18000     // In Can control mode the heater warm up time is enforced by the ECB
#else
#define HEATER_WARM_UP_TIME 6000     // 1 minute
#endif




// ------------- Converter Logic Board ADC Input Settings ---------------------

// DPARKER figure out how to convert the temperature 
// It is in 2's compliment  This only works for positive temperatures
#define ADC_TEMPERATURE_SENSOR_FIXED_SCALE    1.25
#define ADC_TEMPERATURE_SENSOR_FIXED_OFFSET   0


#define ADC_HV_VMON_FIXED_SCALE               .34722
#define ADC_HV_VMON_FIXED_OFFSET              0
#define ADC_HV_VMON_RELATIVE_TRIP_SCALE       MACRO_DEC_TO_CAL_FACTOR_2(.2)
#define ADC_HV_VMON_RELATIVE_TRIP_FLOOR       1000                     
#define ADC_HV_VMON_RELATIVE_TRIP_COUNT       50                                // 500mS


#define ADC_HV_IMON_FIXED_SCALE               .10419
#define ADC_HV_IMON_FIXED_OFFSET              0


#define ADC_GUN_I_PEAK_FIXED_SCALE            .17313
#define ADC_GUN_I_PEAK_FIXED_OFFSET           0


#define ADC_HTR_V_MON_FIXED_SCALE             .13875
#define ADC_HTR_V_MON_FIXED_OFFSET            0
#define ADC_HTR_V_MON_RELATIVE_TRIP_SCALE     MACRO_DEC_TO_CAL_FACTOR_2(.2)
#define ADC_HTR_V_MON_RELATIVE_TRIP_FLOOR     200                               // Minimum 200mV
#define ADC_HTR_V_MON_RELATIVE_TRIP_COUNT     50                                // 500mS


#define ADC_HTR_I_MON_FIXED_SCALE             .10419
#define ADC_HTR_I_MON_FIXED_OFFSET            0
#define ADC_HTR_I_MON_OVER_LIMIT_ABSOLUTE     HTR_OC_ABS    //1750                              // 1.750 Amps
#define ADC_HTR_I_MON_UNDER_LIMIT_ABSOLUTE    200                               // 0.200 Amps
#define ADC_HTR_I_MON_ABSOLUTE_TRIP_TIME      50                                // 500mS


#define ADC_TOP_V_MON_FIXED_SCALE             .69438
#define ADC_TOP_V_MON_FIXED_OFFSET            0
#define ADC_TOP_V_MON_RELATIVE_TRIP_SCALE     MACRO_DEC_TO_CAL_FACTOR_2(.2)
#define ADC_TOP_V_MON_RELATIVE_TRIP_FLOOR     1000                              // 10 Volts
#define ADC_TOP_V_MON_RELATIVE_TRIP_TIME      50                                // 500mS 


#define ADC_BIAS_V_MON_FIXED_SCALE            .34688
#define ADC_BIAS_V_MON_FIXED_OFFSET           0
#define ADC_BIAS_V_MON_OVER_LIMIT_ABSOLUTE    BIAS_OVER_VOLTAGE
#define ADC_BIAS_V_MON_UNDER_LIMIT_ABSOLUTE   BIAS_UNDER_VOLTAGE
#define ADC_BIAS_V_MON_ABSOLUTE_TRIP_TIME     50                                // 500mS 


#define ADC_24_V_MON_FIXED_SCALE              .41688
#define ADC_24_V_MON_FIXED_OFFSET             0


#define ADC_TEMPERATURE_MON_FIXED_SCALE       .08331
#define ADC_TEMPERATURE_MON_FIXED_OFFSET      20400



// --------------------- Converter Logic Board DAC output Settings -------------- //
#define DAC_HIGH_VOLTAGE_FIXED_SCALE          3.0000
#define DAC_HIGH_VOLTAGE_FIXED_OFFSET         0
#define HIGH_VOLTAGE_MAX_SET_POINT            HV_MAX_SET_BOARD_SPEC
#define HIGH_VOLTAGE_MIN_SET_POINT            HV_MIN_SET_BOARD_SPEC


#define DAC_TOP_VOLTAGE_FIXED_SCALE           1.5000
#define DAC_TOP_VOLTAGE_FIXED_OFFSET          0
//#define TOP_VOLTAGE_MAX_SET_POINT             26000                             // 180V
//#define TOP_VOLTAGE_MAX_SET_POINT             40000                             // 320V
#define TOP_VOLTAGE_MAX_SET_POINT             TOP_MAX_SET_BOARD_SPEC
#define TOP_VOLTAGE_MIN_SET_POINT             TOP_MIN_SET_BOARD_SPEC
//#define TOP_VOLTAGE_MIN_SET_POINT             4000                              // -40V


#define DAC_HEATER_VOLTAGE_FIXED_SCALE        7.5188
#define DAC_HEATER_VOLTAGE_FIXED_OFFSET       0
#define HEATER_VOLTAGE_MAX_SET_POINT          8300                              // 8.3V
#define HEATER_VOLTAGE_MIN_SET_POINT          0                                 // 0V



// ------------- A37474 Internal PIC ADC Input Settings --------------------- //
#define POS_5V_FIXED_SCALE                    .15259                            // 1mV per lsb
#define POS_5V_FIXED_OFFSET                   0
 
#define POS_15V_FIXED_SCALE                   .32328
#define POS_15V_FIXED_OFFSET                  0

#define NEG_15V_FIXED_SCALE                   .32328                           // Change this
#define NEG_15V_FIXED_OFFSET                  0


//----  TCPmodbus ----
#define DEFAULT_REMOTE_IP_ADDRESS                            0x0F46A8C0  // 192.168.70.15
#define DEFAULT_IP_ADDRESS                                   0x6346A8C0  // 192.168.70.99


#endif
