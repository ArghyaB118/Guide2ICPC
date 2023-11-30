/* LC#843
 
 You are given an array of unique strings words where words[i] is six letters long. One word of words was chosen as a secret word.
 
 You are also given the helper object Master. You may call Master.guess(word) where word is a six-letter-long string, and it must be from words. Master.guess(word) returns:

 -1 if word is not from words, or
 an integer representing the number of exact matches (value and position) of your guess to the secret word.
 There is a parameter allowedGuesses for each test case where allowedGuesses is the maximum number of times you can call Master.guess(word).

 For each test case, you should call Master.guess with the secret word without exceeding the maximum number of allowed guesses. You will get:

 "Either you took too many guesses, or you did not find the secret word." if you called Master.guess more than allowedGuesses times or if you did not call Master.guess with the secret word, or
 "You guessed the secret word correctly." if you called Master.guess with the secret word with the number of calls to Master.guess less than or equal to allowedGuesses.
 The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).

 Input: secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], allowedGuesses = 10
 Output: You guessed the secret word correctly.*/

void findSecretWord(vector<string>& words, Master& master) {
    vector<unordered_set<char>> v = {{},{},{},{},{},{}};
    vector<string> fives, fours, threes, twos, ones;
    bool guessing = false;
    for (auto i : words) {
        if (i.length() != 6)
            continue;
        else {
            guessing = true;
            for (int j = 0; j < 6; j++) {
                if (v[j].find(i[j]) != v[j].end())
                    guessing = false;
            }
            for (int j = 0; j < fives.size(); j++) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (fives[j][k] == i[k])
                        count++;
                }
                if (count != 5) {
                    guessing = false;
                    break;
                }
            }
            for (int j = 0; j < fours.size(); j++) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (fours[j][k] == i[k])
                        count++;
                }
                if (count != 4) {
                    guessing = false;
                    break;
                }
            }
            for (int j = 0; j < threes.size(); j++) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (threes[j][k] == i[k])
                        count++;
                }
                if (count != 3) {
                    guessing = false;
                    break;
                }
            }
            for (int j = 0; j < twos.size(); j++) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (twos[j][k] == i[k])
                        count++;
                }
                if (count != 2) {
                    guessing = false;
                    break;
                }
            }
            for (int j = 0; j < ones.size(); j++) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (ones[j][k] == i[k])
                        count++;
                }
                if (count != 1) {
                    guessing = false;
                    break;
                }
            }
            if (guessing) {
                int n = master.guess(i);
                if (n == 6)
                    return;
                else if (n == -1) {
                    for (int j = 0; j < 6; j++) {
                        v[j].insert(i[j]);
                    }
                }
                else if (n == 5)
                    fives.push_back(i);
                else if (n == 4)
                    fours.push_back(i);
                else if (n == 3)
                    threes.push_back(i);
                else if (n == 2)
                    twos.push_back(i);
                else if (n == 1)
                    ones.push_back(i);
            }
        }
    }
    return;
}
