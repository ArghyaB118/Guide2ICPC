#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string path) {
	stack<string> st;
	string tmp;
	for (int i = 0; i < path.length(); i++) {
		if (st.empty()) {
			tmp += path[i];
			st.push(tmp);
			tmp.clear();
		}
		else if (path[i] == '/') {
			if (st.top() == "/" && tmp == "")
				continue;
			else {
				if (tmp != "")
					st.push(tmp);
				tmp.clear();
				tmp += path[i];
				st.push(tmp);
				tmp.clear();
			}
		}
		else if (path[i] == '.') {
			if (i + 1 < path.length() && path[i + 1] != '.')
				continue;
			else if (i + 1 < path.length() && path[i + 1] == '.') {
				if (st.top() == "/") {
					st.pop(); 
					if (st.empty())
						return "/";
					else if (st.top() == "home")
						return "/home";
					else
						st.pop();
				}
				else
					st.pop();
				i = i + 2;
			}
		}
		else if (isalpha(path[i]))
			tmp += path[i];
	}
	if (tmp != "")
		st.push(tmp);
	if (st.top() == "/")
		st.pop();
	tmp.clear();
	while (!st.empty()) {
		tmp = st.top() + tmp;
		st.pop();
	}
	return tmp;
}

int main() {
	string path = "/../"; // "/home/../"; // "/home//foo/../"; // "/home//foo/";
	cout << simplifyPath (path) << endl;
	return 0;
}