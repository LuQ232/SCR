#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<fcntl.h>
  
#define BUFFER_SIZE 256


int main(int argc, char const *argv[])
{
    char buffer[BUFFER_SIZE];
    char file_name[32];
    int  in_pipe1, number;
	

	pid_t process,child_process;

	int pipe1[2];
    if (pipe(pipe1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    child_process = fork();

   

    if (child_process == 0) {
        /* Child  code */
        close(pipe1[1]);
        close(0);
        dup(pipe1[0]);
        close(pipe1[0]);  
        execlp("display","display","-",NULL);//TRZEBA ZAINSTALOWAC PROGRAM IMAGE MAGICK!
                                             //sudo apt-get install imagemagick
    } else {
        /* Parent Code */
        printf("INSERT FULL PATH TO FILE\n");
        scanf("%s", file_name);
        close(pipe1[0]); // neccessary

	    if((in_pipe1 = open(file_name, O_RDONLY)) < 0) 
        {
            fprintf(stderr, "%s\n", "Error: opening file");
	        return 1;
        }

        while((number = read(in_pipe1, &buffer, BUFFER_SIZE)) > 0)
        {
            write(pipe1[1],&buffer,number);
        }
        close(in_pipe1);
        close(pipe1[1]);
        wait(NULL);
        
        exit(EXIT_SUCCESS);
    }
return 0;
}

