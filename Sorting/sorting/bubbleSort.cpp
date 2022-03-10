#include "bubbleSort.h"
#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <ctime>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory>
#include <string>
#include <fcntl.h>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#define TYPE int
using namespace std;

class Integer_comparator
{
	public:
		bool operator () (const int& a, const int& b) const
		{
			return (a < b);
		}
};

int main(int argc, char *argv[]) {
	int data_in_megabytes = atoi(argv[1]);
	unsigned long long num_elements = data_in_megabytes * 1024 * 1024 / sizeof(TYPE);
	int fdout;
	if ((fdout = open ("nullbytes", O_RDWR, 0x0777 )) < 0) {
  	printf ("creating nullbytes for writing\n");
  	return 0;
	}
	TYPE* arr;
	if ((arr = (TYPE*) mmap(0, data_in_megabytes*1024*1024, PROT_READ | PROT_WRITE, MAP_SHARED , fdout, 0)) == (TYPE*)MAP_FAILED) {
     printf ("mmap error for output with code\n");
     return 0;
	}
	Integer_comparator comp;
	cout << arr[num_elements - 1] << " " << arr[num_elements - 2] << " " << arr[num_elements - 3] << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " " << comp(arr[i], arr[i + 1]) << endl;
	}
	cout << num_elements << endl;
  time_t start = time(NULL);
	bubbleSort::sort<int, class Integer_comparator>(&arr[0], &arr[num_elements], comp);
  time_t finish = time(NULL);
  double duration = finish - start; cout << "runtime is: " << duration << " s" << endl;
	for (unsigned long long i = 0; i < num_elements - 1; ++i) {
		if (arr[i + 1] < arr[i]) {
			cout << i << arr[i] << " " << arr[i + 1] << " wrong " << endl;
			//break;
		}
	}
	return 0;
}