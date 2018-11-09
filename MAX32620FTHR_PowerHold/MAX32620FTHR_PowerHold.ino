/**********************************************************************
* Copyright (C) 2017 Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
* 
* Authors: 
* Ole Dreessen; ole.dreessen@maximintegrated.com
* 
* Revisions:
* 1.0.0       13.03.2018      initial code
* 
* 
* 
* Aim: If you want to connect only a battery to the MAX32620FTHR board and 
* run any application, you have to initialize the boards PWR-hold-GPIO to 
* be high. Otherwise the PMIC will shut down the system after few moments.
* This example will only work with connected battery and NO USB input!
* 
* Function: 
* Press Power-On-Button
*           v
* configure the MAX77650
*           v
* Do some Application stuff
*           v
*   Goto Power-Off state        
* 
* 
**********************************************************************/

//Pin Definitions
#define MAX32620_Power_hold 18   //µC Pin 18 -> connected to MAX77650 power hold input pin (A1)

// Includes
#include <Wire.h>
#include <MAX77650-Arduino-Library.h>

// Globals
int i=0;

void setup(void)
{
  MAX77650_init();
  pinMode(MAX32620_Power_hold, OUTPUT);          //configure pin as output
  digitalWrite(MAX32620_Power_hold, HIGH);       //set output to HIGH to hold the power-on state

  // Prepare the PMIC LEDs
  MAX77650_setLED_FS0(0b01);
  MAX77650_setINV_LED0(false);    //LED red: phase operation
  MAX77650_setBRT_LED0(0b00000);  //LED red: brightness
  MAX77650_setP_LED0(0b1111);     //LED red: LED period
  MAX77650_setD_LED0(0b1111);     //LED red: LED duty-cycle
  
  MAX77650_setLED_FS1(0b01); 
  MAX77650_setINV_LED1(false);    //LED green: phase operation
  MAX77650_setBRT_LED1(0b00000);  //LED green: brightness 
  MAX77650_setP_LED1(0b1111);     //LED green: LED period 
  MAX77650_setD_LED1(0b1111);     //LED green: LED duty-cycle 
  
  MAX77650_setLED_FS2(0b01); 
  MAX77650_setINV_LED2(false);    //LED blue: phase operation
  MAX77650_setBRT_LED2(0b00000);  //LED blue: brightness 
  MAX77650_setP_LED2(0b1111);     //LED blue: LED period 
  MAX77650_setD_LED2(0b1111);     //LED blue: LED duty-cycle    

  MAX77650_setEN_LED_MSTR(true);  //LEDs Master enable     
}

void loop(void)
{
  //Do some stuff and goto power off again
  for (i=0; i<33; i++){
   MAX77650_setBRT_LED0(i);
   MAX77650_setBRT_LED1(0);
   MAX77650_setBRT_LED2(0);
   delay(50);  
  } 
  for (i=0; i<33; i++){
   MAX77650_setBRT_LED0(0);
   MAX77650_setBRT_LED1(i);
   MAX77650_setBRT_LED2(0);
   delay(50);  
  } 
  for (i=0; i<33; i++){
   MAX77650_setBRT_LED0(0);
   MAX77650_setBRT_LED1(0);
   MAX77650_setBRT_LED2(i);
   delay(50);  
  } 

  digitalWrite(MAX32620_Power_hold, LOW);       //set output to LOW to goto power off again after some seconds  
}
