#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory>
#include <string>
#include <fstream>
using namespace std;
#define TYPE int


unsigned long long data_in_MiB = 0;

int main(int argc, char *argv[]) {
	if (argc < 2) {
    	std::cout << "Insufficient arguments! Usage: ./executables/make-unsorted-data $data_size_run\n";
    	exit(1);
  	}
  	data_in_MiB = std::stol(argv[1]);
  	int fdout;
  	if ((fdout = open ("nullbytes", O_RDWR, 0x0777 )) < 0) {
    	return 0;
  	}
	TYPE* dst;
  	if ((dst = (TYPE*) mmap(0, data_in_MiB*1024*1024, PROT_READ | PROT_WRITE, MAP_SHARED , fdout, 0)) == (TYPE*)MAP_FAILED) {
       printf ("mmap error for output with code\n");
       return 0;
  	}
  	for (unsigned long long i = 0; i < data_in_MiB * 1024 * 1024 / sizeof(TYPE); ++i) {
		dst[i] = abs(rand() % 100000);
	}
  	return 0;
}

