#pragma once

#include "stm32f4xx.h"

uint32_t dwtDelayInit();

// This Function Provides Delay In Microseconds Using DWT
__STATIC_INLINE void delay_us(volatile uint32_t au32Microseconds) {
    uint32_t au32InitialTicks = DWT->CYCCNT;
    uint32_t au32Ticks = (SystemCoreClock / 1000000);
    au32Microseconds *= au32Ticks;
    while ((DWT->CYCCNT - au32InitialTicks) < au32Microseconds - au32Ticks);
}

// This Function Provides Delay In Milliseconds Using DWT
__STATIC_INLINE void delay_ms(volatile uint32_t au32Milliseconds) {
    uint32_t au32InitialTicks = DWT->CYCCNT;
    uint32_t au32Ticks = (SystemCoreClock / 1000);
    au32Milliseconds *= au32Ticks;
    while ((DWT->CYCCNT - au32InitialTicks) < au32Milliseconds);
}

__STATIC_INLINE uint32_t getSystemTicks() {
    return DWT->CYCCNT;
}

__STATIC_INLINE uint32_t currentMilliSeconds() {
    return (getSystemTicks() / (SystemCoreClock / 1000));
}

__STATIC_INLINE uint64_t currentMicroSeconds() {
    return (getSystemTicks() / (SystemCoreClock / 1000000));
}