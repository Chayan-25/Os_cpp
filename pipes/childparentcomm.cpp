#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

using namespace std;

int main()
{
    int fd[2];
    pipe(fd);

    if(fork()==0)
    {
        close(fd[0]);

        char msg[]="Hello Parent";
        write(fd[1],msg,strlen(msg)+1);

        close(fd[1]);
    }
    else
    {
        close(fd[1]);

        char buffer[100];
        read(fd[0],buffer,sizeof(buffer));

        cout<<"Parent received: "<<buffer<<endl;

        close(fd[0]);
        wait(NULL);
    }

    return 0;
}