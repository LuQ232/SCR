#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void terminate(int sig_num)
{
    printf("END OF PROGRAM!!\n");
    exit(0);
}

void alrm(int sig_num)
{
    printf("ALARM!!!!!\n");
}

void usr1(int sig_num)
{
    printf("Program stopped for 10 iterations\n");
    for(int i=0;i<10;i++)
    {
        printf("%d",i);
        sleep(1);
    }
}

void usr2(int sig_num)
{

}


int main()
{
    signal(SIGTERM, terminate);
    signal(SIGALRM, alrm);
    signal(SIGUSR1, usr1);
    signal(SIGUSR2, usr2);

    while(1)
    {
        printf("Program is still working... \n");
        sleep(1);
    }
    return 0;
}
