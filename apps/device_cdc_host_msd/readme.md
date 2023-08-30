---
parent: Harmony 3 USB Multi-Controller application examples
title: CDC Device and MSD Host Example
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# CDC Device and MSD Host Example (device_cdc_host_msd)

This application demonstrates the ability of the MPLAB Harmony USB Stack to support USB Device and Host operation on a PIC32 microcontroller with two USB Controllers.  

## Description

This application demonstrates USB Device and Host operation on a PIC32 microcontroller with two USB Controllers. One USB peripheral operates in USB Device mode and other peripheral operates in USB Host mode. This demonstrates capability of Harmony USB stack to work with multiple USB controllers.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_multi_controller) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_multi_controller/apps/device_cdc_host_msd](https://github.com/Microchip-MPLAB-Harmony/usb_apps_multi_controller/tree/master/apps/device_cdc_host_msd).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mk_gp_db.X                 | MPLABX | PIC32MK1024GPE100   | [PIC32MK General Purpose (GP) Development Board](#config_12)               |
| pic32mk_mcm_curiosity_pro.X     | MPLABX | PIC32MK1024MCM100   | [PIC32MK MCM Curiosity Pro Development Board](#config_18)|
| pic32cz_ca80_curiosity_ultra.X  | MPLABX | PIC32CZ8110CA80208  | [PIC32CZ Curiosity Development Board](#config_23)           |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_23"></a> [PIC32CZ CA80 Curiosity Ultra development board](https://www.microchip.com/en-us/development-tool/ea61x20a)
- Board must be powered by J100.
- USBHS0 Peripheral (Micro-AB connector - J102) operates in USB Host mode.
    - USB Flash drives should be attached to J102 using a USB Type-A Female to micro-B male cable (This cable is not included in the kit). 
    - LED1 on the demonstration board will illuminate to indicate completion of the file transfer.
- USBHS1 Peripheral operates (Type C connector - J103) operates in USB Device mode
    - Connect J103 to a Host PC.
    - LED0 indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).
    - Press switch SW1 to trigger communication from the USB Device to the USB Host.

### <a name="config_12"></a> [PIC32MK General Purpose (GP) Development Board](https://www.microchip.com/developmenttools/ProductDetails/dm320106)

- Switch S4 should be set to the Device position.
- Jumper J28 must be removed.
- USB Micro B Connector J12 must be connected to a USB Host for powering the board.
- USB1 Peripheral (Type A connector - J14) operates in USB Host mode.
    - USB Flash drives should be attached to J14 (Type A connector)
    - LED 2 on the demonstration board will illuminate to indicate completion of the file transfer.
- USB2 Peripheral operates (Type C connector - J15) operates in USB Device mode
    - Connect J15 to a Host PC.
    - LED1 indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).
    - Press S1 to trigger communication from the USB Device to the USB Host.

### <a name="config_18"></a> [PIC32MK MCM Curiosity Pro Development Board](https://www.microchip.com/Developmenttools/ProductDetails/EV31E34A)

- Switch S200 should be set to the Device position.
- Jumper J204 must be removed.
- USB Micro B Connector J203 must be connected to a USB Host for powering the board.
- USB1 Peripheral (Type A connector - J201) operates in USB Host mode.
    - USB Flash drives should be attached to J201 (Type A connector)
    - LED 2 on the demonstration board will illuminate to indicate completion of the file transfer.
- USB2 Peripheral operates (Type C connector - J202) operates in USB Device mode
    - Connect J202 to a Host PC.
    - LED1 indicates USB Device Configuration Set Complete event (the USB device functionality has been activated by the USB Host).
    - Press SW1 to trigger communication from the USB Device to the USB Host.

## Running the Application

This application demonstrates the capability of a PIC32 microcontroller and the MPLAB Harmony USB Host stack to work with two USB Controllers in an application. This application operates USB1 controller on the PIC32MK in USB Host mode and USB2 Controller in USB Device mode. 

USB1 controller on the PIC32 to operate as USB Host MSD and USB2 peripheral to appear like a serial (COM) port to the host. Do the following to run this demonstration:

- Open the project with appropriate IDE. Compile the project and program the target device.
- Attach a USB Flash drive to the Host connector and Connect USB Device connector to a USB Host. Refer to [Configuring the Hardware](#config_title) for details.
- The CDC Device application is same as *cdc_com_port_single* demo. Refer to local documentation from [usb_apps_device/apps/cdc_com_port_single](..\..\apps\cdc_com_port_single\readme.md). The documentation is also available in the github path [usb_apps_device/apps/cdc_com_port_single](https://github.com/Microchip-MPLAB-Harmony/usb_apps_device/apps/cdc_com_port_single).
- The MSD Host application is same as *msd_basic* host demo. Refer to local documentation from [usb_apps_host/apps/msd_basic](..\..\apps\msd_basic\readme.md). The documentation is also available in the github path [usb_apps_host/apps/msd_basic](https://github.com/Microchip-MPLAB-Harmony/usb_apps_host/apps/msd_basic).

**Note:** The PC driver needed for USB device should be used from [usb_apps_multi_controller/apps/device_cdc_host_msd\bin\GenericHIDSimpleDemo_Composite_HID+MSD_Demo_only_PID_0x0054.exe](..\..\apps\hid_msd_basic\bin\GenericHIDSimpleDemo_Composite_HID+MSD_Demo_only_PID_0x0054.exe). To launch the application, double click the executable *GenericHIDSimpleDemo_Composite_HID+MSD_Demo_only_PID_0x0054.exe*.

