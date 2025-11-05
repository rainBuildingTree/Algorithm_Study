#include <iostream>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<array<int, 3>> board(N);
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		board[i][0] = a;
		board[i][1] = b;
		board[i][2] = c;
	}

	vector<array<int, 3>> min_score(2);
	min_score[0][0] = board[0][0];
	min_score[0][1] = board[0][1];
	min_score[0][2] = board[0][2];
	min_score[1][0] = board[0][0];
	min_score[1][1] = board[0][1];
	min_score[1][2] = board[0][2];

	vector<array<int, 3>> max_score(2);
	max_score[0][0] = board[0][0];
	max_score[0][1] = board[0][1];
	max_score[0][2] = board[0][2];
	max_score[1][0] = board[0][0];
	max_score[1][1] = board[0][1];
	max_score[1][2] = board[0][2];

	for (int i = 1; i < N; ++i) {
		min_score[1][0] = board[i][0] + min(min_score[0][0], min_score[0][1]);
		min_score[1][1] = board[i][1] + min(min_score[0][0], min(min_score[0][1], min_score[0][2]));
		min_score[1][2] = board[i][2] + min(min_score[0][1], min_score[0][2]);

		max_score[1][0] = board[i][0] + max(max_score[0][0], max_score[0][1]);
		max_score[1][1] = board[i][1] + max(max_score[0][0], max(max_score[0][1], max_score[0][2]));
		max_score[1][2] = board[i][2] + max(max_score[0][1], max_score[0][2]);

		min_score[0][0] = min_score[1][0];
		min_score[0][1] = min_score[1][1];
		min_score[0][2] = min_score[1][2];

		max_score[0][0] = max_score[1][0];
		max_score[0][1] = max_score[1][1];
		max_score[0][2] = max_score[1][2];
	}

	cout << max(max_score[1][0], max(max_score[1][1], max_score[1][2])) << ' ';
	cout << min(min_score[1][0], min(min_score[1][1], min_score[1][2]));


	return 0;
}