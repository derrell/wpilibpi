/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/Relay.h"

#include "DigitalInternal.h"
#include "HAL/handles/IndexedHandleResource.h"
#include "PortsInternal.h"

using namespace hal;

namespace {

struct Relay {
  uint8_t channel;
  bool fwd;
};

}  // namespace

static IndexedHandleResource<HAL_RelayHandle, Relay, kNumRelayChannels,
                             HAL_HandleEnum::Relay>* relayHandles;

// Create a mutex to protect changes to the relay values
static wpi::mutex digitalRelayMutex;

namespace hal {
namespace init {
void InitializeRelay() {
  static IndexedHandleResource<HAL_RelayHandle, Relay, kNumRelayChannels,
                               HAL_HandleEnum::Relay>
      rH;
  relayHandles = &rH;
}
}  // namespace init
}  // namespace hal

extern "C" {

HAL_RelayHandle HAL_InitializeRelayPort(HAL_PortHandle portHandle, HAL_Bool fwd,
                                        int32_t* status) {
  return (HAL_RelayHandle) 0;
}

void HAL_FreeRelayPort(HAL_RelayHandle relayPortHandle) {
  
}

HAL_Bool HAL_CheckRelayChannel(int32_t channel) {
  // roboRIO only has 4 headers, and the FPGA has
  // seperate functions for forward and reverse,
  // instead of seperate channel IDs
  return channel < kNumRelayHeaders && channel >= 0;
}

/**
 * Set the state of a relay.
 * Set the state of a relay output.
 */
void HAL_SetRelay(HAL_RelayHandle relayPortHandle, HAL_Bool on,
                  int32_t* status) {
  
}

/**
 * Get the current state of the relay channel
 */
HAL_Bool HAL_GetRelay(HAL_RelayHandle relayPortHandle, int32_t* status) {
  return false;
}

}  // extern "C"
