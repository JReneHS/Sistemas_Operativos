#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	for (int i = 0; i < 134; ++i)
	{
		printf("Llamada de error #%d\n",i);
		printf("%s\n\n",strerror(i) );
	}
	return 0;
}
/*
Llamada de error #0
Success

Llamada de error #1
Operation not permitted

Llamada de error #2
No such file or directory

Llamada de error #3
No such process

Llamada de error #4
Interrupted system call

Llamada de error #5
Input/output error

Llamada de error #6
No such device or address

Llamada de error #7
Argument list too long

Llamada de error #8
Exec format error

Llamada de error #9
Bad file descriptor

Llamada de error #10
No child processes

Llamada de error #11
Resource temporarily unavailable

Llamada de error #12
Cannot allocate memory

Llamada de error #13
Permission denied

Llamada de error #14
Bad address

Llamada de error #15
Block device required

Llamada de error #16
Device or resource busy

Llamada de error #17
File exists

Llamada de error #18
Invalid cross-device link

Llamada de error #19
No such device

Llamada de error #20
Not a directory

Llamada de error #21
Is a directory

Llamada de error #22
Invalid argument

Llamada de error #23
Too many open files in system

Llamada de error #24
Too many open files

Llamada de error #25
Inappropriate ioctl for device

Llamada de error #26
Text file busy

Llamada de error #27
File too large

Llamada de error #28
No space left on device

Llamada de error #29
Illegal seek

Llamada de error #30
Read-only file system

Llamada de error #31
Too many links

Llamada de error #32
Broken pipe

Llamada de error #33
Numerical argument out of domain

Llamada de error #34
Numerical result out of range

Llamada de error #35
Resource deadlock avoided

Llamada de error #36
File name too long

Llamada de error #37
No locks available

Llamada de error #38
Function not implemented

Llamada de error #39
Directory not empty

Llamada de error #40
Too many levels of symbolic links

Llamada de error #41
Unknown error 41

Llamada de error #42
No message of desired type

Llamada de error #43
Identifier removed

Llamada de error #44
Channel number out of range

Llamada de error #45
Level 2 not synchronized

Llamada de error #46
Level 3 halted

Llamada de error #47
Level 3 reset

Llamada de error #48
Link number out of range

Llamada de error #49
Protocol driver not attached

Llamada de error #50
No CSI structure available

Llamada de error #51
Level 2 halted

Llamada de error #52
Invalid exchange

Llamada de error #53
Invalid request descriptor

Llamada de error #54
Exchange full

Llamada de error #55
No anode

Llamada de error #56
Invalid request code

Llamada de error #57
Invalid slot

Llamada de error #58
Unknown error 58

Llamada de error #59
Bad font file format

Llamada de error #60
Device not a stream

Llamada de error #61
No data available

Llamada de error #62
Timer expired

Llamada de error #63
Out of streams resources

Llamada de error #64
Machine is not on the network

Llamada de error #65
Package not installed

Llamada de error #66
Object is remote

Llamada de error #67
Link has been severed

Llamada de error #68
Advertise error

Llamada de error #69
Srmount error

Llamada de error #70
Communication error on send

Llamada de error #71
Protocol error

Llamada de error #72
Multihop attempted

Llamada de error #73
RFS specific error

Llamada de error #74
Bad message

Llamada de error #75
Value too large for defined data type

Llamada de error #76
Name not unique on network

Llamada de error #77
File descriptor in bad state

Llamada de error #78
Remote address changed

Llamada de error #79
Can not access a needed shared library

Llamada de error #80
Accessing a corrupted shared library

Llamada de error #81
.lib section in a.out corrupted

Llamada de error #82
Attempting to link in too many shared libraries

Llamada de error #83
Cannot exec a shared library directly

Llamada de error #84
Invalid or incomplete multibyte or wide character

Llamada de error #85
Interrupted system call should be restarted

Llamada de error #86
Streams pipe error

Llamada de error #87
Too many users

Llamada de error #88
Socket operation on non-socket

Llamada de error #89
Destination address required

Llamada de error #90
Message too long

Llamada de error #91
Protocol wrong type for socket

Llamada de error #92
Protocol not available

Llamada de error #93
Protocol not supported

Llamada de error #94
Socket type not supported

Llamada de error #95
Operation not supported

Llamada de error #96
Protocol family not supported

Llamada de error #97
Address family not supported by protocol

Llamada de error #98
Address already in use

Llamada de error #99
Cannot assign requested address

Llamada de error #100
Network is down

Llamada de error #101
Network is unreachable

Llamada de error #102
Network dropped connection on reset

Llamada de error #103
Software caused connection abort

Llamada de error #104
Connection reset by peer

Llamada de error #105
No buffer space available

Llamada de error #106
Transport endpoint is already connected

Llamada de error #107
Transport endpoint is not connected

Llamada de error #108
Cannot send after transport endpoint shutdown

Llamada de error #109
Too many references: cannot splice

Llamada de error #110
Connection timed out

Llamada de error #111
Connection refused

Llamada de error #112
Host is down

Llamada de error #113
No route to host

Llamada de error #114
Operation already in progress

Llamada de error #115
Operation now in progress

Llamada de error #116
Stale file handle

Llamada de error #117
Structure needs cleaning

Llamada de error #118
Not a XENIX named type file

Llamada de error #119
No XENIX semaphores available

Llamada de error #120
Is a named type file

Llamada de error #121
Remote I/O error

Llamada de error #122
Disk quota exceeded

Llamada de error #123
No medium found

Llamada de error #124
Wrong medium type

Llamada de error #125
Operation canceled

Llamada de error #126
Required key not available

Llamada de error #127
Key has expired

Llamada de error #128
Key has been revoked

Llamada de error #129
Key was rejected by service

Llamada de error #130
Owner died

Llamada de error #131
State not recoverable

Llamada de error #132
Operation not possible due to RF-kill

Llamada de error #133
Memory page has hardware error
*/