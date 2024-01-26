/* LC#296

Given an m x n binary grid grid 
where each 1 marks the home of one friend, 
return the minimal total travel distance.

The total travel distance is the sum 
of the distances between the houses 
of the friends and the meeting point.

The distance is calculated using Manhattan Distance. 
*/

// when meeting points are only houses
int minTotalDistance(vector<vector<int>>& grid) {
	vector<vector<int>> friends;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1)
				friends.push_back({i, j});
		}
	}
	int total_distance = 0;
	for (int i = 0; i < friends.size(); i++) {
		int tmp = 0;
		for (int j = 0; j < friends.size(); j++) {
			tmp += abs(friends[i][0] - friends[j][0]) 
				+ abs(friends[i][1] - friends[i][1]);
		}
		total_distance = (total_distance == 0) ? tmp : min(tmp, total_distance);
	}
	return total_distance;
}

int minTotalDistance(vector<vector<int>>& grid) {
	vector<vector<int>> friends;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1)
				friends.push_back({i, j});
		}
	}
	if (friends.size() == 2)
		return abs(friends[0][0] - friends[1][0]) + abs(friends[0][1] - friends[1][1]);
	int avg_x = 0, avg_y = 0;
	for (auto &f : friends) {
		avg_x += f[0];
		avg_y += f[1];
	}
	avg_x /= friends.size();
	avg_y /= friends.size();
    // cout << avg_x << avg_y << endl;
	unsigned long distance = 0;
	for (auto &f : friends) {
		distance += abs(f[0] - avg_x) + abs(f[1] - avg_y);
	}
	vector<vector<int>> alternatives 
	= {{avg_x - 1, avg_y}, {avg_x + 1, avg_y}, 
	{avg_x, avg_y - 1}, {avg_x, avg_y + 1},
	{avg_x - 1, avg_y - 1}, {avg_x - 1, avg_y + 1}, 
	{avg_x + 1, avg_y - 1}, {avg_x + 1, avg_y + 1}};
	for (auto &p : alternatives) {
		if (p[0] >= 0 && p[0] < grid.size() && p[1] >= 0 && p[1] < grid[0].size()) {
			int tmp = 0;
			for (auto &f : friends) {
				tmp += abs(f[0] - p[0]) + abs(f[1] - p[1]);
			}
			distance = (distance > tmp) ? tmp : distance;
		}
	}
	return (int)distance;
}