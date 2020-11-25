#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
  
#define BUFFER_SIZE 1000


int main(int argc, char const *argv[])
{
    char my_string[BUFFER_SIZE];
	if(argc<2)
	{
		fprintf(stderr, "%s\n", "Error: file not given");
		return 1;
	}
	
	if(argc>2)
	{
		fprintf(stderr, "%s\n", "Error: too many args");
		return 1;
	}

	


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
        while(read(pipe1[0],&my_string,BUFFER_SIZE) != 0)
        {
            printf("# %s #\n",my_string);   
            for (int i=0;i<BUFFER_SIZE;i++)
            {
                my_string[i]='\0';
            }  
        } 
        close(pipe1[0]);  
    } else {
        /* Parent Code */
        const char* filename = argv[1];
	    FILE *fptr;

	    if((fptr = fopen(filename, "r")) == NULL)
	    {
	    	fprintf(stderr, "%s\n", "Error: opening file");
	    	return 1;
	    }

	    char buffer[BUFFER_SIZE];
        close(pipe1[0]); // neccessary
	    while(fgets(buffer, BUFFER_SIZE, fptr)!=NULL)
        {
            write(pipe1[1],buffer,strlen(buffer));
        }
        fclose(fptr);
        
        close(pipe1[1]);
        wait(NULL);
        
        exit(EXIT_SUCCESS);
    }
return 0;
}

