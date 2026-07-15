#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

using namespace std;

int main()
{
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if(pid == 0)
    {
        close(fd[1]);

        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));

        cout << "Child received: " << buffer << endl;

        close(fd[0]);
    }
    else
    {
        close(fd[0]);

        char msg[] = "Hello Child!";
        write(fd[1], msg, strlen(msg)+1);

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}