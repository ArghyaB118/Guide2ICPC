/* LC#692
 
 Given an array of strings words and an integer k, return the k most frequent strings.
 
 Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
 
 Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 Output: ["i","love"]
 Explanation: "i" and "love" are the two most frequent words.
 Note that "i" comes before "love" due to a lower alphabetical order.
 
 Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 Output: ["the","is","sunny","day"]
 Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
typedef pair<string, int> Pair;

vector<string> topKFrequent (vector<string>& words, int k) {
    unordered_map<string, int> hashmap;
    for (auto i : words) {
        if (hashmap.find(i) != hashmap.end())
            hashmap[i]++;
        else
            hashmap[i] = 1;
    }
    priority_queue<int> pq;
    for (auto i : hashmap)
        pq.push(i.second);
    while (k > 0) {
        cout << pq.top() << endl;
        k--;
        pq.pop();
    }
    return {};
}

int main () {
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string> result = topKFrequent (words, k);
    for (auto i : result)
        cout << i << endl;
    return 0;
}
