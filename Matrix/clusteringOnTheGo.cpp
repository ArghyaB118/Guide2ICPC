#include <iostream>
#include <vector>
using namespace std;

#define pixel_lit 100

// not the best
// need to traverse the image twice
int make_cluster_dfs 
	(vector<vector<int>> &img, int n, int max_cluster_size) {
	int cluster_id = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (img[i][j] == pixel_lit) {
				for (int k = 0; k < max_cluster_size; k++) {
					for (int l = - max_cluster_size + 1; 
						l < max_cluster_size; 
						l++) {
						if (img[i + k][j + l] == pixel_lit)
							img[i + k][j + l] = cluster_id;
					}
				}
				cluster_id++;
			}
		}
	}
	return cluster_id - 1;
}

vector<vector<int>> maxPool 
	(vector<vector<int>> &img, int n, int base_size) {
	vector<vector<int>> 
		pooled_img(n / base_size, vector<int>(n / base_size, 0));
	for (int i = 0; i < n / base_size; i++) {
		for (int j = 0; j < n / base_size; j++) {
			for (int k = 0; k < base_size; k++) {
				for (int l = 0; l < base_size; l++) {
					pooled_img[i][j] 
						= max(pooled_img[i][j], 
							img[i * base_size + k][j + base_size + l]);
				}
			}
		}
	}
	return pooled_img;
}

vector<int> medians;
int clustering_pooling 
	(vector<vector<int>> &img, int n, int max_cluster_size) {
		int base_size = 2;
	vector<vector<int>> pooled_img = maxPool (img, n, base_size);
	for (int i = 0; i < n / base_size; i++) {
		for (int j = 0; j < n / base_size; j++) {
			if (pooled_img[i][j] > 0) {
				//
			}
		}
	}
}

void printImage (vector<vector<int>> &img, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << img[i][j] << " ";
		}
		cout << endl;
	}
}

int main () {
	int n = 32;
	int max_cluster_size = 3;
	vector<vector<int>> img(n, vector<int>(n, 0));
	// cluster 1
	img[3][3] = pixel_lit; img[3][4] = pixel_lit; img[3][5] = pixel_lit;
	img[4][4] = pixel_lit;
	img[5][3] = pixel_lit; img[5][4] = pixel_lit; img[5][5] = pixel_lit;
	// cluster 2
	img[12][12] = pixel_lit; img[12][13] = pixel_lit;
	img[13][12] = pixel_lit; img[13][13] = pixel_lit;
	// cluster 3
	img[15][10] = pixel_lit;
	img[16][9] = pixel_lit; img[16][10] = pixel_lit; img[16][11] = pixel_lit;
	img[17][10] = pixel_lit;
	printImage(img, n);
	cout << "Number of clusters: " 
		<< make_cluster_dfs(img, n, max_cluster_size) << endl;
	printImage(img, n);
	return 0;
}