#!/bin/bash
gcc sharedMem_write.c -o writesh
gcc sharedMem_read.c -o readsh
gcc sharedMem_destroy.c -o destroysh
