/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AnalogInternal.h"

#include <atomic>

#include <support/mutex.h>

#include "HAL/AnalogInput.h"
#include "PortsInternal.h"

namespace hal {

wpi::mutex analogRegisterWindowMutex;
//std::unique_ptr<tAI> analogInputSystem;
//std::unique_ptr<tAO> analogOutputSystem;

IndexedHandleResource<HAL_AnalogInputHandle, ::hal::AnalogPort,
                      kNumAnalogInputs, HAL_HandleEnum::AnalogInput>*
    analogInputHandles;

//static int32_t analogNumChannelsToActivate = 0;

static std::atomic<bool> analogSystemInitialized{false};

bool analogSampleRateSet = false;

namespace init {
  void InitializeAnalogInternal() {
    static IndexedHandleResource<HAL_AnalogInputHandle, ::hal::AnalogPort,
                                 kNumAnalogInputs, HAL_HandleEnum::AnalogInput>
        alH;
    analogInputHandles = &alH;
  }
}  // namespace init

/**
 * Initialize the analog System.
 */
void initializeAnalog(int32_t* status) {
  
}

/**
 * Return the number of channels on the module in use.
 *
 * @return Active channels.
 */
int32_t getAnalogNumActiveChannels(int32_t* status) {
  
  return 0;
}

/**
 * Get the number of active channels.
 *
 * This is an internal function to allow the atomic update of both the
 * number of active channels and the sample rate.
 *
 * When the number of channels changes, use the new value.  Otherwise,
 * return the curent value.
 *
 * @return Value to write to the active channels field.
 */
int32_t getAnalogNumChannelsToActivate(int32_t* status) {
  return 0;
}

/**
 * Set the sample rate.
 *
 * This is a global setting for the Athena and effects all channels.
 *
 * @param samplesPerSecond The number of samples per channel per second.
 */
void setAnalogSampleRate(double samplesPerSecond, int32_t* status) {
  
}

/**
 * Set the number of active channels.
 *
 * Store the number of active channels to set.  Don't actually commit to
 * hardware
 * until SetSampleRate().
 *
 * @param channels Number of active channels.
 */
void setAnalogNumChannelsToActivate(int32_t channels) {
  
}

}  // namespace hal
