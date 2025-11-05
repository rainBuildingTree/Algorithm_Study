#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_safe(const vector<int>& queens, const int row, const int col) {
	for (int i = 0; i < row; ++i)
		if (col == queens[i] || abs(row - i) == abs(col - queens[i]))
			return false;
	return true;
}

int nqueen(const int N, const int row, vector<int>& queens) {
	if (row == N) return 1;
	
	int count = 0;
	for (int i = 0; i < N; ++i) {
		if (!is_safe(queens, row, i))
			continue;
		queens[row] = i;
		count += nqueen(N, row+1, queens);
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> queens(N, -1);
	cout << nqueen(N, 0, queens);

	return 0;
}