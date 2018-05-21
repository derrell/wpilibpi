/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/Encoder.h"

#include "EncoderInternal.h"
#include "HAL/Counter.h"
#include "HAL/Errors.h"
#include "HAL/handles/LimitedClassedHandleResource.h"
#include "PortsInternal.h"

using namespace hal;

Encoder::Encoder(HAL_Handle digitalSourceHandleA,
                 HAL_AnalogTriggerType analogTriggerTypeA,
                 HAL_Handle digitalSourceHandleB,
                 HAL_AnalogTriggerType analogTriggerTypeB,
                 bool reverseDirection, HAL_EncoderEncodingType encodingType,
                 int32_t* status) {

}

void Encoder::SetupCounter(HAL_Handle digitalSourceHandleA,
                           HAL_AnalogTriggerType analogTriggerTypeA,
                           HAL_Handle digitalSourceHandleB,
                           HAL_AnalogTriggerType analogTriggerTypeB,
                           bool reverseDirection,
                           HAL_EncoderEncodingType encodingType,
                           int32_t* status) {
}

Encoder::~Encoder() {
  
}

// CounterBase interface
int32_t Encoder::Get(int32_t* status) const {
  return 0;
}

int32_t Encoder::GetRaw(int32_t* status) const {
  return 0;
}

int32_t Encoder::GetEncodingScale(int32_t* status) const {
  return 0;
}

void Encoder::Reset(int32_t* status) {
  
}

double Encoder::GetPeriod(int32_t* status) const {
  return 0.0;
}

void Encoder::SetMaxPeriod(double maxPeriod, int32_t* status) {

}

bool Encoder::GetStopped(int32_t* status) const {
  return false;
}

bool Encoder::GetDirection(int32_t* status) const {
  return false;
}

double Encoder::GetDistance(int32_t* status) const {
  return 0.0;
}

double Encoder::GetRate(int32_t* status) const {
  return 0.0;
}

void Encoder::SetMinRate(double minRate, int32_t* status) {
  
}

void Encoder::SetDistancePerPulse(double distancePerPulse, int32_t* status) {
  
}

void Encoder::SetReverseDirection(bool reverseDirection, int32_t* status) {
  
}

void Encoder::SetSamplesToAverage(int32_t samplesToAverage, int32_t* status) {
  
}

int32_t Encoder::GetSamplesToAverage(int32_t* status) const {
  return 0;
}

void Encoder::SetIndexSource(HAL_Handle digitalSourceHandle,
                             HAL_AnalogTriggerType analogTriggerType,
                             HAL_EncoderIndexingType type, int32_t* status) {
  
}

double Encoder::DecodingScaleFactor() const {
  switch (m_encodingType) {
    case HAL_Encoder_k1X:
      return 1.0;
    case HAL_Encoder_k2X:
      return 0.5;
    case HAL_Encoder_k4X:
      return 0.25;
    default:
      return 0.0;
  }
}

/*static LimitedClassedHandleResource<HAL_EncoderHandle, Encoder,
                                    kNumEncoders + kNumCounters,
                                    HAL_HandleEnum::Encoder>* encoderHandles;
*/
namespace hal {
namespace init {
void InitializeEncoder() {
  /*
  static LimitedClassedHandleResource<HAL_EncoderHandle, Encoder,
                                      kNumEncoders + kNumCounters,
                                      HAL_HandleEnum::Encoder>
      eH;
  encoderHandles = &eH;*/
}
}  // namespace init
}  // namespace hal

extern "C" {
HAL_EncoderHandle HAL_InitializeEncoder(
    HAL_Handle digitalSourceHandleA, HAL_AnalogTriggerType analogTriggerTypeA,
    HAL_Handle digitalSourceHandleB, HAL_AnalogTriggerType analogTriggerTypeB,
    HAL_Bool reverseDirection, HAL_EncoderEncodingType encodingType,
    int32_t* status) {
  return (HAL_EncoderHandle) 0;
}

void HAL_FreeEncoder(HAL_EncoderHandle encoderHandle, int32_t* status) {
  
}

int32_t HAL_GetEncoder(HAL_EncoderHandle encoderHandle, int32_t* status) {
  return 0;
}

int32_t HAL_GetEncoderRaw(HAL_EncoderHandle encoderHandle, int32_t* status) {
  return 0;
}

int32_t HAL_GetEncoderEncodingScale(HAL_EncoderHandle encoderHandle,
                                    int32_t* status) {
  return 0;
}

void HAL_ResetEncoder(HAL_EncoderHandle encoderHandle, int32_t* status) {
  
}

double HAL_GetEncoderPeriod(HAL_EncoderHandle encoderHandle, int32_t* status) {
  return 0.0;
}

void HAL_SetEncoderMaxPeriod(HAL_EncoderHandle encoderHandle, double maxPeriod,
                             int32_t* status) {
}

HAL_Bool HAL_GetEncoderStopped(HAL_EncoderHandle encoderHandle,
                               int32_t* status) {
  return true;
}

HAL_Bool HAL_GetEncoderDirection(HAL_EncoderHandle encoderHandle,
                                 int32_t* status) {
  return false;
}

double HAL_GetEncoderDistance(HAL_EncoderHandle encoderHandle,
                              int32_t* status) {
  return 0.0;
}

double HAL_GetEncoderRate(HAL_EncoderHandle encoderHandle, int32_t* status) {
  return 0.0;
}

void HAL_SetEncoderMinRate(HAL_EncoderHandle encoderHandle, double minRate,
                           int32_t* status) {
  
}

void HAL_SetEncoderDistancePerPulse(HAL_EncoderHandle encoderHandle,
                                    double distancePerPulse, int32_t* status) {
}

void HAL_SetEncoderReverseDirection(HAL_EncoderHandle encoderHandle,
                                    HAL_Bool reverseDirection,
                                    int32_t* status) {
}

void HAL_SetEncoderSamplesToAverage(HAL_EncoderHandle encoderHandle,
                                    int32_t samplesToAverage, int32_t* status) {
}

int32_t HAL_GetEncoderSamplesToAverage(HAL_EncoderHandle encoderHandle,
                                       int32_t* status) {
  return 0;
}

double HAL_GetEncoderDecodingScaleFactor(HAL_EncoderHandle encoderHandle,
                                         int32_t* status) {
  return 0.0;
}

double HAL_GetEncoderDistancePerPulse(HAL_EncoderHandle encoderHandle,
                                      int32_t* status) {
  return 0.0;
}

HAL_EncoderEncodingType HAL_GetEncoderEncodingType(
    HAL_EncoderHandle encoderHandle, int32_t* status) {
  return (HAL_EncoderEncodingType) 0;
}

void HAL_SetEncoderIndexSource(HAL_EncoderHandle encoderHandle,
                               HAL_Handle digitalSourceHandle,
                               HAL_AnalogTriggerType analogTriggerType,
                               HAL_EncoderIndexingType type, int32_t* status) {
}

int32_t HAL_GetEncoderFPGAIndex(HAL_EncoderHandle encoderHandle,
                                int32_t* status) {
  return 0;
}

}  // extern "C"
