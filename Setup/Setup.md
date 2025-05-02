# Setup Instructions

This guide will help you set up your system for the Flexe Glove project. It covers how to dual boot Ubuntu 22.04 or use a virtual machine, and how to install the necessary tools including ROS2 Humble, STM32CubeIDE, and Fusion 360.

**IMPORTANT: Download Ubuntu 22.04 ONLY. Do NOT download the latest version.**

## Option 1: Dual Boot Ubuntu 22.04 LTS with Windows

1. **Backup your data**: Always back up important files before partitioning your disk.
2. **Create a bootable USB**:

   * Download the Ubuntu 22.04 ISO from the [official site](https://ubuntu.com/download/desktop).
   * Use [Rufus](https://rufus.ie) (Windows) or `Etcher` (Linux/macOS) to create a bootable USB.
3. **Create a partition**:

   * Use Disk Management in Windows to shrink your primary drive and create unallocated space (\~30GB or more).
4. **Boot from USB**:

   * Restart your PC and boot into the USB (change boot order in BIOS/UEFI).
5. **Install Ubuntu**:

   * Choose "Install Ubuntu alongside Windows".
   * Allocate space for Ubuntu and complete the installation.

## Option 2: Use Ubuntu in a Virtual Machine (VM)

1. **Install VirtualBox** (or VMware Workstation Player).
2. **Download Ubuntu 22.04 ISO**.
3. **Create a new virtual machine**:

   * Allocate at least 4 GB RAM and 30 GB storage.
   * Mount the ISO and install Ubuntu.

## ROS 2 Humble Desktop Installation (on Ubuntu 22.04)

1. **Set up sources**:

   ```bash
   sudo apt update && sudo apt install curl gnupg lsb-release
   sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
   echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
   ```
2. **Install ROS 2 Humble Desktop**:

   ```bash
   sudo apt update
   sudo apt install ros-humble-desktop
   ```
3. **Set up the environment**:

   ```bash
   echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
   source ~/.bashrc
   ```

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

## Fusion 360 Installation (via Wine or VM)

> Note: Fusion 360 is not officially supported on Linux. Two options:

### Option 1: Use in Windows (recommended)

* Install Fusion 360 directly in Windows or in a Windows VM.

### Option 2: Use Wine (experimental)

1. **Install Wine and dependencies**:

   ```bash
   sudo apt install wine64 winetricks
   ```
2. **Follow [this guide](https://wiki.winehq.org/Fusion_360)** for detailed Fusion 360 installation via Wine.

For best performance and compatibility, we recommend using Fusion 360 on Windows or through a VM.

This setup ensures your system is ready for all development aspects of the Flexe Glove project.
