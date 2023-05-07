#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    pid_t pid = fork();
    if(-1 == pid)
    {
        perror("fork");
        return 1;
    }

    if( pid == 0 )
    {
        printf("sub process start\n");
        sleep(2);
        printf("sub process end\n");
    }
    else
    {
        printf("main process wait %u\n",pid);
        int status;
        int ops = 0;
        pid_t wait_pid = waitpid(pid,&status,ops);
        printf("waitpid return %u\n",wait_pid);
    }

    return 0;
}
