/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/Solenoid.h"

#include <FRC_NetworkCommunication/LoadOut.h>

#include "HAL/Errors.h"
#include "HAL/Ports.h"
#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/IndexedHandleResource.h"
#include "PCMInternal.h"
#include "PortsInternal.h"
#include "ctre/PCM.h"

namespace {

struct Solenoid {
  uint8_t module;
  uint8_t channel;
};

}  // namespace

using namespace hal;

static IndexedHandleResource<HAL_SolenoidHandle, Solenoid,
                             kNumPCMModules * kNumSolenoidChannels,
                             HAL_HandleEnum::Solenoid>* solenoidHandles;

namespace hal {
namespace init {
void InitializeSolenoid() {
  static IndexedHandleResource<HAL_SolenoidHandle, Solenoid,
                               kNumPCMModules * kNumSolenoidChannels,
                               HAL_HandleEnum::Solenoid>
      sH;
  solenoidHandles = &sH;
}
}  // namespace init
}  // namespace hal

extern "C" {

HAL_SolenoidHandle HAL_InitializeSolenoidPort(HAL_PortHandle portHandle,
                                              int32_t* status) {
  return (HAL_SolenoidHandle) 0;
}

void HAL_FreeSolenoidPort(HAL_SolenoidHandle solenoidPortHandle) {
  
}

HAL_Bool HAL_CheckSolenoidModule(int32_t module) {
  return false; 
}

HAL_Bool HAL_CheckSolenoidChannel(int32_t channel) {
  return false;
}

HAL_Bool HAL_GetSolenoid(HAL_SolenoidHandle solenoidPortHandle,
                         int32_t* status) {
  return false;
}

int32_t HAL_GetAllSolenoids(int32_t module, int32_t* status) {
  return 0;
}

void HAL_SetSolenoid(HAL_SolenoidHandle solenoidPortHandle, HAL_Bool value,
                     int32_t* status) {
  
}

void HAL_SetAllSolenoids(int32_t module, int32_t state, int32_t* status) {
  
}

int32_t HAL_GetPCMSolenoidBlackList(int32_t module, int32_t* status) {
  return 0;
}

HAL_Bool HAL_GetPCMSolenoidVoltageStickyFault(int32_t module, int32_t* status) {
  return false;
}

HAL_Bool HAL_GetPCMSolenoidVoltageFault(int32_t module, int32_t* status) {
  return false;
}

void HAL_ClearAllPCMStickyFaults(int32_t module, int32_t* status) {
  
}

void HAL_SetOneShotDuration(HAL_SolenoidHandle solenoidPortHandle,
                            int32_t durMS, int32_t* status) {
  
}

void HAL_FireOneShot(HAL_SolenoidHandle solenoidPortHandle, int32_t* status) {
  
}
}  // extern "C"
