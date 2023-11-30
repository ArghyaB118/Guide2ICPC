//Reference: geeksforgeeks.org
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void swap(int *p1, int *p2) {
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void printarray(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

void printVector(vector<int>& vec) {
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << ' ';
	cout << endl;
}

/* Idea: Build nested for loops, commpare the adjacent elements, swap if needed
 Complexity: always O(n^2) */
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

// Small Optimization: stop when it is already sorted.
// Best case is O(n) and worst case is O(n^2)
void bubbleSortOpt(int arr[], int size) {
	bool swapped = false;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

/* Idea: Run through the array n times and stores the minimum element
 Complexity: O(n^2)  */
void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		int min_id;
		for (int j = i + 1; j < size; ++j) {
			min_id = i;
			if (arr[j] < arr[min_id])
				min_id = j;
			swap(&arr[min_id], &arr[i]);
		}
	}
}

/* Merge Sort: O(n log n)
 Recursive sorting algorithm
 Idea:
 1. Break the array in two parts
 2. Sort the subparts.
 3. Merge the sorted runs.
*/
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1, n2 = r - m;
	int temp1[n1], temp2[n2];
	for (i = 0; i < n1; ++i)
		temp1[i] = arr[l + i];
	for (j = 0; j < n2; ++j)
		temp2[j] = arr[m + 1 + j];
	i = 0; j = 0; k = l;
	while (i < n1 && j < n2) {
		if (temp1[i] <= temp2[j]) {
			arr[k] = temp1[i];
			++i;
		}
		else {
			arr[k] = temp2[j];
			++j;
		}
		++k;
	}
	while (i < n1) {
		arr[k] = temp1[i];
		++i;
		++k;
	}
	while (j < n2) {
		arr[k] = temp2[j];
		++j;
		++k;
	}
}

void mergeClean (int arr[], int l, int r) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = l; i <= r; i++)
        pq.push(arr[i]);
    int i = l;
    while (!pq.empty()) {
        arr[i] = pq.top(); i++; pq.pop();
    }
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
        mergeClean(arr, l, r); // merge(arr, l, m, r);
	}
}

// Example: the way we sort cards
// Stream through the array, insert every element in a sorted manner
void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

/* Quicksort
 Complexity: O(n log n) average*/
int pivoting(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j) {
		if (arr[j] <= pivot) {
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return(i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = pivoting(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}


// Very useful to sort arrays with a lot of duplicates
// Brings down the cost from O(n log n) to O(n + k), k = input range
vector<int> countSort(vector<int>& arr) {
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;
	vector<int> count(range), output(arr.size());
	for (int i = 0; i < arr.size(); ++i)
		count[arr[i] - min]++;
	for (int i = 1; i < count.size(); ++i)
		count[i] += count[i - 1];
	for (int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}
	return output;
}

// Notes: Using a map with make the cost O(n log k), k = range of inputs

void countSortexp(int arr[], int n, int exp) {
	int output[n];
	int count[10] = {0};
	for (int i = 0; i < n; ++i)
		count[(arr[i] / exp) % 10]++;
	for (int i = 1; i < 10; ++i)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i]/exp)%10] - 1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for (int i = 0; i < n; ++i) 
        arr[i] = output[i];
}

/* https://www.interviewkickstart.com/learn/radix-sort-algorithm
 Radix sort can be applied to data that can be sorted lexicographically, such as words and integers. It is also used for stably sorting strings.
 It is a good option when the algorithm runs on parallel machines, making the sorting faster. To use parallelization, we divide the input into several buckets, enabling us to sort the buckets in parallel, as they are independent of each other.
 It is used for constructing a suffix array. (An array that contains all the possible suffixes of a string in sorted order is called a suffix array. For example: If the string is “sort,” then the suffix array SA[] will be:*/

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void radixSort(int arr[], int n) {
	int max_elt = getMax(arr, n);
	for (int exp = 1; max_elt / exp > 0; exp *= 10)
		countSortexp(arr, n, exp);
}


void countSortexpAlt(vector<int>& arr, int exp) {
	int n = arr.size();
	vector<int> output(arr.size());
	int count[10] = {0};
	for (int i = 0; i < n; ++i)
		count[(arr[i] / exp) % 10]++;
	for (int i = 1; i < 10; ++i)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i]/exp)%10] - 1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for (int i = 0; i < n; ++i) 
        arr[i] = output[i];
}

void radixSortAlt(vector<int>& arr) {
	int max_elt = *max_element(arr.begin(), arr.end());
	for (int exp = 1; max_elt / exp > 0; exp *= 10)
		countSortexpAlt(arr, exp);
}

void bucketSort(vector<float>& arr) { 
	int n = arr.size();
    // 1) Create n empty buckets 
    vector<float> bucket[n]; 
    // 2) Put array elements in different buckets 
    for (int i = 0; i < n; i++) { 
       int bucket_index = n * arr[i]; // Index in bucket 
       bucket[bucket_index].push_back(arr[i]); 
    } 
    // 3) Sort individual buckets 
    for (int i=0; i<n; i++) 
       sort(bucket[i].begin(), bucket[i].end()); 
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < bucket[i].size(); j++) 
          arr[index++] = bucket[i][j]; 
} 


void shellSort(vector<int>& arr) {
	int n = arr.size();
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			int temp = arr[i], j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}


void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

void buildMaxHeap(int arr[], int n) {
	int startId = (n / 2) - 1;
	for (int i = startId; i >= 0; i--) 
		heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	int arr1[] = { 23, 5, 65, 34, 7, 14};
	int size = sizeof(arr1) / sizeof(arr1[0]);
	cout << "The output of bubble sort is: " << endl;
	bubbleSort(arr1, size); printarray(arr1, size);
	int arr2[] = { 23, 7, 63, 34, 9, 19};
	cout << "The output of optimized bubble sort is: " << endl;
	bubbleSortOpt(arr2, size); printarray(arr2, size);
	int arr3[] = { 23, 5, 65, 34, 7, 14};
	cout << "The output of selection sort is: " << endl;
	selectionSort(arr3, size); printarray(arr3, size);
	int arr4[] = { 23, 5, 65, 34, 7, 14};
	cout << "The output of insertion sort is: " << endl;
	insertionSort(arr4, size); printarray(arr4, size);
	int arr5[] = { 23, 5, 65, 34, 7, 14};
	cout << "The output of merge sort is: " << endl;
	mergeSort(arr5, 0, size - 1); printarray(arr5, size);

	int arr6[] = { 10, 7, 7, 9, 1, 5, 1, 10, 5, 7};
	int size6 = sizeof(arr6) / sizeof(arr6[0]);
	cout << "The output of quick sort is: " << endl;
	quickSort(arr6, 0, size6 - 1); printarray(arr6, size6);


	vector<int> arr11 = { 172, 45, 77, 91, 802, 27, 5, 66};
	cout << "The output of count sort is: " << endl;
	vector<int> out = countSort(arr11); printVector(out);

	vector<int> arr7 = { 170, 45, 75, 90, 802, 24, 2, 66};
	cout << "The output of shell sort is: " << endl;
	shellSort(arr7);
	printVector(arr7);

	int arr8[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr8)/sizeof(arr8[0]);
	cout << "The output of heap sort is: " << endl;
	heapSort(arr8, n); printarray(arr8, n);

	vector<float> arr9 = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
    bucketSort(arr9); 
    cout << "The output of bucket sort is: " << endl;
    for (int i = 0; i < arr9.size(); ++i) 
       cout << arr9[i] << ' '; 
    cout << endl;

	vector<int> arr10 = { 172, 45, 77, 91, 802, 27, 5, 66};
	cout << "The output of radix sort is: " << endl;
	radixSortAlt(arr10); //radixSort(arr6, n); 
    printVector(arr10); //printarray(arr6, n); 

    return 0;
}
