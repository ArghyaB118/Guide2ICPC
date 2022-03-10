#include <iostream>
#include <vector>
using namespace std;

class MinMaxStack {
public:
    int min = INT_MAX, max = INT_MIN;
    vector<int> s; 
    
    /** initialize your data structure here. */
    MinMaxStack() {
    }

    void push(int x) {
        s.push_back(x);
        if (x < min) {
            min = x;
        }
        if (x > max)
            max = x;
    }
    
    void pop() {
        if (s.size() != 0) {
            if (top() == min) {
                min = *min_element(s.begin(), s.end() - 1);
            }
            if (top() == max) {
                max = *max_element(s.begin(), s.end() - 1);
            }
            s.pop_back();
            if (s.size() == 0)
                min = INT_MAX;
            if (s.size() == 0)
                max = INT_MIN;
        }
    }
    
    int top() {
        return s[s.size() - 1]; // gets last element from the vector
    }
    
    int getMin() {
        return min;
    }
        
    int getMax() {
        return max;
    }
        
};

int main()
{
      MinMaxStack* ss = new MinMaxStack();

      ss->push(3);
      ss->push(7);
      int param_max = ss->getMax(); cout << param_max << endl;
      int param_min = ss->getMin(); cout << param_min << endl;
      ss->push(1);
      param_min = ss->getMin(); cout << param_min << endl;
      ss->push(2);
      int param = ss->top(); cout << param << endl;
      ss->pop();
      param = ss->top(); cout << param << endl;
      ss->pop();
      ss->pop();
      ss->pop();
      ss->pop();
      ss->getMin();
      
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */