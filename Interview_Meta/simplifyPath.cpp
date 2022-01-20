/*
cwd and target are inputs. return the final cwd.

cwd       target           return
/         a                /a
/b        /c               /c
/foo/bar  ../../../../..   /
/x/y      ../p/../q        /x/q
/x/y      /p/./q           /p/q
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// Idea: keep the last dir in a stack
// If .. pop the last element. If . continue
// If new string, push in stack
// If first item is /, ignore input cwd.

vector<string> split (string s, char del) {
  if (s.length() == 0)
    return {};
  int start = 0, end = 0;
  vector<string> v;
  while (end <= s.length()) {
    if (s[end] == del && end == 0) {
      start = end + 1;
    }
    else if (s[end] == del && end != 0) {
      if (end == start + 1)
        v.push_back(s.substr(start, end - 1));
      else
        v.push_back(s.substr(start, end));
      start = end + 1;
    }
    end++;
  }
  v.push_back(s.substr(start, end - 1));
  return v;
}

string finalPath (string cwd, string target) {
  stack<string> st;
  vector<string> cwds;
  if (target[0] != '/') {
    cwds = split(cwd, '/');
    for (auto & tmp : cwds) {
      st.push(tmp);
      // cout << tmp << endl;
    }
  }
  for (auto & tmp : cwds)
    cout << tmp << endl;
  cwds = split(target, '/');
  for (auto & tmp : cwds)
    cout << tmp << endl;

  for (int i = 0; i < cwds.size(); i++) {
    string last_dir = st.top();
    if (cwds[i] == ".." && !st.empty())
        st.pop();
    else if (cwds[i] != ".")
        st.push(cwds[i]); // x q
  }

  string result;
  while(!st.empty()) {
    result = result + st.top() + "/";
    st.pop();
  }
  if (result.length() == 0)
    return "/";
  

  return result;
/*  
  if (target[0] != '/')
    for (int i = 0; i < cwds.size(); i++)
      st.push(cwds[i]); // x y 
  
  
  
  cwds = target.substr(target.begin(), target.end(), '/');
  for (int i = 0; i < cwds.size(); i++) {
    last_dir = st.top();
    if (cwds[i] == ".." && !st.empty())
        st.pop();
    else if (cwds[i] != ".")
        st.push(cwds[i]); // x q
  }
  string result;
  while(!st.empty()) {
    result = result + st.top() + "/";
    st.pop();
  }
  if (result.length() == 0)
    return "/";
  reverse(result.begin(); result.end());
  return result;
*/
}

int main () {
  string cwd = "/x/y";
  string target = "../p/../q";
  cout << finalPath(cwd, target) << endl;
  return 0;
}
