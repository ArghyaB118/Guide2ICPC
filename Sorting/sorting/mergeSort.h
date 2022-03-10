//#include "../CacheHelper.h"
#include "funnelSort.h"
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
using namespace std;
#define TYPE int
unsigned long long num_elements, base_case;
int logical_block_size_MB = 16;


namespace mergeSort {
	template <class T, class Compare>
	void sort(T* inFirst, T* inLast, Compare comp) {

	} 
}