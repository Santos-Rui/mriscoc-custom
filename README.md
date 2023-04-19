# TODO

- Start end g-code

- pid's MPC?

- timeout


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




