/*
Passing Yearbooks

There are n students, numbered from 1 to n, each with their own yearbook.

They would like to pass their yearbooks around and get them signed by other students.
You're given a list of n integers arr[1..n], which is guaranteed to be a permutation 
of 1..n (in other words, it includes the integers from 1 to n exactly once each, 
in some order). The meaning of this list is described below.

Initially, each student is holding their own yearbook. The students will then repeat 
the following two steps each minute: Each student i will first sign the yearbook that 
they're currently holding (which may either belong to themselves or to another student), 
and then they'll pass it to student arr[i-1]. It's possible that arr[i-1] = i for any 
given i, in which case student i will pass their yearbook back to themselves. 
Once a student has received their own yearbook back, they will hold on to it and 
no longer participate in the passing process.

It's guaranteed that, for any possible valid input, each student will eventually receive 
their own yearbook back and will never end up holding more than one yearbook at a time.

You must compute a list of n integers output, whose element at i-1 is equal to the number 
of signatures that will be present in student i's yearbook once they receive it back.

Example:

Consider that each student is a member of a single yearbook passing cycle.
For example, for input [3, 2, 4, 1], there are two yearbook passing cycles: 
{3, 4, 1} and {2}.
Therefore, the number of signatures for each member of a passing cycle 
is equal to the size of the cycle.
In the example, students {3, 4, 1} each get 3 signatures (1 for his/her self, 
and 1 for the other 2 students), and student {2} gets 1 signature, his/her own signature.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findSignatureCounts (vector<int> arr) {
	vector<int> counts;
	// Write your code here
	for (int i = 0; i < arr.size(); i++) {
		int count = 1, index_pos = arr[i] - 1;
		while (index_pos != i) {
			count++;
			index_pos = arr[index_pos] - 1;
		}
		counts.push_back(count);
	}
	return counts;
}

int main() {
	vector<int> v{3,2,4,1};
	v = findSignatureCounts(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}
