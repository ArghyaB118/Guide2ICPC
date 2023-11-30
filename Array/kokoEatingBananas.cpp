/* LC#875

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

#include <iostream>
#include <vector>
using namespace std;

bool canEat (vector<int>& piles, int h, int k) {
	int tmp = 0;
	for (auto & pile : piles) {
		tmp += (pile % k != 0) ? pile / k + 1 : pile / k;
		// cout << tmp << " ";
	}
	// cout << k << endl;
	if (tmp <= h)
		return true;
	return false;
}

int binarySearch (vector<int>& piles, int h, int k_min, int k_max) {
	if (k_max == k_min + 1) {
		if (canEat (piles, h, k_min))
			return k_min;
		return k_max;
	}
	if (canEat (piles, h, k_min + (k_max - k_min) / 2))
		return binarySearch (piles, h, k_min, k_min + (k_max - k_min) / 2);
	return binarySearch (piles, h, k_min + (k_max - k_min) / 2, k_max);
}

int minEatingSpeed (vector<int>& piles, int h) {
	int n = piles.size();
	if (n > h)
		return -1;
	else if (n == h)
		return *max_element(piles.begin(), piles.end());
	int k = *max_element(piles.begin(), piles.end());
	// linear search from the highest to the right value
	// takes too much time
	/*while (canEat (piles, h, k) == true) {
		k--;
	}
	return k + 1*/
	return binarySearch (piles, h, 1, k);
}

int main () {
	vector<int> piles = {3,6,7,11}; // {30,11,23,4,20}; //
	int h = 8; // 6; // 8;
	cout << minEatingSpeed (piles, h) << endl;
	return 0;
}