/*
Largest Triple Products
You're given a list of n integers arr[0..(n-1)]. You must compute a list output[0..(n-1)] such that, for each index i (between 0 and n-1, inclusive), output[i] is equal to the product of the three largest elements out of arr[0..i] (or equal to -1 if i < 2, as arr[0..i] then includes fewer than three elements).
Note that the three largest elements used to form any product may have the same values as one another, but they must be at different indices in arr.

Example 1
n = 5
arr = [1, 2, 3, 4, 5]
output = [-1, -1, 6, 24, 60]
The 3rd element of output is 3*2*1 = 6, the 4th is 4*3*2 = 24, and the 5th is 5*4*3 = 60.
Example 2
n = 5
arr = [2, 1, 2, 1, 2]
output = [-1, -1, 4, 4, 8]
The 3rd element of output is 2*2*1 = 4, the 4th is 2*2*1 = 4, and the 5th is 2*2*2 = 8.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMaxProduct(vector<int> arr) {
  // Write your code here
  if (arr.size() == 0)
    return {};
  else if (arr.size() == 1)
    return {-1};
  else if (arr.size() == 2)
    return {-1, -1};
  else if (arr.size() == 3)
    return {-1, -1, arr[0] * arr[1] * arr[2]};
  vector<int> output{-1, -1, arr[0] * arr[1] * arr[2]};
  
  vector<int> max_elts;
  max_elts.push_back(arr[0]); max_elts.push_back(arr[1]); max_elts.push_back(arr[2]);
  sort(max_elts.begin(), max_elts.end());
  
  for (int i = 3; i < arr.size(); i++) {
    if (arr[i] <= max_elts[0])
      output.push_back(max_elts[0] * max_elts[1] * max_elts[2]);
    else {
      max_elts[0] = arr[i];
      sort(max_elts.begin(), max_elts.end());
      output.push_back(max_elts[0] * max_elts[1] * max_elts[2]);
    }
  }
  return output;
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
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  vector <int> arr_1{1, 2, 3, 4, 5};
  vector <int> expected_1{-1, -1, 6, 24, 60};
  vector <int> output_1 = findMaxProduct(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{-1, -1, 56, 56, 140, 140};
  vector <int> output_2 = findMaxProduct(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}