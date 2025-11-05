#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

int longest_path(const vector<vector<char>>& board,
vector<vector<bool>>& visited, const int r, const int c,
vector<bool>& alphabet_visited
) {
	const int R = (int)board.size();
	const int C = (int)board[0].size();
	if (r < 0 || r >= R || c < 0 || c >= C) return 0;
	if (visited[r][c]) return 0;
	if (alphabet_visited[board[r][c]-'A']) return 0;
	visited[r][c] = true;
	alphabet_visited[board[r][c]-'A'] = true;

	int max_path = 0;
	if (r > 0 && !visited[r-1][c] && !alphabet_visited[board[r-1][c]-'A']) {
		max_path = max(max_path, longest_path(board, visited, r-1, c, alphabet_visited));
		visited[r-1][c] = false;
		alphabet_visited[board[r-1][c]-'A'] = false;
	}
	if (r < R-1 && !visited[r+1][c] && !alphabet_visited[board[r+1][c]-'A']) {
		max_path = max(max_path, longest_path(board, visited, r+1, c, alphabet_visited));
		visited[r+1][c] = false;
		alphabet_visited[board[r+1][c]-'A'] = false;
	}
	if (c > 0 && !visited[r][c-1] && !alphabet_visited[board[r][c-1]-'A']) {
		max_path = max(max_path, longest_path(board, visited, r, c-1, alphabet_visited));
		visited[r][c-1] = false;
		alphabet_visited[board[r][c-1]-'A'] = false;
	}
	if (c < C-1 && !visited[r][c+1] && !alphabet_visited[board[r][c+1]-'A']) {
		max_path = max(max_path, longest_path(board, visited, r, c+1, alphabet_visited));
		visited[r][c+1] = false;
		alphabet_visited[board[r][c+1]-'A'] = false;
	}
	return max_path + 1;

	
}

int main() {
	int R, C;
	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C));
	for (int r = 0; r < R; ++r) {
		string input;
		cin >> input;
		for (int c = 0; c < C; ++c)
			board[r][c] = input[c];
	}

	vector<vector<bool>> visited(R, vector<bool>(C, false));
	vector<bool> alphabet_visited(26, false);
	cout << longest_path(board, visited, 0, 0, alphabet_visited);
	
	return 0;
}