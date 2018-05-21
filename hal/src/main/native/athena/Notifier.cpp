/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/Notifier.h"

#include <atomic>
#include <cstdlib>  // For std::atexit()
#include <memory>

#include <support/condition_variable.h>
#include <support/mutex.h>

#include "HAL/Errors.h"
#include "HAL/HAL.h"
#include "HAL/cpp/make_unique.h"
#include "HAL/handles/UnlimitedHandleResource.h"

using namespace hal;

static constexpr int32_t kTimerInterruptNumber = 28;

static wpi::mutex notifierMutex;
//static std::unique_ptr<tAlarm> notifierAlarm;
//static std::unique_ptr<tInterruptManager> notifierManager;
//static uint64_t closestTrigger{UINT64_MAX};

namespace {

struct Notifier {
  uint64_t triggerTime = UINT64_MAX;
  uint64_t triggeredTime = UINT64_MAX;
  bool active = true;
  wpi::mutex mutex;
  wpi::condition_variable cond;
};

}  // namespace

static std::atomic_flag notifierAtexitRegistered{ATOMIC_FLAG_INIT};
static std::atomic_int notifierRefCount{0};

using namespace hal;

class NotifierHandleContainer
    : public UnlimitedHandleResource<HAL_NotifierHandle, Notifier,
                                     HAL_HandleEnum::Notifier> {
 public:
  ~NotifierHandleContainer() {
    ForEach([](HAL_NotifierHandle handle, Notifier* notifier) {
      {
        std::lock_guard<wpi::mutex> lock(notifier->mutex);
        notifier->triggerTime = UINT64_MAX;
        notifier->triggeredTime = 0;
        notifier->active = false;
      }
      notifier->cond.notify_all();  // wake up any waiting threads
    });
  }
};

static NotifierHandleContainer* notifierHandles;

//static void alarmCallback(uint32_t, void*) {
  
//}

//static void cleanupNotifierAtExit() {
//  notifierAlarm = nullptr;
//  notifierManager = nullptr;
//}

namespace hal {
namespace init {
void InitializeNotifier() {
  static NotifierHandleContainer nH;
  notifierHandles = &nH;
}
}  // namespace init
}  // namespace hal

extern "C" {

HAL_NotifierHandle HAL_InitializeNotifier(int32_t* status) {
  return (HAL_NotifierHandle) 0;
}

void HAL_StopNotifier(HAL_NotifierHandle notifierHandle, int32_t* status) {
  
}

void HAL_CleanNotifier(HAL_NotifierHandle notifierHandle, int32_t* status) {
  if (notifierRefCount.fetch_sub(1) == 1) {
    // if this was the last notifier, clean up alarm and manager
    // the notifier can call back into our callback, so don't hold the lock
    // here (the atomic fetch_sub will prevent multiple parallel entries
    // into this function)

    // Cleaning up the manager takes up to a second to complete, so don't do
    // that here. Fix it more permanently in 2019...

    // if (notifierAlarm) notifierAlarm->writeEnable(false, status);
    // if (notifierManager) notifierManager->disable(status);

    // std::lock_guard<wpi::mutex> lock(notifierMutex);
    // notifierAlarm = nullptr;
    // notifierManager = nullptr;
    // closestTrigger = UINT64_MAX;
  }
}

void HAL_UpdateNotifierAlarm(HAL_NotifierHandle notifierHandle,
                             uint64_t triggerTime, int32_t* status) {
  
}

void HAL_CancelNotifierAlarm(HAL_NotifierHandle notifierHandle,
                             int32_t* status) {
  
}

uint64_t HAL_WaitForNotifierAlarm(HAL_NotifierHandle notifierHandle,
                                  int32_t* status) {
  return 0;
}

}  // extern "C"
