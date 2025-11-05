#include <iostream>
#include <map>
#include <array>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> house(N+1, vector<int>(N+1, 0));
	for (int i = 1; i < N+1; ++i)
		for (int j = 1; j < N+1; ++j)
			cin >> house[i][j];
	
	vector<vector<vector<int>>> memo(N+1, vector<vector<int>>(N+1, vector<int>(3, 0)));
	memo[1][2][0] = 1;

	for (int row = 1; row < N+1; ++row)
		for (int col = 1; col < N+1; ++col) {
			if (house[row][col]) continue;

			if (!memo[row][col][0])
				memo[row][col][0] = memo[row][col-1][0] + memo[row][col-1][2];
			memo[row][col][1] = memo[row-1][col][1] + memo[row-1][col][2];
			
			if (house[row-1][col] || house[row][col-1]) continue;
			memo[row][col][2] = memo[row-1][col-1][0] + memo[row-1][col-1][1] + memo[row-1][col-1][2];
		}
	
	cout << memo[N][N][0] + memo[N][N][1] + memo[N][N][2];

	return 0;
}