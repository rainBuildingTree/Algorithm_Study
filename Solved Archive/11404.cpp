#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	const int INF = 20000001;
	vector<vector<int>> distance(n+1, vector<int>(n+1, INF));
	for (int i = 1; i < n+1; ++i)
		distance[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		distance[a][b] = min(c, distance[a][b]);
	}

	
	for (int i = 1; i < n+1; ++i)
		for (int j = 1; j < n+1; ++j)
			for (int k = 1; k < n+1; ++k)
				distance[j][k] = min(distance[j][k], distance[j][i] + distance[i][k]);

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			if (j-1) cout << ' ';
			cout << (distance[i][j] < INF ? distance[i][j] : 0);
		}
		cout << '\n';
	}

	return 0;
}