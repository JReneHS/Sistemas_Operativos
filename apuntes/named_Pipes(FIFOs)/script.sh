#!/bin/bash
gcc ejemplo_FIFO_Emisor_01.c -o Emisor
gcc ejemplo_FIFO_Receptor_01.c -o Receptor
gnome-terminal -t "Emisor" --window -- "./Emisor" & gnome-terminal -t "Receptor" --window -- "./Receptor"