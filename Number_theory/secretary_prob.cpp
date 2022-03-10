#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
#define num 20
#define e 2.71828

int roundnumber(float n) {
	float fractpart, intpart;
	fractpart = modf (n , &intpart);
	return fractpart < 0.5 ? intpart : intpart + 1;
}

void printBestCandidate(int candidate[]) {
	int sample_size = roundnumber(num / e);
	cout << "The sample size is: " << sample_size << endl;
	int best = 0;  
    for (int i = 1; i < sample_size; i++) 
        if (candidate[i] > candidate[best]) 
            best = i; 
    for (int i = sample_size; i < num; i++) 
        if (candidate[i] >= candidate[best]) { 
            best = i; 
            break; 
        }
    if (best >= sample_size) 
        cout << endl << "Best candidate: " << best + 1 << " Talent: " << candidate[best] << endl; 
    else
        cout << "Couldn't find a best candidate\n";
}

int main() {
	int candidate[num];
	srand(time(0));
	for (int i = 0; i < num; i++) {
		candidate[i] = rand() % 100;
	}
	cout << "Candidate : Talents\n"; 
    for (int i = 0; i < num; i++) 
        cout << i + 1 << "\t" << candidate[i] << "\n"; 
    cout << endl;
    printBestCandidate(candidate);
}

