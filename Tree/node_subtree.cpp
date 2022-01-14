/*
Nodes in a Subtree
You are given a tree that contains N nodes, each containing an integer u which corresponds to a lowercase character c in the string s using 1-based indexing.
You are required to answer Q queries of type [u, c], where u is an integer and c is a lowercase letter. The query result is the number of nodes in the subtree of node u containing c.
Signature
int[] countOfNodes(Node root, ArrayList<Query> queries, String s)
Input
A pointer to the root node, an array list containing Q queries of type [u, c], and a string s
Constraints
N and Q are the integers between 1 and 1,000,000
u is a unique integer between 1 and N
s is of the length of N, containing only lowercase letters
c is a lowercase letter contained in string s
Node 1 is the root of the tree
Output
An integer array containing the response to each query
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> children;
  
  Node() {
    val = 0;
    children = vector<Node*>();
  }
  
  Node(int _val) {
    val = _val;
    children = vector<Node*>();
  }
  
  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

struct Query {
  int u; 
  char c; 
};

// Add any helper functions you may need here


vector<int> countOfNodes(Node* root, vector<Query> queries, string s) {
  vector<int> counts;
  for (int i = 0; i < queries.size(); i++) {
    int count = 0;
    queue<Node*> q; q.push(root);
    while (root->val != queries[i].u) {
      Node* root = q.front(); q.pop();
      for (int j = 0; j < root->children.size(); j++)
        q.push(root->children[j]);
    }
    root = q.front(); 
    queue<Node*> q2; q2.push(root);
    while (!q2.empty()) {
      root = q2.front(); q2.pop();
      if (s[root->val - 1] == queries[i].c)
        count++;
      for (int j = 0; j < root->children.size(); j++)
        q2.push(root->children[j]);
    }
    counts.push_back(count);
  }
  return counts;
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

  // Testcase 1
  int n_1 = 3, q_1 = 1;
  string s_1 = "aba";
  Node *root_1 = new Node(1);
  root_1->children.push_back(new Node(2)); 
  root_1->children.push_back(new Node(3));  
  vector<Query> queries_1{{1,'a'}};
  vector<int> output_1 = countOfNodes(root_1, queries_1, s_1); 
  vector<int> expected_1 = {2};
  check(expected_1, output_1); 
  
  // Testcase 2
  int n_2 = 7, q_2 = 3;
  string s_2 = "abaacab";
  Node *root_2 = new Node(1); 
  root_2->children.push_back(new Node(2)); 
  root_2->children.push_back(new Node(3)); 
  root_2->children.push_back(new Node(7)); 
  root_2->children[0]->children.push_back(new Node(4)); 
  root_2->children[0]->children.push_back(new Node(5)); 
  root_2->children[1]->children.push_back(new Node(6));  
  vector<Query> queries_2{{1,'a'}, {2, 'b'}, {3, 'a'}};
  vector<int> output_2 = countOfNodes(root_2, queries_2, s_2); 
  vector<int> expected_2 = {4, 1, 2};
  check(expected_2, output_2); 

  // Add your own test cases here
  return 0;  
}
