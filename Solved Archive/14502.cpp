#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

void get_combinations(vector<vector<pair<int,int>>>& combinations, 
	vector<pair<int,int>>& combination, const vector<vector<int>>& map,
	const int depth, const int max_depth = 3) {
	if (depth == max_depth) {
		combinations.push_back(combination);
		return;
	}

	int r, c;
	if (depth == 0) {
		r = -1; c = -1;
	}
	else {
		r = combination[depth-1].first;
		c = combination[depth-1].second;
	}

	const int N = (int)map.size();
	const int M = (int)map[0].size();
	if (r >= 0)
		for (int i = c+1; i < M; ++i) {
			if (map[r][i] != 0) continue;
			combination[depth] = {r,i};
			get_combinations(combinations, combination, map, depth+1, max_depth);
		}

	for (int i = r+1; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (map[i][j] != 0) continue;
			combination[depth] = {i,j};
			get_combinations(combinations, combination, map, depth+1, max_depth);
		}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int,int>> infected;
	vector<pair<int,int>> walls;
	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				walls.push_back({i,j});
			else if (map[i][j] == 2)
				infected.push_back({i,j});
		}

	vector<vector<pair<int,int>>> combinations;
	combinations.reserve(20000);
	vector<pair<int,int>> empty_combination(3);
	get_combinations(combinations, empty_combination, map, 0, 3);
	
	int max_unvisited = 0;
	for (const vector<pair<int,int>> combination : combinations) {
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		queue<pair<int,int>> bfs_queue;

		for (const pair<int,int> wall : combination) {
			map[wall.first][wall.second] = 1;
			visited[wall.first][wall.second] = true;
		}

		for (const pair<int,int> wall : walls)
			visited[wall.first][wall.second] = true;

		for (const pair<int,int> infect : infected) {
			visited[infect.first][infect.second] = true;
			bfs_queue.push({infect.first, infect.second});
		}

		while (!bfs_queue.empty()) {
			int r = bfs_queue.front().first;
			int c = bfs_queue.front().second;
			bfs_queue.pop();

			if (r > 0 && !visited[r-1][c]) {
				visited[r-1][c] = true;
				bfs_queue.push({r-1,c});
			}
			if (r < N-1 && !visited[r+1][c]) {
				visited[r+1][c] = true;
				bfs_queue.push({r+1,c});
			}
			if (c > 0 && !visited[r][c-1]) {
				visited[r][c-1] = true;
				bfs_queue.push({r,c-1});
			}
			if (c < M-1 && !visited[r][c+1]) {
				visited[r][c+1] = true;
				bfs_queue.push({r,c+1});
			}
		}

		int unvisited_count = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) 
				if (!visited[i][j])
					++unvisited_count;

		max_unvisited = max(max_unvisited, unvisited_count);

		for (const pair<int,int> wall : combination)
			map[wall.first][wall.second] = 0;
	}
	
	cout << max_unvisited;

	return 0;
}