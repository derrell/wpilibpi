/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/OSSerialPort.h"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include <chrono>
#include <cstring>
#include <string>

#include "HAL/Errors.h"
#include "HAL/cpp/SerialHelper.h"

static int portHandles[4]{-1, -1, -1, -1};
static std::chrono::milliseconds portTimeouts[4]{
    std::chrono::milliseconds(0), std::chrono::milliseconds(0),
    std::chrono::milliseconds(0), std::chrono::milliseconds(0)};

namespace hal {
namespace init {
void InitializeOSSerialPort() {
  for (int i = 0; i < 4; i++) {
    portHandles[i] = -1;
    portTimeouts[i] = std::chrono::milliseconds(0);
  }
}
}  // namespace init
}  // namespace hal

extern "C" {

void HAL_InitializeOSSerialPort(HAL_SerialPort port, int32_t* status) {
  
}

void HAL_SetOSSerialBaudRate(HAL_SerialPort port, int32_t baud,
                             int32_t* status) {
}

void HAL_SetOSSerialDataBits(HAL_SerialPort port, int32_t bits,
                             int32_t* status) {
  
}

void HAL_SetOSSerialParity(HAL_SerialPort port, int32_t parity,
                           int32_t* status) {
}

void HAL_SetOSSerialStopBits(HAL_SerialPort port, int32_t stopBits,
                             int32_t* status) {
  
}

void HAL_SetOSSerialWriteMode(HAL_SerialPort port, int32_t mode,
                              int32_t* status) {
  // No op (from WPILib source)
}

void HAL_SetOSSerialFlowControl(HAL_SerialPort port, int32_t flow,
                                int32_t* status) {
  // No op (from WPILib source)
}

void HAL_SetOSSerialTimeout(HAL_SerialPort port, double timeout,
                            int32_t* status) {
}

void HAL_EnableOSSerialTermination(HAL_SerialPort port, char terminator,
                                   int32_t* status) {
  // \n is hardcoded for now. Will fix later (from WPILib source)
  // Seems like a VISA only setting, need to check
}

void HAL_DisableOSSerialTermination(HAL_SerialPort port, int32_t* status) {
  // Seems like a VISA only setting, need to check (from WPILib source)
}

void HAL_SetOSSerialReadBufferSize(HAL_SerialPort port, int32_t size,
                                   int32_t* status) {
  // No op (from WPILib source)
}

void HAL_SetOSSerialWriteBufferSize(HAL_SerialPort port, int32_t size,
                                    int32_t* status) {
  // No op (from WPILib source)
}

int32_t HAL_GetOSSerialBytesReceived(HAL_SerialPort port, int32_t* status) {
  return 0;
}

int32_t HAL_ReadOSSerial(HAL_SerialPort port, char* buffer, int32_t count,
                         int32_t* status) {
  return 0;
}

int32_t HAL_WriteOSSerial(HAL_SerialPort port, const char* buffer,
                          int32_t count, int32_t* status) {
  return 0;
}
void HAL_FlushOSSerial(HAL_SerialPort port, int32_t* status) {
  
}
void HAL_ClearOSSerial(HAL_SerialPort port, int32_t* status) {
  
}
void HAL_CloseOSSerial(HAL_SerialPort port, int32_t* status) {
  
}

}  // extern "C"
