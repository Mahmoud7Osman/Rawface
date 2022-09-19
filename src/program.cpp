#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <stat/stat.h>

int main(int argc, char** argv){
	// Openning And Initializing File
	if (argv[1] == NULL)
		return 1;

	int fd=open(argv[1]);
	if (fd == -1) return -1;

	struct stat filestat;
	fstat(fd, &filestat);

	char* data=(char*)malloc(filestat.st_size);
	const char* entry=data;

	if (read(fd, data, filestat.st_size) == -1) return -1;

	char bits[8];
	int  byte;

	// Translating Binary Bits into ASCII And Echoing it back
	for (data; data<=data+(filestat.st_size-1); data++){
		// Code Goes Here
	}
}
