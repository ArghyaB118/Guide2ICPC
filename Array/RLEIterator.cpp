/* LC#900
 
 We can use run-length encoding (i.e., RLE) to encode a sequence of integers. In a run-length encoded array of even length encoding (0-indexed), for all even i, encoding[i] tells us the number of times that the non-negative integer value encoding[i + 1] is repeated in the sequence.
 
 For example, the sequence arr = [8,8,8,5,5] can be encoded to be encoding = [3,8,2,5]. encoding = [3,8,0,9,2,5] and encoding = [2,8,1,8,2,5] are also valid RLE of arr.
 Given a run-length encoded array, design an iterator that iterates through it.

 Implement the RLEIterator class:

 RLEIterator(int[] encoded) Initializes the object with the encoded array encoded.
 int next(int n) Exhausts the next n elements and returns the last element exhausted in this way. If there is no element left to exhaust, return -1 instead.*/

#include <iostream>
#include <vector>
using namespace std;

class RLEIterator {
private:
    int exhausted = 0, size = 0;
    vector<int> coding;
public:
    RLEIterator(vector<int>& encoding) {
        for (int i = 0; i < encoding.size(); i = i + 2) {
            if (encoding[i] != 0) {
                this->coding.push_back(encoding[i]);
                this->coding.push_back(encoding[i + 1]);
                this->size += encoding[i];
            }
        }
        /*int tmp = 0;
        for (int i = 0; i < encoding.size(); i + 2) {
            tmp += encoding[i];
            encoding[i] = tmp;
        }*/
    }
    
    int next(int n) {
        if (n == 0)
            return this->coding[1];
        else if (n + this->exhausted > this->size)
            return -1;
        
        int i = 0;
        this->exhausted += n;
        n = this->exhausted;
        while (n > 0) {
            n -= this->coding[i];
            exhausted += this->coding[i];
            i += 2;
        }
        return this->coding[i + 1];
    }
};

int main () {
    vector<int> encoding = {2,8,1,8,2,5}; // 8 8 8 5 5
    RLEIterator* obj = new RLEIterator(encoding);
    cout << obj->next(2) << endl;
    cout << obj->next(2) << endl;
    cout << obj->next(1) << endl;
    cout << obj->next(2) << endl;
    return 0;
}
/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
