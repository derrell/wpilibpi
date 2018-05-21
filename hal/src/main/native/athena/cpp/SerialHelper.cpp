/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/cpp/SerialHelper.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

#include <llvm/FileSystem.h>
#include <llvm/StringRef.h>

#include "../visa/visa.h"
#include "HAL/Errors.h"

constexpr const char* OnboardResourceVISA = "ASRL1::INSTR";
constexpr const char* MxpResourceVISA = "ASRL2::INSTR";

constexpr const char* OnboardResourceOS = "/dev/ttyS0";
constexpr const char* MxpResourceOS = "/dev/ttyS1";

namespace hal {

std::string SerialHelper::m_usbNames[2]{"", ""};

wpi::mutex SerialHelper::m_nameMutex;

SerialHelper::SerialHelper() {
  //viOpenDefaultRM(reinterpret_cast<ViSession*>(&m_resourceHandle));
}

std::string SerialHelper::GetVISASerialPortName(HAL_SerialPort port,
                                                int32_t* status) {
  return "";
}

std::string SerialHelper::GetOSSerialPortName(HAL_SerialPort port,
                                              int32_t* status) {
  return "";
}

std::vector<std::string> SerialHelper::GetVISASerialPortList(int32_t* status) {
  std::vector<std::string> retVec;

  return retVec;
}

std::vector<std::string> SerialHelper::GetOSSerialPortList(int32_t* status) {
  std::vector<std::string> retVec;

  return retVec;
}

void SerialHelper::SortHubPathVector() {
  
}

void SerialHelper::CoiteratedSort(
    llvm::SmallVectorImpl<llvm::SmallString<16>>& vec) {
  
}

void SerialHelper::QueryHubPaths(int32_t* status) {
  
}

int32_t SerialHelper::GetIndexForPort(HAL_SerialPort port, int32_t* status) {
  
  return 0;
}

}  // namespace hal
