#include <iostream>
#include <string.h>
#include <map>
using namespace std;

// Linear time solution. Uses a custom hash table based on the ascii values
void countSort (char arr[]) {
	cout << arr << endl;
	char output[strlen(arr)]; // the output string, space = O(n)
	int count[256]; // to store the ascii counts, space = O(1)
	memset(count, 0, sizeof(count));
	for (int i = 0; i < strlen(arr); i++)
		count[arr[i]]++; // store the counts
    
    for (int i = 0; i < 256; i++)
        cout << count[i] << " ";
    cout << endl;
    
	for (int i = 1; i < 256; i++)
		count[i] += count[i - 1]; // store the cumulative counts
    
    /*for (int i = 0; i < 256; i++)
        cout << count[i] << " ";
    cout << endl;*/
    
	for (int i = 0; i < strlen(arr); i++) {
		output[count[arr[i]] - 1] = arr[i]; // places the 'g' in 6th position.
		count[arr[i]]--; // reduce the counter at 5, so that next time 'g' is placed in the 4th position.
	}
    
    for (int i = 0; i < 256; i++)
        cout << count[i] << " ";
    cout << endl;
    
	cout << output << endl;
}

/*
 Input: string
 Idea: Use a map to keep the count.
 Note: Map already sorts by the keys.
 Each Lookup and insert cost: O(log n)
 Overall cost: O(n log n)
 */
string countSortMap (string word) {
    map <char, int> m;
    for (auto ch : word) {
        if (m.find(ch) != m.end())
            m[ch]++;
        else
            m[ch] = 1;
    }
    word = "";
    for (auto i : m) {
        for (int j = 0; j < i.second; j++)
            word.push_back(i.first);
    }
    return word;
}


int main() {
	char arr[] = "geeksforgeeks";
	countSort(arr);
    
    string word = "geeksforgeeks";
    cout << countSortMap(word) << endl;
	return 0;
}
