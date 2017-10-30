#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct INFO {
	char	name[20];
	int		age;
	float	height;
} INFO;

int main(int argc, char * argv[]){
	int fd;
	int i;
	INFO data[4] = {
		"kim", 20, 170.1F,
		"park", 25, 180.1F,
		"lee", 30, 190.1F,
		"choi", 40, 160.5F
	};
	
	if(argc != 3){
		printf("Usage: %s <filename to be created> <number of lines to read>\n", argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1], O_WRONLY|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO)) == -1){
		perror("open");
		exit(1);
	}
	
	for(i=0; i<atoi(argv[2]); i++){
		if(write(fd, &data[i], sizeof(INFO)) != sizeof(INFO)){
		// if(write(fd, &data[i], sizeof(INFO)) == -1){
			perror("write");
			close(fd); 
			exit(2);
		}
	}
	
	close(fd);
	return 0;
					
}
