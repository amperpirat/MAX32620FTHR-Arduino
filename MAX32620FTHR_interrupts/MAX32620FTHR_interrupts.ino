/**********************************************************************
  Copyright (C) 2018 Maxim Integrated Products, Inc., All Rights Reserved.

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included
  in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.

  Except as contained in this notice, the name of Maxim Integrated
  Products, Inc. shall not be used except as stated in the Maxim Integrated
  Products, Inc. Branding Policy.

  The mere transfer of this software does not imply any licenses
  of trade secrets, proprietary technology, copyrights, patents,
  trademarks, maskwork rights, or any other form of intellectual
  property whatsoever. Maxim Integrated Products, Inc. retains all
  ownership rights.

  Authors:
  Ole Dreessen; ole.dreessen@maximintegrated.com

  Revisions:
  1.0.0       07.11.2018      initial code

  Aim: This code is to demonstrate the Arduino interrupt capabilities using the MAX32620FTHR board.
  Function: While pressing the boot-switch the blue LED will be switched on and light for 1sec. 

  More information can be found here:
  MAX32620FTHR based Arduino sketches: https://github.com/amperpirat/MAX32620FTHR-Arduino
  MAX32620 datasheet: https://datasheets.maximintegrated.com/en/ds/MAX32620-MAX32621.pdf
  MAX32620FTHR datasheet: https://datasheets.maximintegrated.com/en/ds/MAX32620FTHR.pdf

**********************************************************************/

//Includes

//Definitions
#define MAX32620_blue_LED P2_6
#define MAX32620_boot_switch_pin P2_7
#define MAX77650_PHLD P2_2
#define MAX77650_debug true
#define MAX77650_I2C_port 2

//Globals
int LED_last_millies = 0;

void setup(void)
{
  //Configure the Power-Management (Power-Hold)
  pinMode(MAX77650_PHLD, OUTPUT);          //configure pin as output
  digitalWrite(MAX77650_PHLD, HIGH);       //set output to HIGH to hold the power-on state

  //setup GPIO
  pinMode(MAX32620_blue_LED, OUTPUT);      //set GPIO P2_6 (blue LED) to output
  digitalWrite(MAX32620_blue_LED, HIGH);   //set GPIO P2_6 (blue LED) to be high (switch off LED)
  pinMode(MAX32620_boot_switch_pin, INPUT_PULLUP);  //set GPIO P2_7 (boot button) to input

  //setup Interrupts
  attachInterrupt(MAX32620_boot_switch_pin, LED_IRQ_handler, FALLING);    //enable interrupt
}


void LED_IRQ_handler(void) {   //this routine is called whenever the boot-button will be pressed
  digitalWrite(MAX32620_blue_LED, LOW);   //switch the blue LED on
  LED_last_millies = millis();            //save the switch-on-time
}

void loop(void) {
  if (millis() >= LED_last_millies + 1000) {   //execute if the LED-on-time reaches 1sec
    digitalWrite(MAX32620_blue_LED, HIGH);     //switch off the LED
  }
}
