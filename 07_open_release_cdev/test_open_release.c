#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int fd;

	if(argc < 2) {
		printf("pass file to open as an argument\n");
		return 0;
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0){
		perror("Error opening file\n");
		return fd;
	}
	
	close (fd);


	fd = open(argv[1], O_RDWR | O_SYNC);
	return 0;
}
