---
parent: Harmony 3 USB Multi-Controller application examples
title: Dual CDC Device Example
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Dual CDC Device Example (device_dual_cdc)

This application demonstrates the ability of the MPLAB Harmony USB Stack to support multiple USB Device operation on a PIC32 microcontroller with two USB Controllers.  

## Description

This application demonstrates Multiple USB Device operation on a PIC32 microcontroller with two USB Controllers. Both the USB peripherals operate in USB CDC Device mode. This demonstrates capability of Harmony USB stack to work with multiple USB controllers.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_multi_controller) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_multi_controller/apps/device_dual_cdc](https://github.com/Microchip-MPLAB-Harmony/usb_apps_multi_controller/tree/master/apps/device_dual_cdc).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mk_gp_db.X                 | MPLABX | PIC32MK1024GPE100   | [PIC32MK General Purpose (GP) Development Board](#config_12)               |
| pic32mk_mcm_curiosity_pro.X     | MPLABX | PIC32MK1024MCM100   | [PIC32MK MCM Curiosity Pro Development Board](#config_18)|
| pic32cz_ca80_curiosity_ultra.X  | MPLABX | PIC32CZ8110CA80208  | [PIC32CZ Curiosity Development Board](#config_23) 
## <a name="config_title"></a> Configuring the Hardware

### <a name="config_12"></a> [PIC32MK General Purpose (GP) Development Board](https://www.microchip.com/developmenttools/ProductDetails/dm320106)

- Switch S4 should be set to the Device position.
- Jumper J28 must be removed.
- USB Micro B Connector J12 must be connected to a USB Host for powering the board.
- Use the USB connectors on the board to connect the USB Device to the USB Host PC.
    - J13 - USB Peripheral 1 (USB Micro B connector located on the bottom side of the board)
    - J15 - USB Peripheral 2 (USB Type C connector)
- Following LEDs indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).
    - LED1 - USB Peripheral 1 (USB Micro B connector - J13)
    - LED2 - USB Peripheral 2 (USB Type C connector - J15)
- Press switch to trigger communication from the USB Device to the USB Host.
    - S1 - USB Peripheral 1 (USB Micro B connector - J13)
    - S2 - USB Peripheral 2 (USB Type C connector - J15)

### <a name="config_18"></a> [PIC32MK MCM Curiosity Pro Development Board](https://www.microchip.com/Developmenttools/ProductDetails/EV31E34A)

- Switch S200 should be set to the Device position.
- Jumper J204 must be removed.
- USB Micro B Connector J203 must be connected to a USB Host for powering the board.
- Use the USB connectors on the board to connect the USB Device to the USB Host PC.
    - J200 - USB Peripheral 1 (USB Micro B connector located on the bottom side of the board)
    - J202 - USB Peripheral 2 (USB Type C connector)
- Following LEDs indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).
    - LED1 - USB Peripheral 1 (USB Micro B connector - J200)
    - LED2 - USB Peripheral 2 (USB Type C connector - J202)
- Press switch to trigger communication from the USB Device to the USB Host.
    - SW1 - USB Peripheral 1 (USB Micro B connector - J200)
    - SW2 - USB Peripheral 2 (USB Type C connector - J202)

### <a name="config_23"></a> [PIC32CZ CA80 Curiosity Ultra development board](https://www.microchip.com/en-us/development-tool/ea61x20a)
- Connect the following USB connectors on the board to the USB Host PC:
    - J102 - USBHS0 (USB Micro-B connector)
    - J103 - USBHS1 (USB Type-C connector)
- The following LEDs indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host):
    - LED0 - USBHS0 (USB Micro-B connector - J102)
    - LED1 - USBHS1 (USB Type-C connector - J103)
- Press the following switches to trigger communication from the USB Device to the USB Host:
    - SW0 - USBHS0 (USB Micro-B connector - J102)
    - SW1 - USBHS1 (USB Type-C connector - J103)

## Running the Application

This application demonstrates dual USB Device operation on a PIC32 microcontroller with two USB Controllers. The MPLAB Harmony USB Stack is capable of handling multiple USB controllers. In this demonstration, both of the USB controllers act as CDC devices. 

This demonstration allows the each controller on the PIC32 to appear like a serial (COM) port to the host. Do the following to run this demonstration:

1. Open the project with appropriate IDE. Compile the project and program the target device.
1. Attach both USB connectors J15 and J13 to a USB Host. Refer to [Configuring the Hardware](#config_title) for details.
1. The CDC Device application is same as *cdc_com_port_single* demo. Refer to local documentation from [usb_apps_device/apps/cdc_com_port_single](..\..\apps\cdc_com_port_single\readme.md). The documentation is also available in the github path [usb_apps_device/apps/cdc_com_port_single](https://github.com/Microchip-MPLAB-Harmony/usb_apps_device/apps/cdc_com_port_single).
