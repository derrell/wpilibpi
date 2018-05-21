/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/Compressor.h"

#include "HAL/Errors.h"
#include "HAL/handles/HandlesInternal.h"
#include "PCMInternal.h"
#include "PortsInternal.h"
#include "ctre/PCM.h"

using namespace hal;

namespace hal {
namespace init {
void InitializeCompressor() {}
}  // namespace init
}  // namespace hal

extern "C" {

HAL_CompressorHandle HAL_InitializeCompressor(int32_t module, int32_t* status) {
  // Use status to check for invalid index
  return (HAL_CompressorHandle) 0;
}

HAL_Bool HAL_CheckCompressorModule(int32_t module) {
  return module < kNumPCMModules && module >= 0;
}

HAL_Bool HAL_GetCompressor(HAL_CompressorHandle compressorHandle,
                           int32_t* status) {
  return false;
}

void HAL_SetCompressorClosedLoopControl(HAL_CompressorHandle compressorHandle,
                                        HAL_Bool value, int32_t* status) {
  
}

HAL_Bool HAL_GetCompressorClosedLoopControl(
    HAL_CompressorHandle compressorHandle, int32_t* status) {
  return false;
}

HAL_Bool HAL_GetCompressorPressureSwitch(HAL_CompressorHandle compressorHandle,
                                         int32_t* status) {
  return false; // true for safety?
}

double HAL_GetCompressorCurrent(HAL_CompressorHandle compressorHandle,
                                int32_t* status) {
  return 0.0;
}
HAL_Bool HAL_GetCompressorCurrentTooHighFault(
    HAL_CompressorHandle compressorHandle, int32_t* status) {
  return false;
}

HAL_Bool HAL_GetCompressorCurrentTooHighStickyFault(
    HAL_CompressorHandle compressorHandle, int32_t* status) {
  return false;
}

HAL_Bool HAL_GetCompressorShortedStickyFault(
    HAL_CompressorHandle compressorHandle, int32_t* status) {
  return false;
}

HAL_Bool HAL_GetCompressorShortedFault(HAL_CompressorHandle compressorHandle,
                                       int32_t* status) {
  return false;
}

HAL_Bool HAL_GetCompressorNotConnectedStickyFault(
    HAL_CompressorHandle compressorHandle, int32_t* status) {
  return false;
}

HAL_Bool HAL_GetCompressorNotConnectedFault(
    HAL_CompressorHandle compressorHandle, int32_t* status) {
  return true; 
}

}  // extern "C"
