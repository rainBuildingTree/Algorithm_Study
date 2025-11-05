#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	vector<int> item_count(n+1, 0);
	for (int i = 1; i < n+1; ++i)
		cin >> item_count[i];

	const int INF = 0x3fffffff;
	vector<vector<int>> distance(n+1, vector<int>(n+1, INF));
	for (int i = 0; i < r; ++i) {
		int a, b, l;
		cin >> a >> b >> l;
		distance[a][b] = l;
		distance[b][a] = l;
	}
	for (int i = 1; i < n+1; ++i)
		distance[i][i] = 0;

	for (int mid = 1; mid < n+1; ++mid)
		for (int start = 1; start < n+1; ++start)
			for (int end = 1; end < n+1; ++end)
				if (distance[start][end] > distance[start][mid] + distance[mid][end])
					distance[start][end] = distance[start][mid] + distance[mid][end];
	
	int max_item_count = 0;
	for (int i = 1; i < n+1; ++i) {
		int current_item_count = 0;
		for (int j = 1; j < n+1; ++j) {
			if (distance[i][j] <= m)
				current_item_count += item_count[j];
		}
		max_item_count = max(max_item_count, current_item_count);
	}
	
	cout << max_item_count;

	return 0;
}