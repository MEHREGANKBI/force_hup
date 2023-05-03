# Force_hup (aka yeshup)

## Table of contents:
- [Introduction](#introduction)
- [Installation](#installation)
- [Uninstallation](#uninstallation)
- [Usage](#usage)
- [Notes](#notes)

## Introduction
Force_hup is an app that is meant to force the linux apps that ignore SIGHUP to exit upon receiving the signal. Basically, it does the reverse of the nohup command. 

## Installation
1- On your linux system, clone/download the repository

2- Using "cd", change directory to the project's root directory

3- from there, run the following command: "make install"

4- If successful, you'll be notified and the binary will be built and located in the "~/.local/bin/" directory


## Usage
SYNOPSIS: force_hup your_command [the_args_for_the_command]

The usage is straightforward. just prepend the command you always use with force_hup.

For example if you would normally use the following command: sleep 1 2 3

You should use: force_hup sleep 1 2 3

If your command has errors, you'll be notified


## Uninstallation
1- Using "cd", change directory to the project's root directory
2- Run the following command: "make uninstall"
3- The binary will be removed and you can now remove the source code as well


## Notes
*This app **"should"** run on any modern x64 linux system.*

*This app acts like a shell intsance. Users should be aware of the permissions of the force_hup binary.*

*Normal usage is not likely to cause security concerns. However, the possibility of shell injection attacks in edge-cases cannot be ruled out. proceed with caution.*

*This app has no guarantees. Consult the license file of this project for more information.*