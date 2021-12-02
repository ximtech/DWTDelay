# DWTDelay
STM32 LL(Low Layer) delay library.\
By tracking the clock cycles, an accurate time delay can be generated by the given operating frequency of the CPU.

### Features
- Ultra lightweight
- Easy to use
- No HAL dependency

### Trade-offs
- Only STM32F4 supported at this time

### Add as CPM project dependency
How to add CPM to the project, check the [link](https://github.com/cpm-cmake/CPM.cmake)
```cmake
# For Clion STM32 plugin generated Cmake add
CPMAddPackage(
        NAME DWTDelay
        GITHUB_REPOSITORY ximtech/DWTDelay
        GIT_TAG origin/main)

include_directories(${DWT_DELAY_DIRECTORY}) # add directory to project
file(GLOB_RECURSE SOURCES ${DWT_DELAY_SOURCES}) # add source files
```

### Usage
```C
uint32_t isStarted = dwtDelayInit();// 0 - clock cycle counter started, 1 - clock cycle counter not started

delay_us(10);   // microseconds delay
delay_ms(100); // milliseconds delay

uint32_t ticks = getSystemTicks(); // system tick from start

uint32 millisMs = currentMilliSeconds(); // milliseconds from MCU start
uint32 millisUs = currentMicroSeconds(); // microseconds from MCU start
```
