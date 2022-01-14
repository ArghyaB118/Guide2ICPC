/*
Queue Removals
You're given a list of n integers arr, which represent elements in a queue (in order from front to back). You're also given an integer x, and must perform x iterations of the following 3-step process:
Pop x elements from the front of queue (or, if it contains fewer than x elements, pop all of them)
Of the elements that were popped, find the one with the largest value (if there are multiple such elements, take the one which had been popped the earliest), and remove it
For each one of the remaining elements that were popped (in the order they had been popped), decrement its value by 1 if it's positive (otherwise, if its value is 0, then it's left unchanged), and then add it back to the queue
Compute a list of x integers output, the ith of which is the 1-based index in the original array of the element which had been removed in step 2 during the ith iteration.

nput
x is in the range [1, 316].
n is in the range [x, x*x].
Each value arr[i] is in the range [1, x].
Output
Return a list of x integers output, as described above.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int run_experiment(vector<int>& arr, int x) {
	cout << arr.size() << " " << x << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	int max_elt_index = 0, max_elt = arr[0];
	queue<int> q; 
	for (int i = 0; i < x; i++) {
		q.push(arr[0]);
		if (arr[0] > max_elt) {
			max_elt = arr[0];
			max_elt_index = i;
		}
		arr.pop_back();
	}
	int count = 0;
	while (!q.empty()) {
		if (count != max_elt_index)
			(q.front() >= 1) ? arr.push_back(q.front() - 1) : arr.push_back(q.front());				
		q.pop();
		count++;
	}
	return max_elt_index;
}

vector <int> findPositions(vector <int> arr, int x) {
	vector<int> v;
	for (int i = 0; i < x; i++) 
		v.push_back(run_experiment(arr, x));
	return v;
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << " Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  int n_1 = 6;
  int x_1 = 5;
  vector <int> arr_1{1, 2, 2, 3, 4, 5};
  vector <int> expected_1{5, 6, 4, 1, 2 };
  vector <int> output_1 = findPositions(arr_1, x_1);
  check(expected_1, output_1);

  int n_2 = 13;
  int x_2 = 4;
  vector <int> arr_2{2, 4, 2, 4, 3, 1, 2, 2, 3, 4, 3, 4, 4};
  vector <int> expected_2{2, 5, 10, 13};
  vector <int> output_2 = findPositions(arr_2, x_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}