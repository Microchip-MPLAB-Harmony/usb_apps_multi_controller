---
parent: Harmony 3 USB Multi-Controller application examples
title: Host MSD Dual Example
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Host MSD Dual Example (host_msd_dual)

This application demonstrates the ability of the MPLAB Harmony USB Stack to support multiple USB Host operation on a PIC32 microcontroller with two USB Controllers.  

## Description

This application demonstrates Multiple USB Host operation on a PIC32 microcontroller with two USB Controllers. Both the USB peripherals operate in USB MSD Host mode. This demonstrates capability of Harmony USB stack to work with multiple USB controllers.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/usb_apps_multi_controller) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is [usb_apps_multi_controller/apps/host_msd_dual](https://github.com/Microchip-MPLAB-Harmony/usb_apps_multi_controller/tree/master/apps/host_msd_dual).

Following table gives the details of project configurations, target device used, hardware and its IDE. Open the project using the respective IDE and build it. 

| Project Name                    | IDE    | Target Device       | Hardware / Configuration                                                   |
| ------------------------------- | ------ | ------------------- | -------------------------------------------------------------------------- |
| pic32mk_gp_db.X                 | MPLABX | PIC32MK1024GPE100   | [PIC32MK General Purpose (GP) Development Board](#config_12)               |
| pic32mk_mcm_curiosity_pro.X     | MPLABX | PIC32MK1024MCM100   | [PIC32MK MCM Curiosity Pro Development Board](#config_18)|
| pic32cz_ca80_curiosity_ultra.X  | MPLABX | PIC32CZ8110CA80208  | [PIC32CZ Curiosity Development Board](#config_23)           |

## <a name="config_title"></a> Configuring the Hardware

### <a name="config_23"></a> PIC32CZ CA80 Curiosity Development Board
- A power supply must be connected to J100 to powering the board.
- LED 0 on the demonstration board will illuminate to indicate completion of the file transfer.
- USB Flash drives should be attached to Connector J103 (Type C connector) and J102 (micro-AB connector) after programming the microcontroller.
- An USB Type-A Female to micro-B male cable and a USB Type-C male to standard-A female must be used. (Theses cables are not included in the kit)

### <a name="config_12"></a> [PIC32MK General Purpose (GP) Development Board](https://www.microchip.com/developmenttools/ProductDetails/dm320106)

- Switch S4 should be set to the Device position.
- Jumper J28 must be shorted.
- USB Micro B Connector J2 must be connected to a USB Host for powering the board.
- LED 1 on the demonstration board will illuminate to indicate completion of the file transfer.
- USB Flash drives should be attached to Connector J15 (Type C connector) and J14 (Type A connector) after programming the microcontroller.

### <a name="config_18"></a> [PIC32MK MCM Curiosity Pro Development Board](https://www.microchip.com/Developmenttools/ProductDetails/EV31E34A)

- Switch S200 should be set to the Device position.
- Jumper J204 must be shorted.
- USB Micro B Connector J203 must be connected to a USB Host for powering the board.
- LED 1 on the demonstration board will illuminate to indicate completion of the file transfer.
- USB Flash drives should be attached to Connector J202 (Type C connector) and J201 (Type A connector) after programming the microcontroller.

## Running the Application

This application demonstrates the capability of a PIC32 microcontroller and the MPLAB Harmony USB Host stack to work with two USB Controllers in an application. The MPLAB Harmony USB Stack is capable of handling multiple USB controllers. The application uses the USB Host_layer, MSD class driver, and the MPLAB Harmony File System Framework to enumerate a USB Flash drive and to write a file to it. 

Do the following to run this demonstration:

1. Open the project with appropriate IDE. Compile the project and program the target device.
1. Two USB Flash drives are needed to run this demo.
1. With the code running, attach a USB Flash drive with a file *file.txt* in it to one of the Host connector on the board.
1. Connect another USB Flash drive to other Host connector on the board. Ensure this flash drive does not contain any file named newfile.txt.
1. The application will copy the file file.txt from the drive containing this file to the other drive. The copied file will be renamed as newfile.txt. LED on the demonstration board will illuminate to indicate completion of the file transfer.
1. Disconnect the drives and confirm demonstration success by inserting them into a personal computer and verifying the file transfer completed as expected.