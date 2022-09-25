#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void  up(unsigned char*);
void  dtb(char*, char, int, int, bool);

int main(int argc, char** argv){
	// Openning And Initializing File
	if (argv[1] == NULL)
		return printf("Usage:\n    rawface <file> -d : decode a binary file and write it's contents to stdout (Binary File Containing The ASCII Form of 0s and 1s)\n    rawface <file> -c : turn any file into human readable binary 0s and 1s and write the output to stdout\n");
	if (argv[2] == NULL)
		return printf("Usage:\n    rawface <file> -d : decode a binary file and write it's contents to stdout (Binary File Containing The ASCII Form of 0s and 1s)\n    rawface <file> -c : turn any file into human readable binary 0s and 1s and write the output to stdout\n");

	int fd=open(argv[1], O_RDONLY);
	if (fd == -1) return -1;

	struct stat filestat;
	fstat(fd, &filestat);

	char* data=(char*)malloc(filestat.st_size);
	if(data == NULL) return 5;
	char* entry=data;

	if (read(fd, data, filestat.st_size) == -1) return -1;

	switch(*(*(argv+2)+1)){
		case 'd':
			goto btod;
		case 'c':
			goto dtob;
	}
dtob:
	// Translating Data to Binary And Echoing it to stdout
	char ebyte[8];

	for (data; data<=(entry+filestat.st_size-1); data++){
		memset(ebyte,'0',8);
		dtb(ebyte, *data, pow(2, 0), 7, false);
		printf("%c%c%c%c%c%c%c%c", ebyte[0], ebyte[1], ebyte[2], ebyte[3], ebyte[4], ebyte[5], ebyte[6], ebyte[7], *data);
	}
	printf("\n");
	free(entry);
	exit(0);
btod:
	// Translating Binary to Data And Echoing it to stdout
	char bits[8];
	unsigned char dbyte=0;

	for (char* byte=data; data<=entry+(filestat.st_size-1);data+=8){
		if (data+8>entry+(filestat.st_size-1)) break;
		while(byte <= data+7){
			if (*byte != '0' && *byte != '1') exit(10);
			bits[(((data+7)-byte)-7)*(-1)]=*byte;
			byte++;
		}
//		printf("Byte: %c%c%c%c%c%c%c%c\n", bits[0], bits[1], bits[2], bits[3], bits[4], bits[5], bits[6], bits[7]);

		unsigned char c=0;

		for (int tmp=7; tmp>=0; tmp--){
			up(&c);
			if(bits[tmp] == '0')
				continue;
			dbyte+=c;
		}
		printf("%c", dbyte);
		dbyte=0;
	}
	free(entry);
	exit(0);
}

void up(unsigned char* c){
	static int a=0;
	if (a==8) a=0;
	*c=pow(2, a);
	a++;
}
void dtb(char* byte, char data, int power, int bit, bool stop=false){
	if (stop == true) return;

	if (power<=data){
		if (power*2>data){
			byte[bit]='1';
			if ((data-=power)==0) stop=true;
			power=1;
			bit=7;
		}
		else{
			bit--;
			power*=2;
			stop=false;
		}
		return dtb(byte, data, power, bit, stop);
	}
	else{
		return;
	}
}
