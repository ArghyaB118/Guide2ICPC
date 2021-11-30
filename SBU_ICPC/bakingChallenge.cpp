#include <iostream>
using namespace std;

int main() {
	string seq = "ssccssccsc";
	std::sort(seq.begin(), seq.end()); cout << seq << " " << seq.length() << endl;
	if (seq.length() % 2 != 0) {
		if (seq[seq.length() % 2] == 'c')
			cout << "Cathy!" << endl;
		else if (seq[seq.length() % 2] == 's')
			cout << "Sally!" << endl;
		else
			cout << "Unknown." << endl;
	}
	else {
		if (seq[seq.length() % 2 - 1] == 'c' && seq[seq.length() % 2] == 'c')
			cout << "Cathy!" << endl;
		else if (seq[seq.length() % 2 - 1] == 's' && seq[seq.length() % 2] == 's')
			cout << "Sally!" << endl;
		else
			cout << "Tie!" << endl;
	}
	return 0;
}