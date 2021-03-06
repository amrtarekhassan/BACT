﻿/*
 * L3G4200D_Cfg.h
 *
 * Created: 24/09/2015 09:13:50 م
 *  Author: hossam & Amr Tarek
 */ 


#ifndef L3G4200D_CFG_H_
#define L3G4200D_CFG_H_
#include "BasicTypes.h"
#include "../HAL/DIO.h"
#include "../HAL/SPI.h"

/*SPI Communication Configuration*/
#define GYHD_INIT_SLAVE_SELECT() DIO_InitPortDirection(PB,0xff,1<<2);\
                                DIO_WritePort(PB,0xff,1<<2) 							
#define GYHD_ACTIVATE_SLAVE_SELECT() DIO_WritePort(PB,0x00,1<<2) 
#define GYHD_DEACTIVATE_SLAVE_SELECT() DIO_WritePort(PB,0xff,1<<2) 

/*Timeout Management Configuration*/
#define u8USE_DELAY 0x00
#define u8USE_TIMER 0x01

#define u8TIMEOUT_FUNCTION u8USE_DELAY

#if(u8TIMEOUT_FUNCTION == u8USE_DELAY)

#include <util/delay.h>
#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR) _delay_ms(DELAY_MS);\
                                              *(FLAG_PTR) = 0x01
#else
#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR)
#endif

/*Self Axis Movement Detection Config*/
#define u8SELF_AXIS_MOV  OFF


#endif /* L3G4200D_CFG_H_ */