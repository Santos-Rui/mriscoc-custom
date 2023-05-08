# TODO

- Start end g-code

<br/><br/>
<br/><br/>

# Instructions Boreal Spring 2023

##  Compile

 - Option STM32F10ERE_creality 512k

<br/><br/>


## Base Config 

- Ender3V2-427-BLTUBL-T5-MPC (MPC -> Alternative to PID)

<br/><br/>



## Extra Z Stepepr

### pins_CREALITY_V4.h


- Commentar esta merda, ou não dá
```
(M)// #if HOTENDS > 1 || E_STEPPERS > 1
(M)//   #error "Creality V4 only supports one hotend / E-stepper. Comment out this line to continue."
(M)// #endif
```

- Free pin to have 3 free ones for extra stepper full control
```
(M) #define Z_MIN_PROBE_PIN                   PA7   // BLTouch IN
```

- Define new pins
```
(+) #define E1_ENABLE_PIN                       PB1 //(connect to ground to always enable)
(+) #define E1_STEP_PIN                         PA14 //SWCLK (STEP - pulled low)
(+) #define E1_DIR_PIN                          PA13 //SWIO  (DIR - pulled high)
```

### Configuration.h
```
(+) #define Z2_DRIVER_TYPE  TMC2208_STANDALONE   // Ender Configs - Extra Z
```
<br/><br/>



## Probe Offset 
### Configuration.h

```
(M) #define NOZZLE_TO_PROBE_OFFSET { -44, 3, -4.28 }
```
<br/><br/>



## Jerk
### Configuration.h
```
(M)  #define DEFAULT_XJERK 15.0  // Ender Configs
(M)  #define DEFAULT_YJERK 15.0  // Ender Configs
```
<br/><br/>



## Sound
### Configuration_adv.h
```
(M) //#define SOUND_ON_DEFAULT    // Buzzer/speaker default enabled state
```
<br/><br/>



## Default steps
### Configuration.h
```
(M) //#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 96.6 }  // Ender Configs
```
<br/><br/>



## Temp Sensor
### Configuration.h
```
(M) #define TEMP_SENSOR_0 5  // Volcano thermistor
```
<br/><br/>


## Live Move
### dwin.cpp
```
(M) bool EnableLiveMove = true;
```
<br/><br/>


## Max/Min Positions
### Configuration.h

```
// The size of the printable area
#define X_BED_SIZE 230  // MRiscoC Max usable bed size
#define Y_BED_SIZE 230  // MRiscoC Max usable bed size
```
```
(M)#define X_MAX_POS 249
(M)#define Y_MAX_POS 230  
(M)#define Z_MAX_POS 249 
```
<br/><br/>


 ## Mesh
### Configuration.h

```
(M) #define MESH_INSET 10           
(M) #define GRID_MAX_POINTS_X 7     
```
### Configuration_adv.h
```
#define X_MIN_POS 0  // MRiscoC Stock physical limit
#define Y_MIN_POS 0  // MRiscoC Stock physical limit
(M)#define Z_MIN_POS 0
(M)#define Y_MAX_POS 220  // 
(M)#define Z_MAX_POS 249  // 
```
<br/><br/>

 ## Tramming
### Configuration.h

```
(M)  #define BED_TRAMMING_INSET_LFRB { 10, 10, 10, 10 }    
```

<br/><br/>

## Temps

### Configuration.h

```
(M) #define PROBING_BED_TEMP     60
(M)  #define LEVELING_BED_TEMP     60
```


<br/><br/>

 ## Bed PID
### Configuration.h

```
(M)  #define DEFAULT_bedKp 203.80
(M)  #define DEFAULT_bedKi 39.81
(M)  #define DEFAULT_bedKd 695.64
```


<br/><br/>

 ## HotEnd MPC
### Configuration.h

```
(M)   #define MPC_BLOCK_HEAT_CAPACITY { 16.42 }           // (J/K) Heat block heat capacities.
(M)   #define MPC_SENSOR_RESPONSIVENESS { 0.1312 }         // (K/s per ∆K) Rate of change of sensor temperature from heat block.
(M)   #define MPC_AMBIENT_XFER_COEFF { 0.0842 }           // (W/K) Heat transfer coefficients from heat block to room air with fan off.
(M)   #define MPC_AMBIENT_XFER_COEFF_FAN255 { 0.1027 }  // (W/K) Heat transfer coefficients from heat block to room air with fan on full.
```



<br/><br/>

 ## Stepper Timeout
### Configuration_adv.h

```
#define DEFAULT_STEPPER_DEACTIVE_TIME 900
```

<br/><br/>

 ## Pause
### Configuration_adv.h

```
#define ADVANCED_PAUSE_FEATURE  // MRiscoC Enabled
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         50  // (mm/s) Initial retract feedrate.
  #define PAUSE_PARK_RETRACT_LENGTH            5  // (mm) Initial retract.
                                                  // This short retract is done immediately, before parking the nozzle.
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     20  // (mm/s) Unload filament feedrate. This can be pretty fast.  // MRiscoC Increased filament unload speed
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25  // (mm/s^2) Lower acceleration may allow a faster feedrate.
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      370  // (mm) The length of filament for a complete unload.
                                                  //   For Bowden, the full length of the tube and nozzle.
                                                  //   For direct drive, the full length of the nozzle.
                                                  //   Set to 0 for manual unloading.
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6  // (mm/s) Slow move when starting load.
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0  // (mm) Slow length, to allow time to insert material.
                                                  // 0 to disable start loading and skip to fast load only
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   12  // (mm/s) Load filament feedrate. This can be pretty fast.  // MRiscoC Increased filament load speed
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25  // (mm/s^2) Lower acceleration may allow a faster feedrate.
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     320  // (mm) Load length of filament, from extruder gear to nozzle.
                                                  //   For Bowden, the full length of the tube and nozzle.
                                                  //   For direct drive, the full length of the nozzle.
  //#define ADVANCED_PAUSE_CONTINUOUS_PURGE       // Purge continuously up to the purge length until interrupted.
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3  // (mm/s) Extrude feedrate (after loading). Should be slower than load feedrate.
  #define ADVANCED_PAUSE_PURGE_LENGTH         30  // (mm) Length to extrude after loading.
                                                  //   Set to 0 for manual extrusion.
                                                  //   Filament can be extruded repeatedly from the Filament Change menu
                                                  //   until extrusion is consistent, and to purge old filament.
  #define ADVANCED_PAUSE_RESUME_PRIME          0  // (mm) Extra distance to prime nozzle after returning from park.
  //#define ADVANCED_PAUSE_FANS_PAUSE             // Turn off print-cooling fans while the machine is paused.

                                                  // Filament Unload does a Retract, Delay, and Purge first:
  #define FILAMENT_UNLOAD_PURGE_RETRACT       13  // (mm) Unload initial retract length.
  #define FILAMENT_UNLOAD_PURGE_DELAY       5000  // (ms) Delay for the filament to cool after retract.
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8  // (mm) An unretract is done, then this length is purged.
  #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25  // (mm/s) feedrate to purge before unload

  #define PAUSE_PARK_NOZZLE_TIMEOUT           300 // (seconds) Time limit before the nozzle is turned off for safety.
  #define FILAMENT_CHANGE_ALERT_BEEPS         10  // Number of alert beeps to play when a response is needed.
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT           // Enable for XYZ steppers to stay powered on during filament change.
  //#define FILAMENT_CHANGE_RESUME_ON_INSERT      // Automatically continue / load filament when runout sensor is triggered again.
  //#define PAUSE_REHEAT_FAST_RESUME              // Reduce number of waits by not prompting again post-timeout before continuing.

  #define PARK_HEAD_ON_PAUSE                    // Park the nozzle during pause and filament change.  // MRiscoC Enabled park head when pause command was issued
  //#define HOME_BEFORE_FILAMENT_CHANGE           // If needed, home before parking for filament change

  #define FILAMENT_LOAD_UNLOAD_GCODES           // Add M701/M702 Load/Unload G-codes, plus Load/Unload in the LCD Prepare menu.  // MRiscoC Enabled load/unload Filament G-codes
  //#define FILAMENT_UNLOAD_ALL_EXTRUDERS         // Allow M702 to unload all extruders above a minimum target temp (as set by M302)
#endif
```

