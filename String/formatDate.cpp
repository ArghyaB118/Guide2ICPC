// from: 2nd Jul 1993 to: 1993-07-02
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split (string date) {
	vector<string> s;
	string tmp;
	for (int i = 0; i < date.length(); i++) {
		if (date[i] != ' ')
			tmp.push_back(date[i]);
		else {
			s.push_back(tmp);
			tmp.clear();
		}
	}
	s.push_back(tmp); // get the last item in
	// work on the reformatting of date
	tmp.clear();
	for (int i = 0; i < s[0].length(); i++) {
		if (isdigit(s[0][i]))
			tmp.push_back(s[0][i]);
		else {
			s[0] = tmp;
			tmp.clear();
		}
	}
	// work on reformatting of month
	vector<string> months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	for (int i = 0; i < months.size(); i++)
		if (s[1] == months[i])
			s[1] = to_string(i + 1);
	// take care of one digit month and date
	tmp.clear(); tmp = "0";
	if (s[0].length() == 1) {
		tmp = tmp.append(s[0]);
		s[0] = tmp;
	}
	tmp.clear(); tmp = "0";
	if (s[1].length() == 1) {
		tmp = tmp.append(s[1]);
		s[1] = tmp;
	}
	return s;
}

int main () {
	string date = "2nd Oct 2052";
	vector<string> v = split(date);
	string reformatted_date = "";
	reformatted_date.append(v[2]);
	reformatted_date.push_back('-');
	reformatted_date.append(v[1]);
	reformatted_date.push_back('-');
	reformatted_date.append(v[0]);
	cout << reformatted_date << endl;
	return 0;
}