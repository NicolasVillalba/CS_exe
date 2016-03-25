#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>


typedef struct tagmag
{
    int client_pid;
    char my_data[512];
}MSG;


int main()
{
    int server_fifo_fd, client_fifo_fd;
    char client_fifo[256] = {0};
    sprintf(client_fifo, "CLIENT_FIFO_%d", getpid());
    MSG my_msg;
    memset(&my_msg, 0, sizeof(MSG));
    my_msg.client_pid = getpid();
    server_fifo_fd = open("./SERVER_FIFO_NAME", O_WRONLY);
    mkfifo(client_fifo, 0777);
    while(1)
    {
        int n = read(STDIN_FILENO, my_msg.my_data, 512);
        my_msg.my_data[n] = '\0';
        write(server_fifo_fd, &my_msg, sizeof(MSG));
        client_fifo_fd = open(client_fifo, O_RDONLY);
        n =read(client_fifo_fd, &my_msg, sizeof(MSG));
        my_msg.my_data[n] = 0;
        write(STDOUT_FILENO, my_msg.my_data, strlen(my_msg.my_data));
        close(client_fifo_fd);
   }
   unlink(client_fifo);
}
