# WPILibPi

A port of WPILib to Raspberry Pi. This project is a work in progress and is not ready for use in any way.

# Disclaimer

**This project cannot be used at competitions. You** ***must*** **use a roboRIO at competition.**

# Roadmap

- Rewrite a bit of the HAL
- Make a PCB that puts all the required hardware on one board
- Figure out a way to get CAN working (then add it to the PCB, not sure which one will come first)
- Write an installer

As you can see, there's quite a bit to do before this is anywhere near ready. Pull requests would be very helpful!

But, there is a small problem with the roadmap. The Raspberry Pi 3 is a $35 single-board-computer with an ARM Cortex-A53, while the NI roboRIO is a $435 industrial-grade embedded systems controller with an Xilinx X-7020 ARM CPU and FPGA hybrid that is build for robotics applications. **There are some things that software emulation may not be able to do**. It's too early in the project to know if software eumlation of things like precise PWM and digital i/o processing is possible.
