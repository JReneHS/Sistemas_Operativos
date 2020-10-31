#!/bin/bash
gcc emisor.c -o emisor
gcc receptor.c -o receptor
gnome-terminal -t "emisor" --window -- "./emisor" "$1" & gnome-terminal -t "receptor" --window -- "./receptor"