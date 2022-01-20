/*
On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.

Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]

Input: n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
Output: [8]

Input: n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
Output: [8]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls itself again.
Function 0 (2nd recursive call) starts at the beginning of time 6 and executes for 1 unit of time.
Function 0 (initial call) resumes execution at the beginning of time 7 and executes for 1 unit of time.
So function 0 spends 2 + 4 + 1 + 1 = 8 units of total time executing.

Input: n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
Output: [7,1]
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> split(string s, char del) {
	vector<string> res;
	int start = 0, end = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == del) {
			res.push_back(s.substr(0, i));
			start = i + 1;
		}
	}
	res.push_back(s.substr(start, s.length()));
	return res;
}

vector<int> exclusiveTime(int n, vector<string>& logs) {
	vector<int> runtime;
	for (int i = 0; i < n; i++)
		runtime.push_back(0);
	stack<vector<string>> st;
	for (int i = 0; i < logs.size(); i++) {
		vector<string> tmp = split(logs[i], ':');
		if (st.empty())
			st.push(tmp);
		else {
			if (tmp[2] == "end") {
				vector<string> tmp2 = st.top();
				st.pop();
				runtime[stoi(tmp2[0])] += (stoi(tmp[2]) - stoi(tmp2[2]) + 1);
				if (!st.empty()) {
					vector<string> tmp3 = st.top();
					st.pop();
					tmp3[2] = tmp[2];
					st.push(tmp3);
				}
			}
			else if (tmp[2] == "start") {
				vector<string> tmp2 = st.top();
				st.pop();
				runtime[stoi(tmp2[0])] += (stoi(tmp[2]) - stoi(tmp2[2]) + 1);
				st.push(tmp2); st.push(tmp);
			}
	}
	return runtime;
}

int main() {
	int n = 2; 
	vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
	vector<int> result = exclusiveTime(n, logs);
	for (int & i : result)
		cout << i << " ";
	cout << endl;
	return 0;
}