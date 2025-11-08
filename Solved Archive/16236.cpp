#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <array>
using namespace std;

int main() {
	int N;
	cin >> N;

	pair<int, int> current_position;
	int current_time = 0;
	int shark_size = 2;
	int fish_count = 0;
	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				current_position = { i, j };
				map[i][j] = 0;
			}
		}

	while (true) {
		vector<vector<int>> visited(N, vector<int>(N, 0));
		queue<array<int, 3>> bfs_queue;
		bfs_queue.push({ {current_position.first, current_position.second, current_time} });
		visited[current_position.first][current_position.second] = 1;

		int fastest_time = 0x3fffffff;
		int closest_fish_r = -1;
		int closest_fish_c = -1;
		while (!bfs_queue.empty()) {
			int r = bfs_queue.front()[0];
			int c = bfs_queue.front()[1];
			int t = bfs_queue.front()[2];
			bfs_queue.pop();

			if (t >= fastest_time) break;

			if (r > 0 && !visited[r - 1][c]) {
				if (map[r - 1][c] > 0 && map[r - 1][c] < shark_size) {
					fastest_time = t + 1;
					if (closest_fish_r == -1) {
						closest_fish_r = r - 1;
						closest_fish_c = c;
					}
					else if (r - 1 < closest_fish_r) {
						closest_fish_r = r - 1;
						closest_fish_c = c;
					}
					else if (r - 1 == closest_fish_r && c < closest_fish_c) {
						closest_fish_r = r - 1;
						closest_fish_c = c;
					}
				}
				if (map[r - 1][c] == 0 || map[r - 1][c] == shark_size) {
					visited[r - 1][c] = 1;
					bfs_queue.push({ {r - 1, c, t + 1} });
				}
			}
			if (c > 0 && !visited[r][c - 1]) {
				if (map[r][c - 1] > 0 && map[r][c - 1] < shark_size) {
					fastest_time = t + 1;
					if (closest_fish_r == -1) {
						closest_fish_r = r;
						closest_fish_c = c - 1;
					}
					else if (r < closest_fish_r) {
						closest_fish_r = r;
						closest_fish_c = c - 1;
					}
					else if (r == closest_fish_r && c-1 < closest_fish_c) {
						closest_fish_r = r;
						closest_fish_c = c - 1;
					}
				}
				if (map[r][c - 1] == 0 || map[r][c - 1] == shark_size) {
					visited[r][c - 1] = 1;
					bfs_queue.push({ {r, c - 1, t + 1} });
				}
			}
			if (c < N - 1 && !visited[r][c + 1]) {
				if (map[r][c + 1] > 0 && map[r][c + 1] < shark_size) {
					fastest_time = t + 1;
					if (closest_fish_r == -1) {
						closest_fish_r = r;
						closest_fish_c = c + 1;
					}
					else if (r < closest_fish_r) {
						closest_fish_r = r;
						closest_fish_c = c + 1;
					}
					else if (r == closest_fish_r && c+1 < closest_fish_c) {
						closest_fish_r = r;
						closest_fish_c = c + 1;
					}
				}
				if (map[r][c + 1] == 0 || map[r][c + 1] == shark_size) {
					visited[r][c + 1] = 1;
					bfs_queue.push({ {r, c + 1, t + 1} });
				}
			}
			if (r < N - 1 && !visited[r + 1][c]) {
				if (map[r + 1][c] > 0 && map[r + 1][c] < shark_size) {
					fastest_time = t + 1;
					if (closest_fish_r == -1) {
						closest_fish_r = r + 1;
						closest_fish_c = c;
					}
					else if (r + 1 < closest_fish_r) {
						closest_fish_r = r + 1;
						closest_fish_c = c;
					}
					else if (r + 1 == closest_fish_r && c < closest_fish_c) {
						closest_fish_r = r + 1;
						closest_fish_c = c;
					}
				}
				if (map[r + 1][c] == 0 || map[r + 1][c] == shark_size) {
					visited[r + 1][c] = 1;
					bfs_queue.push({ {r + 1, c, t + 1} });
				}
			}
		}
		if (fastest_time == 0x3fffffff) break;
		fish_count++;
		if (shark_size == fish_count) {
			fish_count = 0;
			shark_size++;
		}
		current_position = { closest_fish_r, closest_fish_c };
		current_time = fastest_time;
		map[closest_fish_r][closest_fish_c] = 0;
	}

	cout << current_time;

	return 0;
}