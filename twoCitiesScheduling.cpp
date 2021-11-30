#include <iostream>
#include <vector>
using namespace std;


int twoCityScheduleCost(vector<vector<int>>& costs) {
	int total_cost = 0, count_a = 0, count_b = 0, count_eq = 0;
	vector<int> diff1{}, diff2{};
	for (auto & i : costs) {
        if (i[0] == i[1])
            count_eq++;
        else {
        	(i[0] < i[1]) ? count_a++ : count_b++;
        	(i[0] > i[1]) ? diff1.push_back(i[0] - i[1]) : diff2.push_back(i[1] - i[0]);
        }
        total_cost += min(i[0], i[1]);
    }
	if (count_a == count_b)
    	return total_cost;
    else {
    	sort(diff1.begin(), diff1.end());
    	sort(diff2.begin(), diff2.end());
    	if (count_a > count_b)
    		for (int i = 0; i < (count_a - count_b - count_eq) / 2; i++)
                total_cost += diff2[i];
    	else
    		for (int i = 0; i < (count_b - count_a - count_eq) / 2; i++)
                total_cost += diff1[i];
    	return total_cost;
    }
}

int main() {
	vector<vector<int> > costs;
	//costs = {{518,518},{71,971},{121,862},{967,607},{138,754},{513,337},{499,873},{337,387},{647,917},{76,417}};
	costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
	for (auto & i : costs)
		cout << i[0] << " " << i[1] << endl;
	cout << twoCityScheduleCost(costs) << endl;
	return 0;
}