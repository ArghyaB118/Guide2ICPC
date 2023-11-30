//#include "../CacheHelper.h"
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
#include <cstring>
#include <fcntl.h>
#include <queue>
#include <algorithm>
#include <fstream>
#include <time.h>
using namespace std;
#define TYPE int

int data_in_megabytes, memory_given_MB, k_logical;
int logical_block_size_MB = 16;
unsigned long long num_elements, base_case;

class Integer_comparator
{
	public:
		bool operator () (const int& a, const int& b) const
		{
			return (a < b);
		}
};

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cout << "insufficient arguments" << endl;
		exit(1);
	}
	int fdout;
	if ((fdout = open ("nullbytes", O_RDWR, 0x0777 )) < 0) {
		cout << "can't create nullbytes for writing" << endl;
		return 0;
	}
	memory_given_MB = atoi(argv[1]); data_in_megabytes = atoi(argv[2]);
	k_logical = (memory_given_MB / (4 * logical_block_size_MB));
	num_elements = data_in_megabytes * 1024 * 1024 / sizeof(TYPE);
	base_case = logical_block_size_MB * 1024 *  1024 / sizeof(TYPE);
	cout << "Running " << k_logical << " way merge sort of array with size: " << num_elements << " with base case: " << base_case << endl;
	TYPE* arr;
	if (((arr = (TYPE*) mmap(0, data_in_megabytes * 1024 * 1024, PROT_READ | PROT_WRITE, MAP_SHARED , fdout, 0)) == (TYPE*)MAP_FAILED)){
		cout << "mmap error for output with code" << endl;
		return 0;
	}
	time_t start = time(NULL);
	mergeSort::sort<int, class Integer_comparator>(&arr[0], &arr[num_elements], comp);
	time_t finish = time(NULL);
	double duration = finish - start; cout << "runtime is: " << duration << endl;
	for (unsigned long long i = 0; i < num_elements - 1; ++i) {
		if (arr[i + 1] < arr[i]) {
			cout << i << arr[i] << " " << arr[i + 1] << " wrong " << endl;
			//break;
		}
	}	
	return 0;
}
