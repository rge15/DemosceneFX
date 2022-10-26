#!/bin/bash

wget --max-redirect=20 -O download.zip https://www.dropbox.com/sh/sgpg5ndtg0slcc9/AAAl3BW5G1u1EV4M_0Tsw-RJa?dl=0

printf "\033[1;34mMoving to img/\033[0m\n"
unzip -u download.zip -x / -d img/
rm download.zip
