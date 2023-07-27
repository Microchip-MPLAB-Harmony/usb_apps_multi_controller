/*******************************************************************************
  Board Support Package Header File.

  Company:
    Microchip Technology Inc.

  File Name:
    bsp.h

  Summary:
    Board Support Package Header File 

  Description:
    This file contains constants, macros, type definitions and function
    declarations 
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef BSP_H
#define BSP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "device.h"

// *****************************************************************************
// *****************************************************************************
// Section: BSP Macros
// *****************************************************************************
// *****************************************************************************
#define pic32cz_ca80_curiosity_ultra
#define BSP_NAME             "pic32cz_ca80_curiosity_ultra"



/*** LED Macros for LED1 ***/
#define LED1_Toggle()     (PORT_REGS->GROUP[1].PORT_OUTTGL = 1UL << 21)
#define LED1_On()         (PORT_REGS->GROUP[1].PORT_OUTCLR = 1UL << 21)
#define LED1_Off()        (PORT_REGS->GROUP[1].PORT_OUTSET = 1UL << 21)
/*** LED Macros for LED2 ***/
#define LED2_Toggle()     (PORT_REGS->GROUP[1].PORT_OUTTGL = 1UL << 22)
#define LED2_On()         (PORT_REGS->GROUP[1].PORT_OUTCLR = 1UL << 22)
#define LED2_Off()        (PORT_REGS->GROUP[1].PORT_OUTSET = 1UL << 22)

/*** SWITCH Macros for SWITCH1 ***/
#define SWITCH1_Get()     ((PORT_REGS->GROUP[1].PORT_IN >> 24) & 0x01)
#define SWITCH1_STATE_PRESSED   0
#define SWITCH1_STATE_RELEASED  1
/*** SWITCH Macros for SWITCH2 ***/
#define SWITCH2_Get()     ((PORT_REGS->GROUP[2].PORT_IN >> 23) & 0x01)
#define SWITCH2_STATE_PRESSED   0
#define SWITCH2_STATE_RELEASED  1

/*** VBUS Macros for VBUS_AL ***/
#define VBUS_AL_PowerEnable()         (PORT_REGS->GROUP[4].PORT_OUTCLR = 1UL << 9)
#define VBUS_AL_PowerDisable()        (PORT_REGS->GROUP[4].PORT_OUTSET = 1UL << 9)




// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void BSP_Initialize(void)

  Summary:
    Performs the necessary actions to initialize a board

  Description:
    This function initializes the LED and Switch ports on the board.  This
    function must be called by the user before using any APIs present on this
    BSP.

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Example:
    <code>
    BSP_Initialize();
    </code>

  Remarks:
    None
*/

void BSP_Initialize(void);

#endif // BSP_H

/*******************************************************************************
 End of File
*/
