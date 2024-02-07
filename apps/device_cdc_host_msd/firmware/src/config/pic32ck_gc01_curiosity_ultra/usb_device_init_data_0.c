/*******************************************************************************
  System Initialization File

  File Name:
    usb_device_init_data.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"
/**************************************************
 * USB Device Function Driver Init Data
 **************************************************/
/* MISRA C-2012 Rule 10.3 deviated:4 Deviation record ID -  H3_USB_MISRAC_2012_R_10_3_DR_1 */
static const USB_DEVICE_CDC_INIT cdcInit0 =
{
    .queueSizeRead = 1,
    .queueSizeWrite = 1,
    .queueSizeSerialStateNotification = 1
};
/* MISRAC 2012 deviation block end */   



/**************************************************
 * USB Device Layer Function Driver Registration 
 * Table
 **************************************************/
 

/* MISRA C-2012 Rule 10.3, 11.8 deviated below. Deviation record ID -  
   H3_USB_MISRAC_2012_R_10_3_DR_1 & H3_USB_MISRAC_2012_R_11_8_DR_1*/

static const USB_DEVICE_FUNCTION_REGISTRATION_TABLE funcRegistrationTable0[1] =
{
        /* CDC Function 0 */
    {
        .configurationValue = 1,                            // Configuration value
        .interfaceNumber = 0,                               // First interfaceNumber of this function
        .speed = (USB_SPEED)((uint32_t)USB_SPEED_HIGH|(uint32_t)USB_SPEED_FULL),             // Function Speed
        .numberOfInterfaces = 2,                            // Number of interfaces
        .funcDriverIndex = 0,                               // Index of CDC Function Driver
        .driver = (void*)USB_DEVICE_CDC_FUNCTION_DRIVER,    // USB CDC function data exposed to device layer
        .funcDriverInit = (void*)&cdcInit0                  // Function driver init data
    },


};

/*******************************************
 * USB Device Layer Descriptors
 *******************************************/
/*******************************************
 *  USB Device Descriptor 
 *******************************************/
static const USB_DEVICE_DESCRIPTOR deviceDescriptor0 =
{
    0x12,                                                   // Size of this descriptor in bytes
    (uint8_t)USB_DESCRIPTOR_DEVICE,                                  // DEVICE descriptor type
    0x0200,                                                 // USB Spec Release Number in BCD format
        USB_CDC_CLASS_CODE,                                     // Class Code
    USB_CDC_SUBCLASS_CODE,                                  // Subclass code
    0x00,                                                   // Protocol code


    USB_DEVICE_EP0_BUFFER_SIZE,                             // Max packet size for EP0, see configuration.h
    0x04D8,                                                 // Vendor ID
    0x000A,                                                 // Product ID                
    0x0100,                                                 // Device release number in BCD format
    0x01,                                                   // Manufacturer string index
    0x02,                                                   // Product string index
    0x00,                                                   // Device serial number string index
    0x01                                                    // Number of possible configurations
};


/*******************************************
 *  USB Device Qualifier Descriptor for this
 *  demo.
 *******************************************/
static const USB_DEVICE_QUALIFIER deviceQualifierDescriptor0 =
{
    0x0A,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE_QUALIFIER,                        // Device Qualifier Type
    0x0200,                                                 // USB Specification Release number
        USB_CDC_CLASS_CODE,                                     // Class Code
    USB_CDC_SUBCLASS_CODE,                                  // Subclass code
    0x00,                                                   // Protocol code


    USB_DEVICE_EP0_BUFFER_SIZE,                             // Maximum packet size for endpoint 0
    0x01,                                                   // Number of possible configurations
    0x00                                                    // Reserved for future use.
};

/*******************************************
 *  USB High Speed Configuration Descriptor
 *******************************************/
static const uint8_t highSpeedConfigurationDescriptor0[]=
{
    /* Configuration Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    (uint8_t)USB_DESCRIPTOR_CONFIGURATION,                           // Descriptor Type
    USB_DEVICE_16bitTo8bitArrange(67),                      //(67 Bytes)Size of the Configuration descriptor
    2,                                                      // Number of interfaces in this configuration
    0x01,                                               // Index value of this configuration
    0x00,                                               // Configuration string index
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, // Attributes
    50,                                                 // Maximum power consumption (mA) /2
    
    /* Interface Descriptor */

    0x09,                                           // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,                       // Descriptor Type is Interface descriptor
    0,                                  // Interface Number
    0x00,                                           // Alternate Setting Number
    0x01,                                           // Number of endpoints in this interface
    USB_CDC_COMMUNICATIONS_INTERFACE_CLASS_CODE,    // Class code
    (uint8_t)USB_CDC_SUBCLASS_ABSTRACT_CONTROL_MODEL,        // Subclass code
    (uint8_t)USB_CDC_PROTOCOL_AT_V250,                       // Protocol code
    0x00,                                           // Interface string index

    /* CDC Class-Specific Descriptors */

    (uint8_t)sizeof(USB_CDC_HEADER_FUNCTIONAL_DESCRIPTOR),               // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                  // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_HEADER,                                  // Type of functional descriptor
    0x20,0x01,                                                  // CDC spec version

    (uint8_t)sizeof(USB_CDC_ACM_FUNCTIONAL_DESCRIPTOR),                  // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                  // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_ABSTRACT_CONTROL_MANAGEMENT,             // Type of functional descriptor
    USB_CDC_ACM_SUPPORT_LINE_CODING_LINE_STATE_AND_NOTIFICATION,// bmCapabilities of ACM

    sizeof(USB_CDC_UNION_FUNCTIONAL_DESCRIPTOR_HEADER) + 1,     // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                  // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_UNION,                                   // Type of functional descriptor
    0,                                                       // com interface number
    1,

    (uint8_t)sizeof(USB_CDC_CALL_MANAGEMENT_DESCRIPTOR),                 // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                  // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_CALL_MANAGEMENT,                         // Type of functional descriptor
    0x00,                                                       // bmCapabilities of CallManagement
    1,                                                       // Data interface number

    /* Interrupt Endpoint (IN) Descriptor */

    0x07,                           // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT,        // Endpoint Descriptor
    1 | USB_EP_DIRECTION_IN,    // EndpointAddress ( EP1 IN INTERRUPT)
    (uint8_t)USB_TRANSFER_TYPE_INTERRUPT,    // Attributes type of EP (INTERRUPT)
    0x10,0x00,                      // Max packet size of this EP
    0x02,                           // Interval (in ms)

    /* Interface Descriptor */

    0x09,                               // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,           // INTERFACE descriptor type
    1,      // Interface Number
    0x00,                               // Alternate Setting Number
    0x02,                               // Number of endpoints in this interface
    USB_CDC_DATA_INTERFACE_CLASS_CODE,  // Class code
    0x00,                               // Subclass code
    (uint8_t)USB_CDC_PROTOCOL_NO_CLASS_SPECIFIC, // Protocol code
    0x00,                               // Interface string index

    /* Bulk Endpoint (OUT) Descriptor */

    0x07,                       // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    2 | USB_EP_DIRECTION_OUT,   // EndpointAddress ( EP2 OUT )
    (uint8_t)USB_TRANSFER_TYPE_BULK,     // Attributes type of EP (BULK)
    0x00, 0x02,                 // Max packet size of this EP
    0x00,                       // Interval (in ms)

     /* Bulk Endpoint (IN)Descriptor */

    0x07,                       // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    2 | USB_EP_DIRECTION_IN,    // EndpointAddress ( EP2 IN )
    0x02,                       // Attributes type of EP (BULK)
    0x00, 0x02,                 // Max packet size of this EP
    0x00,                       // Interval (in ms)



};

/*******************************************
 * Array of High speed config descriptors
 *******************************************/
static USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE highSpeedConfigDescSet0[1] =
{
    highSpeedConfigurationDescriptor0
};

/*******************************************
 *  USB Full Speed Configuration Descriptor
 *******************************************/
 /* MISRA C-2012 Rule 10.3 deviated:25 Deviation record ID -  H3_USB_MISRAC_2012_R_10_3_DR_1 */
static const uint8_t fullSpeedConfigurationDescriptor0[]=
{
    /* Configuration Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    (uint8_t)USB_DESCRIPTOR_CONFIGURATION,                           // Descriptor Type
    USB_DEVICE_16bitTo8bitArrange(67),                      //(67 Bytes)Size of the Configuration descriptor
    2,                                                      // Number of interfaces in this configuration
    0x01,                                                   // Index value of this configuration
    0x00,                                                   // Configuration string index
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, // Attributes
    50,                                                 // Maximum power consumption (mA) /2    
    /* Interface Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    (uint8_t)USB_DESCRIPTOR_INTERFACE,                               // Descriptor Type is Interface descriptor
    0,                                                      // Interface Number
    0x00,                                                   // Alternate Setting Number
    0x01,                                                   // Number of endpoints in this interface
    USB_CDC_COMMUNICATIONS_INTERFACE_CLASS_CODE,            // Class code
    (uint8_t)USB_CDC_SUBCLASS_ABSTRACT_CONTROL_MODEL,                // Subclass code
    (uint8_t)USB_CDC_PROTOCOL_AT_V250,                               // Protocol code
    0x00,                                                   // Interface string index

    /* CDC Class-Specific Descriptors */

    (uint8_t)sizeof(USB_CDC_HEADER_FUNCTIONAL_DESCRIPTOR),                   // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                      // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_HEADER,                                      // Type of functional descriptor
    0x20,0x01,                                                      // CDC spec version

    (uint8_t)sizeof(USB_CDC_ACM_FUNCTIONAL_DESCRIPTOR),                      // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                      // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_ABSTRACT_CONTROL_MANAGEMENT,                 // Type of functional descriptor
    USB_CDC_ACM_SUPPORT_LINE_CODING_LINE_STATE_AND_NOTIFICATION,    // bmCapabilities of ACM

    sizeof(USB_CDC_UNION_FUNCTIONAL_DESCRIPTOR_HEADER) + 1,         // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                      // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_UNION,                                       // Type of functional descriptor
    0,                                                              // com interface number
    1,

    (uint8_t)sizeof(USB_CDC_CALL_MANAGEMENT_DESCRIPTOR),                     // Size of the descriptor
    (uint8_t)USB_CDC_DESC_CS_INTERFACE,                                      // CS_INTERFACE
    (uint8_t)USB_CDC_FUNCTIONAL_CALL_MANAGEMENT,                             // Type of functional descriptor
    0x00,                                                           // bmCapabilities of CallManagement
    1,                                                              // Data interface number

    /* Interrupt Endpoint (IN) Descriptor */

    0x07,                                                   // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT,                                // Endpoint Descriptor
    1 | USB_EP_DIRECTION_IN,                                // EndpointAddress ( EP1 IN INTERRUPT)
    (uint8_t)USB_TRANSFER_TYPE_INTERRUPT,                            // Attributes type of EP (INTERRUPT)
    0x10,0x00,                                              // Max packet size of this EP
    0x02,                                                   // Interval (in ms)

    /* Interface Descriptor */

    0x09,                                                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,                               // INTERFACE descriptor type
    1,                                                      // Interface Number
    0x00,                                                   // Alternate Setting Number
    0x02,                                                   // Number of endpoints in this interface
    USB_CDC_DATA_INTERFACE_CLASS_CODE,                      // Class code
    0x00,                                                   // Subclass code
    (uint8_t)USB_CDC_PROTOCOL_NO_CLASS_SPECIFIC,                     // Protocol code
    0x00,                                                   // Interface string index

    /* Bulk Endpoint (OUT) Descriptor */

    0x07,                                                   // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT,                                // Endpoint Descriptor
    2 | USB_EP_DIRECTION_OUT,                               // EndpointAddress ( EP2 OUT )
    (uint8_t)USB_TRANSFER_TYPE_BULK,                                 // Attributes type of EP (BULK)
    0x40, 0x00,                                             // Max packet size of this EP
    0x00,                                                   // Interval (in ms)

     /* Bulk Endpoint (IN)Descriptor */

    0x07,                                                   // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT,                                // Endpoint Descriptor
    2 | USB_EP_DIRECTION_IN,                                // EndpointAddress ( EP2 IN )
    0x02,                                                   // Attributes type of EP (BULK)
    0x40, 0x00,                                             // Max packet size of this EP
    0x00,                                                   // Interval (in ms)



};

/* MISRAC 2012 deviation block end */
/*******************************************
 * Array of Full speed Configuration 
 * descriptors
 *******************************************/
static USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE fullSpeedConfigDescSet0[1] =
{
    fullSpeedConfigurationDescriptor0
};


/**************************************
 *  String descriptors.
 *************************************/
 /*******************************************
 *  Language code string descriptor
 *******************************************/
const struct
{
    uint8_t bLength;
    uint8_t bDscType;
    uint16_t string[1];
}

static sd000_0 =
{
    (uint8_t)sizeof(sd000_0),                                      // Size of this descriptor in bytes
    (uint8_t)USB_DESCRIPTOR_STRING,                              // STRING descriptor type
    {0x0409}                                            // Language ID
};
/*******************************************
 *  Manufacturer string descriptor
 *******************************************/
const struct
{
    uint8_t bLength;                                    // Size of this descriptor in bytes
    uint8_t bDscType;                                   // STRING descriptor type
    uint16_t string[25];                                // String
}

static sd001_0 =
{
    sizeof(sd001_0),
    USB_DESCRIPTOR_STRING,
    {'M','i','c','r','o','c','h','i','p',' ','T','e','c','h','n','o','l','o','g','y',' ','I','n','c','.'}
    };

/*******************************************
 *  Product string descriptor
 *******************************************/
const struct
{
    uint8_t bLength;                                    // Size of this descriptor in bytes
    uint8_t bDscType;                                   // STRING descriptor type
    uint16_t string[22];                                // String
}

static sd002_0 =
{
    sizeof(sd002_0),
    USB_DESCRIPTOR_STRING,
    {'S','i','m','p','l','e',' ','C','D','C',' ','D','e','v','i','c','e',' ','D','e','m','o'}
}; 

/***************************************
 * Array of string descriptors
 ***************************************/
static USB_DEVICE_STRING_DESCRIPTORS_TABLE stringDescriptors0[3]=
{
    (const uint8_t *const)&sd000_0,
    (const uint8_t *const)&sd001_0,
    (const uint8_t *const)&sd002_0,
};

/*******************************************
 * USB Device Layer Master Descriptor Table 
 *******************************************/
static const USB_DEVICE_MASTER_DESCRIPTOR usbMasterDescriptor0 =
{
    &deviceDescriptor0,                                      // Full speed descriptor
    1,                                                      // Total number of full speed configurations available
    fullSpeedConfigDescSet0,                // Pointer to array of full speed configurations descriptors
    &deviceDescriptor0,                     // High speed device descriptor
    1,                                                      // Total number of high speed configurations available
    highSpeedConfigDescSet0,                                 // Pointer to array of high speed configurations descriptors
    3,                                                      // Total number of string descriptors available.
    stringDescriptors0,                     // Pointer to array of string descriptors.
    &deviceQualifierDescriptor0,                            // Pointer to full speed dev qualifier.
    &deviceQualifierDescriptor0                             // Pointer to high speed dev qualifier.
};


/****************************************************
 * USB Device Layer Initialization Data
 ****************************************************/
const USB_DEVICE_INIT usbDevInitData0 =
{
    /* Number of function drivers registered to this instance of the
       USB device layer */
    .registeredFuncCount = 1,
    
    /* Function driver table registered to this instance of the USB device layer*/
    .registeredFunctions = (USB_DEVICE_FUNCTION_REGISTRATION_TABLE*)funcRegistrationTable0,

    /* Pointer to USB Descriptor structure */
    .usbMasterDescriptor = (USB_DEVICE_MASTER_DESCRIPTOR*)&usbMasterDescriptor0,

    /* USB Device Speed */
    .deviceSpeed =  USB_SPEED_HIGH,   
    
    /* Index of the USB Driver to be used by this Device Layer Instance */
    .driverIndex = DRV_USBHS_INDEX_0,

    /* Pointer to the USB Driver Functions. */
    .usbDriverInterface = DRV_USBHS_DEVICE_INTERFACE,
    
};

/* MISRAC 2012 deviation block end */

// </editor-fold>
