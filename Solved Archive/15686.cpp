#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int calculate_min(const vector<int>& houses,
	const vector<int>& chickens,
	vector<int>& chosen, int idx, const int N, const int M) {
	const int INF = 0x3fffffff;

	if ((int)chosen.size() == M) {
		int min_city_chicken_distance = 0;
		for (const int& house : houses) {
			int row = house / N;
			int col = house % N;
			int min_chicken_distance = INF;
			for (const int& item : chosen) {
				int chick_row = item / N;
				int chick_col = item % N;
				int chicken_distance = abs(row - chick_row) + abs(col - chick_col);
				min_chicken_distance = min(min_chicken_distance, chicken_distance);
			}
			min_city_chicken_distance += min_chicken_distance;
		}
		return min_city_chicken_distance;
	}
	if (idx >= (int)chickens.size())
		return INF;

	int min_city_chicken_distance = INF;
	for (int i = idx+1; i < (int)chickens.size(); ++i) {
		chosen.push_back(chickens[i]);
		min_city_chicken_distance = min(min_city_chicken_distance, calculate_min(
			houses, chickens, chosen, i, N, M
		));
		chosen.pop_back();
	}
	return min_city_chicken_distance;
}

int main() {
	int N, M;
	cin >> N >> M;

	const int INF = 0x3fffffff;

	vector<int> houses;
	vector<int> chickens;
	vector<vector<int>> citymap(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> citymap[i][j];
			int current_idx = i * N + j;
			if (citymap[i][j] == 1)
				houses.emplace_back(current_idx);
			if (citymap[i][j] == 2)
				chickens.emplace_back(current_idx);
		}
	
	vector<int> empty_list;
	cout << calculate_min(houses, chickens, empty_list, -1, N, M);
	return 0;
}