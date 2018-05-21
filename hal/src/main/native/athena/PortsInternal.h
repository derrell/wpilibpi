/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <stdint.h>

namespace hal {

constexpr int32_t kNumAccumulators = 0;
constexpr int32_t kNumAnalogTriggers = 0;
constexpr int32_t kNumAnalogInputs = 8;
constexpr int32_t kNumAnalogOutputs = 4;
constexpr int32_t kNumCounters = 0;
constexpr int32_t kNumDigitalHeaders = 10;
constexpr int32_t kNumDigitalMXPChannels = 16;
constexpr int32_t kNumDigitalSPIPortChannels = 5;
constexpr int32_t kNumPWMHeaders = 20;
constexpr int32_t kNumDigitalChannels =
    kNumDigitalHeaders + kNumDigitalMXPChannels + kNumDigitalSPIPortChannels;
constexpr int32_t kNumPWMChannels = 0 + kNumPWMHeaders;
constexpr int32_t kNumDigitalPWMOutputs = 0 + 10;
constexpr int32_t kNumEncoders = 4;
constexpr int32_t kNumInterrupts = 0;
constexpr int32_t kNumRelayChannels = 8;
constexpr int32_t kNumRelayHeaders = 4;
constexpr int32_t kNumPCMModules = 63;
constexpr int32_t kNumSolenoidChannels = 8;
constexpr int32_t kNumPDPModules = 63;
constexpr int32_t kNumPDPChannels = 16;

}  // namespace hal
