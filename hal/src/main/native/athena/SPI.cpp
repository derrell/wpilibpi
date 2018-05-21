/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/SPI.h"

#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <array>
#include <atomic>
#include <cstring>

#include <llvm/raw_ostream.h>
#include <support/mutex.h>

#include "DigitalInternal.h"
#include "HAL/DIO.h"
#include "HAL/HAL.h"
#include "HAL/cpp/make_unique.h"
#include "HAL/handles/HandlesInternal.h"

using namespace hal;

//static int32_t m_spiCS0Handle{0};
//static int32_t m_spiCS1Handle{0};
//static int32_t m_spiCS2Handle{0};
//static int32_t m_spiCS3Handle{0};
//static int32_t m_spiMXPHandle{0};

//static constexpr int32_t kSpiMaxHandles = 5;

// Indices 0-3 are for onboard CS0-CS2. Index 4 is for MXP.
//static std::array<wpi::mutex, kSpiMaxHandles> spiHandleMutexes;
//static std::array<wpi::mutex, kSpiMaxHandles> spiApiMutexes;
//static std::array<wpi::mutex, kSpiMaxHandles> spiAccumulatorMutexes;

// MXP SPI does not count towards this
//static std::atomic<int32_t> spiPortCount{0};

//static HAL_DigitalHandle digitalHandles[9]{HAL_kInvalidHandle};

//static wpi::mutex spiAutoMutex;
//static int32_t spiAutoPort = kSpiMaxHandles;
//static std::atomic_bool spiAutoRunning{false};
//static std::unique_ptr<tDMAManager> spiAutoDMA;

//static bool SPIInUseByAuto(HAL_SPIPort port) {
  // SPI engine conflicts with any other chip selects on the same SPI device.
  // There are two SPI devices: one for ports 0-3 (onboard), the other for port
  // 4 (MXP).
//  if (!spiAutoRunning) return false;
//  std::lock_guard<wpi::mutex> lock(spiAutoMutex);
//  return (spiAutoPort >= 0 && spiAutoPort <= 3 && port >= 0 && port <= 3) ||
//         (spiAutoPort == 4 && port == 4);
//}

namespace hal {
namespace init {
void InitializeSPI() {}
}  // namespace init
}  // namespace hal

extern "C" {

//static void CommonSPIPortInit(int32_t* status) {
//}

//static void CommonSPIPortFree(void) {
//}

/*
 * Initialize the spi port. Opens the port if necessary and saves the handle.
 * If opening the MXP port, also sets up the channel functions appropriately
 * @param port The number of the port to use. ~~0-3 for Onboard CS0-CS3, 4 for MXP~~
 */
void HAL_InitializeSPI(HAL_SPIPort port, int32_t* status) {
  
}

/**
 * Generic transaction.
 *
 * This is a lower-level interface to the spi hardware giving you more control
 * over each transaction.
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param dataToSend Buffer of data to send as part of the transaction.
 * @param dataReceived Buffer to read data into.
 * @param size Number of bytes to transfer. [0..7]
 * @return Number of bytes transferred, -1 for error
 */
int32_t HAL_TransactionSPI(HAL_SPIPort port, const uint8_t* dataToSend,
                           uint8_t* dataReceived, int32_t size) {
  return 0;
}

/**
 * Execute a write transaction with the device.
 *
 * Write to a device and wait until the transaction is complete.
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param datToSend The data to write to the register on the device.
 * @param sendSize The number of bytes to be written
 * @return The number of bytes written. -1 for an error
 */
int32_t HAL_WriteSPI(HAL_SPIPort port, const uint8_t* dataToSend,
                     int32_t sendSize) {
  return 0;
}

/**
 * Execute a read from the device.
 *
 *   This method does not write any data out to the device
 *   Most spi devices will require a register address to be written before
 *   they begin returning data
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param buffer A pointer to the array of bytes to store the data read from the
 * device.
 * @param count The number of bytes to read in the transaction. [1..7]
 * @return Number of bytes read. -1 for error.
 */
int32_t HAL_ReadSPI(HAL_SPIPort port, uint8_t* buffer, int32_t count) {
  return 0;
}

/**
 * Close the SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 */
void HAL_CloseSPI(HAL_SPIPort port) {
  
}

/**
 * Set the clock speed for the SPI bus.
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param speed The speed in Hz (0-1MHz)
 */
void HAL_SetSPISpeed(HAL_SPIPort port, int32_t speed) {
  
}

/**
 * Set the SPI options
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param msbFirst True to write the MSB first, False for LSB first
 * @param sampleOnTrailing True to sample on the trailing edge, False to sample
 * on the leading edge
 * @param clkIdleHigh True to set the clock to active low, False to set the
 * clock active high
 */
void HAL_SetSPIOpts(HAL_SPIPort port, HAL_Bool msbFirst,
                    HAL_Bool sampleOnTrailing, HAL_Bool clkIdleHigh) {
  
}

/**
 * Set the CS Active high for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 */
void HAL_SetSPIChipSelectActiveHigh(HAL_SPIPort port, int32_t* status) {
  
}

/**
 * Set the CS Active low for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 */
void HAL_SetSPIChipSelectActiveLow(HAL_SPIPort port, int32_t* status) {
  
}

/**
 * Get the stored handle for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @return The stored handle for the SPI port. 0 represents no stored handle.
 */
int32_t HAL_GetSPIHandle(HAL_SPIPort port) {
  return 0;
}

/**
 * Set the stored handle for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for
 * MXP.
 * @param handle The value of the handle for the port.
 */
void HAL_SetSPIHandle(HAL_SPIPort port, int32_t handle) {
  
}

void HAL_InitSPIAuto(HAL_SPIPort port, int32_t bufferSize, int32_t* status) {
  
}

void HAL_FreeSPIAuto(HAL_SPIPort port, int32_t* status) {
  
}

void HAL_StartSPIAutoRate(HAL_SPIPort port, double period, int32_t* status) {
  
}

void HAL_StartSPIAutoTrigger(HAL_SPIPort port, HAL_Handle digitalSourceHandle,
                             HAL_AnalogTriggerType analogTriggerType,
                             HAL_Bool triggerRising, HAL_Bool triggerFalling,
                             int32_t* status) {
}

void HAL_StopSPIAuto(HAL_SPIPort port, int32_t* status) {
  
}

void HAL_SetSPIAutoTransmitData(HAL_SPIPort port, const uint8_t* dataToSend,
                                int32_t dataSize, int32_t zeroSize,
                                int32_t* status) {

}

void HAL_ForceSPIAutoRead(HAL_SPIPort port, int32_t* status) {
  
}

int32_t HAL_ReadSPIAutoReceivedData(HAL_SPIPort port, uint8_t* buffer,
                                    int32_t numToRead, double timeout,
                                    int32_t* status) {
  return 0; 
}

int32_t HAL_GetSPIAutoDroppedCount(HAL_SPIPort port, int32_t* status) {
  return 0;
}

}  // extern "C"
