#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 
int numOfTweets (int tweetCat, int userID) {
	int answer = 0;
	if (userID < 10) 
		answer = 1 ? userID == tweetCat : 0;
	else {
		while (userID >= 10) {
			int temp = userID % 10;
			userID /= 10;
			if (temp == tweetCat)
				answer++;
		}
		if (userID == tweetCat)
			answer++;
	}
	return answer;
}

int main () {
	int tweetCat = 5;
	int userID = 55555555;
	int result = numOfTweets(tweetCat, userID);
	cout << result << endl;
	return 0;
}

