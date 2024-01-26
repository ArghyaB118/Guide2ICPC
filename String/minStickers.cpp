/* LC#691

We are given n different types of stickers. 
Each sticker has a lowercase English word on it.

You would like to spell out the given string target 
by cutting individual letters from your 
collection of stickers and rearranging them. 
You can use each sticker more than once if you want, 
and you have infinite quantities of each sticker.

Return the minimum number of stickers 
that you need to spell out target. 
If the task is impossible, return -1.

Note: In all test cases, 
all words were chosen randomly 
from the 1000 most common US English words, 
and target was chosen 
as a concatenation of two random words.
*/

int minStickers (vector<string>& stickers, string target) {
	unordered_map<char, int> target_char_count;
	vector<unordered_map<char, int>> stickers_char_count(stickers.size(), target_char_count);
	for (auto& t : target) {
		if (target_char_count.find(t) == target_char_count.end())
			target_char_count[t] = 1;
		else
			target_char_count[t]++;
	}
	for (int i = 0; i < stickers.size(); i++) {
		for (auto &j : stickers[i]) {
			if (target_char_count.find(j) != target_char_count.end())
				if (stickers_char_count[i].find(j) == stickers_char_count[i].end())
					stickers_char_count[i][j] = 1;
				else
					stickers_char_count[i][j]++;
		}
	}
}