#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int foo = 0;
    __pid_t pid = fork();
    if (pid == -1)
    {
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0)
    {
        printf("%d: Hello world\n",getpid());
        foo = 1;
    } 
    else
    {
        printf("%d: %d created\n",getpid(), pid);
        int s;
        (void)waitpid(pid, &s, 0);
        printf("%d: %d finished(%d)\n", getpid(), pid, s);
    }
    printf("%d: foo(%p) = %d\n", getpid(), &foo, foo);
    exit(EXIT_SUCCESS);
    return 0;
}
/* 
Ejemplo 1
46856: 46857 created
46857: Hello world
46857: foo(0x7ffd0529cbdc) = 1
46856: 46857 finished(0)
46856: foo(0x7ffd0529cbdc) = 0 
Ejemplo 2
50453: Hello world
50452: 50453 created
50453: foo(0x7fff4e1bb33c) = 1
50452: 50453 finished(0)
50452: foo(0x7fff4e1bb33c) = 0
Ejemplo 3
50981: Hello world
50981: foo(0x7ffc09ed128c) = 1
50980: 50981 created
50980: 50981 finished(0)
50980: foo(0x7ffc09ed128c) = 0
*/
