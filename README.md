# MAX32620FTHR-Arduino Repository

This repository shall provide a bunch of example sketches for Arduino IDE to be used with MAX32620FTHR.

The MAX32620FTHR board is a rapid development platform designed to help engineers quickly implement 
battery-optimized solutions with the MAX32620 Arm® Cortex®-M4 microcontroller with FPU. The board also 
includes the MAX77650 ultra-low power PMIC and MAX17055 fuel gauge to provide efficient power conversion 
and battery management with minimal board space. The form factor is a small 0.9in x 2.0in dual-row header 
footprint that is compatible with breadboards and off-the-shelf peripheral expansion boards. In addition to 
the dual-row headers, there are also two 12-pin Pmod™-compatible socket connectors for more expansion 
options. Also on board are common user-interface peripherals including two RGB indicator LEDs and two 
pushbuttons. These provide a power-optimized flexible platform for quick proofs-of-concept and early 
software development to enhance time to market.

# Examples 
## Prerequisites
If you use the MAX32620FTHR board and want to utilize the analog based functions like charger, battery and system 
current and voltage read-outs, you have to modify your board by deploying R15 with 0 Ohm to route AMUX output 
from MAX77650 to the AIN of MAX32620.

## MAX32620FTHR_complete_board-init
This code shows a complete PMIC initialization example. It handles the PMIC output voltages, LEDs and all
other stuff on the board which has to be set properly to use it in a real world application.

## MAX32620FTHR_interrupts
This example is to demonstrate the interrupt capabilities of the Maxim BSP because there're some minor differences
compared to the standard Arduino interrupt setup.

## MAX32620FTHR_PMIC_analog_multiplexer
The analog multiplexer in the MAX77650 is able to measure all relevant values like board voltages and currents. This
is to demonstrate how it works. To use this example one have to populate the resistor R15 with 0 ohm on the board. 
This connects the analog multiplexer output from the MAX77650 to analog input AIN3 of the MAX32620. 

## MAX32620FTHR_PMIC_Charge-LED
In this example the PMIC LEDs are used to show the recent state of the PMIC-Li+-charger. If you connect a battery,
please be aware that you have to set the proper battery-values to not destroy anything! If the battery is fully
charged, the green LED will notify about this. If the battery has to be charged and a power supply is present at 
the USB port, the red LED will signal any charging of the battery.

## MAX32620FTHR_PMIC_LED
Here I'm going to show how to configure, set and change the LEDs which are connected to the PMIC. 

## MAX32620FTHR_PMIC_SIMO_Buck_Boost
The PMIC has the ability to have the DC-DC- and LDO-converter outputs to be modified to meet the needs 
of the application. This code is to demonstrate how we can do this. Handle with extreme caution! If you overdue
the output voltages of the regulators you will certainly destroy the board!

## MAX32620FTHR_PowerHold
If you want to connect only a battery to the MAX32620FTHR board and run any application, you have to 
initialize the boards PWR-hold-GPIO to be high. Otherwise the PMIC will shut down the system after few moments.
This example will only work with connected battery and NO USB input.

# Parts used on the board
## MAX32620
DARWIN is a new breed of low-power microcontrollers built to thrive in the rapidly evolving Internet of 
Things (IoT). They are smart, with the biggest memories in their class and a massively scalable memory 
architecture. They run forever, thanks to wearable-grade power technology. They are also tough enough 
to withstand the most advanced cyberattacks. DARWIN microcontrollers are designed to run any 
application imaginable—in places where you would not dream of sending other micro controllers.

Generation U microcontrollers are perfect for wearables and IoT applications that cannot afford to 
compromise power or performance. The MAX32620/MAX32621 feature an Arm® Cortex®-M4 with FPU 
CPU that delivers high-efficiency signal processing, ultra-low power consumption and ease of use.

Flexible power modes, an intelligent PMU, and dynamic clock and power gating optimize performance 
and power consumption for each application. Internal oscillators run at 96MHz for high-performance or 
4MHz to maximize battery life in applications requiring always-on monitoring.

Multiple SPI, UART, I2C, 1-Wire® master, and USB interfaces are provided. The four-input, 10-bit ADC 
with selectable references can monitor external sensors.

All versions provide a hardware AES engine. The MAX32621 is provides a secure trust protection unit 
(TPU) with a modular arithmetic accelerator (MAA) for fast ECDSA, a hardware PRNG entropy generator, 
and a secure boot loader. The MAX32620L provides a reduced 1MB of flash memory.

More resources can be found here:
* https://www.maximintegrated.com/en/products/microcontrollers/MAX32620.html
* https://www.maximintegrated.com/en/products/microcontrollers/MAX32620FTHR.html
* https://github.com/maximintegratedmicros/arduino-max326xx/wiki/MAX32620FTHR
* https://datasheets.maximintegrated.com/en/ds/MAX32620-MAX32621.pdf

## MAX77650
The MAX77650/MAX77651 provide highly-integrated battery charging and power supply solutions for 
low-power wearable applications where size and efficiency are critical. Both devices feature a SIMO 
buck-boost regulator that provides three independently programmable power rails from a single inductor 
to minimize total solution size. A 150mA LDO provides ripple rejection for audio and other noise-sensitive 
applications. A highly configurable linear charger supports a wide range of Li+ battery capacities and includes 
battery temperature monitoring for additional safety (JEITA).
The devices include other features such as current sinks for driving LED indicators and an analog multiplexer 
that switches several internal voltage and current signals to an external node for monitoring with an external 
ADC. A bidirectional I2C interface allows for configuring and checking the status of the devices. An internal 
on/off controller provides a controlled startup sequence for the regulators and provides supervisory functionality 
when the devices are on. Numerous factory programmable options allow the device to be tailored for many 
applications, enabling faster time to market.

More resources can be found here:
* https://www.maximintegrated.com/en/products/power/battery-management/MAX77650.html
* https://www.maximintegrated.com/en/app-notes/index.mvp/id/6428

## MAX17055
The MAX17055 is a low 7μA operating current fuel gauge which implements Maxim ModelGauge™ m5 EZ 
algorithm. ModelGauge m5 EZ makes fuel gauge implementation easy by eliminating battery characterization 
requirements and simplifying host software interaction. The ModelGauge m5 EZ robust algorithm provides 
tolerance against battery diversity for most lithium batteries and applications.

ModelGauge m5 EZ algorithm combines the short-term accuracy and linearity of a coulomb counter with 
the long-term stability of a voltage-based fuel gauge, along with temperature compensation to provide 
industry-leading fuel gauge accuracy. The MAX17055 automatically compensates for cell aging, temperature, 
and discharge rate, and provides accurate state of charge (SOC in %) and remaining capacity in milliampere-hours 
(mAh). As the battery approaches the critical region near empty, the ModelGauge m5 algorithm invokes a special 
error correction mechanism that eliminates any error. It also provides three methods for reporting the age of 
the battery: reduction in capacity, increase in battery resistance, and cycle odometer.

The MAX17055 provides precision measurements of current, voltage, and temperature. Temperature of the 
battery pack is measured using an internal temperature measurement or external thermistor. A 2-wire I²C 
interface provides access to data and control registers. 

More resources can be found here:
* https://www.maximintegrated.com/en/products/power/battery-management/MAX17055.html
* https://datasheets.maximintegrated.com/en/ds/MAX17055.pdf

# Getting Started
## Prerequisites
- installed Adruino IDE (version 1.8.5 or newer)
- installed Maxim Board Support Package for Adruino 
- installed library for MAX77650 and MAX17055

## Installing
Step by step installation for Arduino:
### Installing Maxim Arduino Board Support Package
1. Start Arduino IDE 
2. Go to "File" -> "Preferences"
3. Enter the Maxim Board-Support-Package-URL (https://raw.githubusercontent.com/maximintegratedmicros/arduino-collateral/master/package_maxim_index.json) into the "Additional Board Manager Urls" and click "Okay"
4. Go to Tools -> Board: … -> Boards Manager; a new window opens
5. Type Maxim into the upper search field and look for "Maxim's 32-bit Microcontroller by …"
6. Select the most recent version (1.1.4 recent version) and click "Install"

### Installing libraries
1. Clone the GitHub repo into your library-folder (usually C:\Users\<user>\Documents\Arduino\libraries for Windows systems) or install via install libraies via the library-manager
2. Insert the library into your sketch using #include <MAX77650-Arduino-Library.h>
3. You're ready to use the functions for PMIC and fuel gauge
4. For further details have a look into the wiki section under https://github.com/amperpirat/MAX32620FTHR-Arduino/wiki

# Versioning
We use [SemVer](http://semver.org/) for versioning.

# Authors

* **Ole Dreessen** - *Initial work* - [amperpirat](https://github.com/amperpirat)

# License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

