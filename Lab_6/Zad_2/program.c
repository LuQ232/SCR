#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(){

	pid_t process_id;
	char nazwa_pliku[64];
	char obr_map[] = "./obr_map";
	int plik_1;
	int plik_2;
	struct stat status_pliku;
	void *addr = NULL;
	
	process_id = fork();
	
	if(process_id < 0)
	{
		printf("Nie utworzono procesu potomnego\n");
		return 1;
	}

	if(process_id == 0)
	{
		execlp("display","display","-update","1",obr_map,NULL);
	}

	if(process_id > 0)
	{
			while(1){
			printf("Podaj nazwę pliku :\t");
			scanf("%s",nazwa_pliku);
			plik_1 = open(nazwa_pliku, O_RDONLY);
			while(plik_1 < 0){
				printf("Nie otwarto pliku\n");
				printf("Podaj nową nazwę pliku:\t");
				scanf("%s",nazwa_pliku);
				plik_1 = open(nazwa_pliku, O_RDONLY);
			}
			printf("\n");
			stat(nazwa_pliku, &status_pliku);
			plik_2 = open(obr_map, O_RDWR);
			truncate(obr_map,status_pliku.st_size);
			addr = mmap(NULL, status_pliku.st_size,PROT_WRITE | PROT_READ, MAP_SHARED, plik_2, 0);
			read(plik_1, addr, status_pliku.st_size);
			msync(addr, status_pliku.st_size,MS_SYNC);
			close(plik_1);
			close(plik_2);
		}
	}
	munmap(addr, status_pliku.st_size);
	return 0;
}

