#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int cheese_count = 0;
	vector<vector<int>> cheeses(N, vector<int>(M, 0));
	vector<vector<int>> map(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> cheeses[i][j];
			map[i][j] = cheeses[i][j];
			if (cheeses[i][j]) ++cheese_count;
		}

	int time = 0;
	while (cheese_count) {
		vector<vector<int>> visited(N, vector<int>(M, 0));
		queue<pair<int, int>> bfs_queue;
		bfs_queue.push({ 0,0 });
		map[0][0] = 2;

		while (!bfs_queue.empty()) {
			int r = bfs_queue.front().first;
			int c = bfs_queue.front().second;
			bfs_queue.pop();

			if (r > 0 && !visited[r - 1][c] && !cheeses[r - 1][c]) {
				map[r - 1][c] = 2;
				visited[r - 1][c] = 1;
				bfs_queue.push({ r - 1,c });
			}
			if (r < N - 1 && !visited[r + 1][c] && !cheeses[r + 1][c]) {
				map[r + 1][c] = 2;
				visited[r + 1][c] = 1;
				bfs_queue.push({ r + 1,c });
			}
			if (c > 0 && !visited[r][c - 1] && !cheeses[r][c - 1]) {
				map[r][c - 1] = 2;
				visited[r][c - 1] = 1;
				bfs_queue.push({ r,c - 1 });
			}
			if (c < M - 1 && !visited[r][c + 1] && !cheeses[r][c + 1]) {
				map[r][c + 1] = 2;
				visited[r][c + 1] = 1;
				bfs_queue.push({ r,c + 1 });
			}
		}

		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				if (!cheeses[r][c])
					continue;
				int air_count = 0;
				if (r > 0 && map[r - 1][c] == 2)
					++air_count;
				if (r < N - 1 && map[r + 1][c] == 2)
					++air_count;
				if (c > 0 && map[r][c - 1] == 2)
					++air_count;
				if (c < M - 1 && map[r][c + 1] == 2)
					++air_count;

				if (air_count > 1) {
					cheeses[r][c] = 0;
					--cheese_count;
				}
			}
		}

		++time;
	}

	cout << time;

	return 0;
}