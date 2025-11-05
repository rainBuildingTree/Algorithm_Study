#include <iostream>
#include <vector>

using namespace std;

void print_vec(const vector<vector<int>>& vec2print) {
	int r_size = (int)vec2print.size();
	int c_size = (int)vec2print[0].size();

	for (int i = 1; i < r_size; ++i) {
		for (int j = 1; j < c_size; ++j) {
			if (j) cout << ' ';
			cout << vec2print[i][j];
		}
		cout << '\n';
	}
}

int main() {
	int R, C, T;
	cin >> R >> C >> T;

	int current_status = 0;
	vector<vector<vector<int>>> status(3, vector<vector<int>>(R+1, vector<int>(C+1, 0)));

	int purifier_col = 1;
	int purifier_row_up, purifier_row_down;
	for (int i = 1; i < R+1; ++i)
		for (int j = 1; j < C+1; ++j) {
			cin >> status[0][i][j];
			if (status[0][i][j] == -1) {
				status[1][i][j] = -1;
				status[2][i][j] = -1;
				purifier_row_down = i;
			}
		}
	purifier_row_up = purifier_row_down-1;

	for (int t = 0; t < T; ++t) {
		for (int i = 1; i < R+1; ++i)
			for (int j = 1; j < C+1; ++j) {
				if (t == 0) break;
				status[0][i][j] = status[2][i][j];
				if (status[0][i][j] != -1) {
					status[1][i][j] = 0;
					status[2][i][j] = 0;
				}
			}
		//print_vec(status[0]);
		//cout << '\n';
		for (int i = 1; i < R+1; ++i)
			for (int j = 1; j < C+1; ++j) {
				if (status[0][i][j] < 1) continue;
				int diffusion_count = 0;
				int diffusion_amount = status[0][i][j] / 5;
				if (i > 1 && status[0][i-1][j] != -1) {
					++diffusion_count;
					status[1][i-1][j] += diffusion_amount;
				}
				if (i < R && status[0][i+1][j] != -1) {
					++diffusion_count;
					status[1][i+1][j] += diffusion_amount;
				}
				if (j > 1 && status[0][i][j-1] != -1) {
					++diffusion_count;
					status[1][i][j-1] += diffusion_amount;
				}
				if (j < C && status[0][i][j+1] != -1) {
					++diffusion_count;
					status[1][i][j+1] += diffusion_amount;
				}
				status[1][i][j] += status[0][i][j] - diffusion_count * diffusion_amount;
			}
		//print_vec(status[1]);
		//cout << '\n';
		for (int i = 1; i < R+1; ++i) {
			for (int j = 1; j < C+1; ++j) { // position[wind_direction]
				if (j == 1 && i < purifier_row_up) { // left[down]
					if (i+1 != purifier_row_up)
						status[2][i+1][j] = status[1][i][j];
				}
				else if (j == 1 && i > purifier_row_down) { // left[up]
					if (i-1 != purifier_row_down)
						status[2][i-1][j] = status[1][i][j];
				}
				else if (j == C && 1 < i && i <= purifier_row_up) { // right[up]
					status[2][i-1][j] = status[1][i][j];
				}
				else if (j == C && purifier_row_down <= i && i < R) { // right[down]
					status[2][i+1][j] = status[1][i][j];
				}
				else if (i == 1 && 1 < j && j <= C)  { // top[left]
					status[2][i][j-1] = status[1][i][j];
				}
				else if (i == R && 1 < j && j <= C) { // bottom[left]
					status[2][i][j-1] = status[1][i][j];
				}
				else if (i == purifier_row_up && 1 < j && j < C) { // upper_mid[right]
					status[2][i][j+1] = status[1][i][j];
				}
				else if (i == purifier_row_down && 1 < j && j < C) { // lower_mid[right]
					status[2][i][j+1] = status[1][i][j];
				}
				else {
					status[2][i][j] = status[1][i][j];
				}
			}
		}
		//print_vec(status[2]);
		//cout << "\n\n";
	}

	int dust_count = 2;
	for (int i = 1; i < R+1; ++i)
		for (int j = 1; j < C+1; ++j)
			dust_count += status[2][i][j];

	cout << dust_count;

	return 0;
}