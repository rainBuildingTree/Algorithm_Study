#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <array>
using namespace std;

struct Cheese {
	int melted_at = -1;
	int air_contact = 0;
};

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<Cheese>> paper(N, vector<Cheese>(M, Cheese()));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			int input;
			cin >> input;
			if (input == 0) paper[i][j].melted_at = 0;
		}
	
	queue<array<int, 3>> bfs_queue;
	int max_melted_at = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (i > 0 && paper[i-1][j].melted_at == 0)
				++paper[i][j].air_contact;
			if (i < N-1 && paper[i+1][j].melted_at == 0)
				++paper[i][j].air_contact;
			if (j > 0 && paper[i][j-1].melted_at == 0)
				++paper[i][j].air_contact;
			if (j < M-1 && paper[i][j+1].melted_at == 0)
				++paper[i][j].air_contact;
			
			if (paper[i][j].melted_at < 0 && paper[i][j].air_contact > 1) {
				bfs_queue.push({{i, j, 1}});
			}
		}
	}

	while (!bfs_queue.empty()) {
		int x = bfs_queue.front()[0];
		int y = bfs_queue.front()[1];
		int time = bfs_queue.front()[2];
		bfs_queue.pop();

		if (paper[x][y].melted_at >= 0)
			continue;
		if (paper[x][y].air_contact > 1)
			paper[x][y].melted_at = time;
		if (paper[x][y].melted_at < 0)
			continue;
		max_melted_at = max(max_melted_at, time);

		if (x > 0 && paper[x-1][y].melted_at < 0) {
			++paper[x-1][y].air_contact;
			if (paper[x-1][y].air_contact > 1)
				bfs_queue.push({{x-1, y, time+1}});
		}
		if (x < N-1 && paper[x+1][y].melted_at < 0) {
			++paper[x+1][y].air_contact;
			if (paper[x+1][y].air_contact > 1)
				bfs_queue.push({{x+1, y, time+1}});
		}
		if (y > 0 && paper[x][y-1].melted_at < 0) {
			++paper[x][y-1].air_contact;
			if (paper[x][y-1].air_contact > 1)
				bfs_queue.push({{x, y-1, time+1}});
		}
		if (y > 0 && paper[x][y+1].melted_at < 0) {
			++paper[x][y+1].air_contact;
			if (paper[x][y+1].air_contact > 1)
				bfs_queue.push({{x, y+1, time+1}});
		}
	}

	cout << max_melted_at;

	return 0;
}