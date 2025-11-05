#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> maze(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		string row;
		cin >> row;
		for (int j = 0; j < M; ++j)
			maze[i][j] = row[j] - '0';
	}

	
	vector<vector<vector<int>>> shortest(N, vector<vector<int>>(M, vector<int>(2, -1)));
	shortest[0][0][0] = 1;

	queue<array<int,3>> bfs_queue;
	bfs_queue.push({{0,0,0}});

	while (!bfs_queue.empty()) {
		int row = bfs_queue.front()[0];
		int col = bfs_queue.front()[1];
		int broke = bfs_queue.front()[2];
		int current = shortest[row][col][broke];
		bfs_queue.pop();

		if (row > 0) {
			if (maze[row-1][col] < 1 && shortest[row-1][col][broke] < 0) {
				shortest[row-1][col][broke] = current + 1;
				bfs_queue.push({{row-1, col, broke}});
			}
			if (maze[row-1][col] > 0 && broke < 1 && shortest[row-1][col][1] < 0) {
				shortest[row-1][col][1] = current + 1;
				bfs_queue.push({{row-1, col, 1}});
			}
		}
		if (row < N-1) {
			if (maze[row+1][col] < 1 && shortest[row+1][col][broke] < 0) {
				shortest[row+1][col][broke] = current + 1;
				bfs_queue.push({{row+1, col, broke}});
			}
			if (maze[row+1][col] > 0 && broke < 1 && shortest[row+1][col][1] < 0) {
				shortest[row+1][col][1] = current + 1;
				bfs_queue.push({{row+1, col, 1}});
			}
		}
		if (col > 0) {
			if (maze[row][col-1] < 1 && shortest[row][col-1][broke] < 0) {
				shortest[row][col-1][broke] = current + 1;
				bfs_queue.push({{row, col-1, broke}});
			}
			if (maze[row][col-1] > 0 && broke < 1 && shortest[row][col-1][1] < 0) {
				shortest[row][col-1][1] = current + 1;
				bfs_queue.push({{row, col-1, 1}});
			}
		}
		if (col < M-1) {
			if (maze[row][col+1] < 1 && shortest[row][col+1][broke] < 0) {
				shortest[row][col+1][broke] = current + 1;
				bfs_queue.push({{row, col+1, broke}});
			}
			if (maze[row][col+1] > 0 && broke < 1 && shortest[row][col+1][1] < 0) {
				shortest[row][col+1][1] = current + 1;
				bfs_queue.push({{row, col+1, 1}});
			}
		}
	}

	const int INF = 0x3fffffff;
	int shortest_without_break = shortest[N-1][M-1][0];
	int shortest_with_break = shortest[N-1][M-1][1];

	if (shortest_without_break < 0 && shortest_with_break < 0)
		cout << "-1\n";
	else {
		shortest_without_break = shortest_without_break < 0 ? INF : shortest_without_break;
		shortest_with_break = shortest_with_break < 0 ? INF : shortest_with_break;
		cout << min(shortest_without_break, shortest_with_break);
	}
	
	return 0;
}