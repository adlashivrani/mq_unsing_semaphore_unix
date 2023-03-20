#include "header.h"
#include <semaphore.h>

int main()
{
    mqd_t rdfd;
	sem_t *fd;
	fd = sem_open("semaphore", 0660, 0);
    char buff1[MAX] = {0};
    char buff[MAX] = {0};
    rdfd = mq_open("/mymq", O_RDWR, 0666, NULL);
    printf("\nEnter msg from client2...\n");
   	fgets(buff, MAX, stdin);
    mq_send(rdfd, buff, MAX, 0);
	sem_wait(fd);
    mq_receive(rdfd, buff1, MAX, 0);
    printf("\nserver msg...\n%s\n", buff1);
    mq_close(rdfd);
    return 0;
}
