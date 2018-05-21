/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/Interrupts.h"

#include <memory>

#include <support/SafeThread.h>

#include "DigitalInternal.h"
#include "HAL/Errors.h"
#include "HAL/cpp/make_unique.h"
#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/LimitedHandleResource.h"
#include "PortsInternal.h"

using namespace hal;

namespace {

struct Interrupt {
  //std::unique_ptr<tInterrupt> anInterrupt;
  //std::unique_ptr<tInterruptManager> manager;
  void * anInterrupt;
  void * manager; 
};

// Safe thread to allow callbacks to run on their own thread
class InterruptThread : public wpi::SafeThread {
 public:
  void Main() {
    
  }

  bool m_notify = false;
  HAL_InterruptHandlerFunction m_handler;
  void* m_param;
  uint32_t m_mask;
};

class InterruptThreadOwner : public wpi::SafeThreadOwner<InterruptThread> {
 public:
  void SetFunc(HAL_InterruptHandlerFunction handler, void* param) {
  }

  void Notify(uint32_t mask) {  
  }
};

}  // namespace

/*static void threadedInterruptHandler(uint32_t mask, void* param) {
  static_cast<InterruptThreadOwner*>(param)->Notify(mask);
}*/

static LimitedHandleResource<HAL_InterruptHandle, Interrupt, kNumInterrupts,
                             HAL_HandleEnum::Interrupt>* interruptHandles;

namespace hal {
namespace init {
void InitialzeInterrupts() {
  static LimitedHandleResource<HAL_InterruptHandle, Interrupt, kNumInterrupts,
                               HAL_HandleEnum::Interrupt>
      iH;
  interruptHandles = &iH;
}
}  // namespace init
}  // namespace hal

extern "C" {

HAL_InterruptHandle HAL_InitializeInterrupts(HAL_Bool watcher,
                                             int32_t* status) {
  return (HAL_InterruptHandle) 0;
}

void HAL_CleanInterrupts(HAL_InterruptHandle interruptHandle, int32_t* status) {
}

/**
 * In synchronous mode, wait for the defined interrupt to occur.
 * @param timeout Timeout in seconds
 * @param ignorePrevious If true, ignore interrupts that happened before
 * waitForInterrupt was called.
 * @return The mask of interrupts that fired.
 */
int64_t HAL_WaitForInterrupt(HAL_InterruptHandle interruptHandle,
                             double timeout, HAL_Bool ignorePrevious,
                             int32_t* status) {
  return 0;
}

/**
 * Enable interrupts to occur on this input.
 * Interrupts are disabled when the RequestInterrupt call is made. This gives
 * time to do the setup of the other options before starting to field
 * interrupts.
 */
void HAL_EnableInterrupts(HAL_InterruptHandle interruptHandle,
                          int32_t* status) {
  
}

/**
 * Disable Interrupts without without deallocating structures.
 */
void HAL_DisableInterrupts(HAL_InterruptHandle interruptHandle,
                           int32_t* status) {
  
}

/**
 * Return the timestamp for the rising interrupt that occurred most recently.
 * This is in the same time domain as GetClock().
 * @return Timestamp in seconds since boot.
 */
double HAL_ReadInterruptRisingTimestamp(HAL_InterruptHandle interruptHandle,
                                        int32_t* status) {
  return 0.0;
}

/**
 * Return the timestamp for the falling interrupt that occurred most recently.
 * This is in the same time domain as GetClock().
 * @return Timestamp in seconds since boot.
 */
double HAL_ReadInterruptFallingTimestamp(HAL_InterruptHandle interruptHandle,
                                         int32_t* status) {
  return 0.0;
}

void HAL_RequestInterrupts(HAL_InterruptHandle interruptHandle,
                           HAL_Handle digitalSourceHandle,
                           HAL_AnalogTriggerType analogTriggerType,
                           int32_t* status) {
}

void HAL_AttachInterruptHandler(HAL_InterruptHandle interruptHandle,
                                HAL_InterruptHandlerFunction handler,
                                void* param, int32_t* status) {
}

void HAL_AttachInterruptHandlerThreaded(HAL_InterruptHandle interrupt_handle,
                                        HAL_InterruptHandlerFunction handler,
                                        void* param, int32_t* status) {
  
}

void HAL_SetInterruptUpSourceEdge(HAL_InterruptHandle interruptHandle,
                                  HAL_Bool risingEdge, HAL_Bool fallingEdge,
                                  int32_t* status) {
  
}

}  // extern "C"
