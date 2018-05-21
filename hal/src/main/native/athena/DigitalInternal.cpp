/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DigitalInternal.h"

#include <atomic>
#include <thread>

#include <FRC_NetworkCommunication/LoadOut.h>
#include <support/mutex.h>

#include "ConstantsInternal.h"
#include "HAL/AnalogTrigger.h"
#include "HAL/HAL.h"
#include "HAL/Ports.h"
//#include "HAL/cpp/UnsafeDIO.h"
#include "PortsInternal.h"

namespace hal {

//std::unique_ptr<tDIO> digitalSystem;
//std::unique_ptr<tRelay> relaySystem;
//std::unique_ptr<tPWM> pwmSystem;
//std::unique_ptr<tSPI> spiSystem;

// Create a mutex to protect changes to the digital output values
wpi::mutex digitalDIOMutex;

DigitalHandleResource<HAL_DigitalHandle, DigitalPort,
                      kNumDigitalChannels + kNumPWMHeaders>*
    digitalChannelHandles;

namespace init {
void InitializeDigitalInternal() {
  static DigitalHandleResource<HAL_DigitalHandle, DigitalPort,
                               kNumDigitalChannels + kNumPWMHeaders>
      dcH;
  digitalChannelHandles = &dcH;
}
}  // namespace init

namespace detail {
wpi::mutex& UnsafeGetDIOMutex() { return digitalDIOMutex; }
//tDIO* UnsafeGetDigialSystem() { return digitalSystem.get(); }
int32_t ComputeDigitalMask(HAL_DigitalHandle handle, int32_t* status) {
  return 0;
}
}  // namespace detail

/**
 * Initialize the digital system.
 */
void initializeDigital(int32_t* status) {
  
}

/**
 * Map SPI channel numbers from their physical number (27 to 31) to their
 * position in the bit field.
 */
int32_t remapSPIChannel(int32_t channel) { return channel - 26; }

/**
 * Map DIO channel numbers from their physical number (10 to 26) to their
 * position in the bit field.
 */
int32_t remapMXPChannel(int32_t channel) { return channel - 10; }

int32_t remapMXPPWMChannel(int32_t channel) {
  return channel + 10;
}

/**
 * remap the digital source channel and set the module.
 * If it's an analog trigger, determine the module from the high order routing
 * channel else do normal digital input remapping based on channel number
 * (MXP)
 */
bool remapDigitalSource(HAL_Handle digitalSourceHandle,
                        HAL_AnalogTriggerType analogTriggerType,
                        uint8_t& channel, uint8_t& module,
                        bool& analogTrigger) {
  return false;
}

}  // namespace hal
//}
