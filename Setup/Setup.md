# Setup Instructions

This guide will help you set up your system for the Flexe Glove project. It covers how to dual boot Ubuntu 22.04 or use a virtual machine, and how to install the necessary tools including ROS2 Humble, STM32CubeIDE, Fusion 360, and Pure Data.

**IMPORTANT: Download Ubuntu 22.04 ONLY. Do NOT download the latest version.**

## Option 1: Dual Boot Ubuntu 22.04 LTS with Windows

1. **Backup your data**: Always back up important files before partitioning your disk.
2. **Create a bootable USB**:

   * Download the Ubuntu 22.04 ISO from the [official site](https://ubuntu.com/download/desktop).
   * Follow the tutorial given [here](https://www.youtube.com/watch?v=GXxTxBPKecQ)

## Option 2: Use Ubuntu in a Virtual Machine (VM)

1. **Install VirtualBox** (or VMware Workstation Player).
2. **Download Ubuntu 22.04 ISO**.
3. **Create a new virtual machine**:

   * Allocate at least 8 GB RAM and 100 GB storage.
   * Mount the ISO and install Ubuntu.

### Basic Linux Shell Commands
- Update your system:
  sudo apt update && sudo apt upgrade
- Install software:
  sudo apt install <package_name>
- Navigate directories:
  cd <directory_name>
- List files in a directory:
  ls
- Make a directory:
  mkdir <directory_name>
- View file contents:
  cat <file_name>
> My favourite commands :  cowsay , fortune , sl 
  I urge to find more cool commands and tell me (I find these really cool!!)

## ROS 2 Humble Desktop Installation (on Ubuntu 22.04)

1. **Set up sources**: Follow this guide [here](https://www.youtube.com/playlist?list=PLLSegLrePWgJudpPUof4-nVFHGkB62Izy) to install and learn ROS2.
   This is an excellent guide—I myself learnt everything from this. Again, note the version.

## STM32CubeIDE Installation (Linux)

1. **Download the installer** from the [STMicroelectronics website](https://www.st.com/en/development-tools/stm32cubeide.html).
2. **Make the installer executable**:

   ```bash
   chmod +x SetupSTM32CubeIDE*.sh
   ```
3. **Run the installer**:

   ```bash
   ./SetupSTM32CubeIDE*.sh
   ```
4. **Follow the GUI prompts** to complete the installation.

These are the resources for learning the basics of STM32. We will be using the Bluepill and NUCLEO boards for our project, so learn the basics for them. Also learn about PWM, ADC with DMA, and using multichannel ADC through FTDI. I will update resources as needed here.

## Fusion 360 Installation (via Wine or VM)

We will be downloading Fusion 360 in macOS/Windows itself since it is not supported in Linux. Then we will be using add-ins to export our CAD files to URDF.

- The steps to convert our file to URDF will be conveyed later—you don’t need to download any special software for that now.
- Please log in to Fusion 360 using your IITK email, just like you would have done for TA111 with AutoCAD.

## Pure Data

This will be used for final song conversion, so have fun playing with it whenever you get bored.

Look up MIDI control in Pure Data using Python if you want to learn more:
[https://puredata.info/](https://puredata.info/)

> This setup ensures your system is ready for all development aspects of the Flexe Glove project.
