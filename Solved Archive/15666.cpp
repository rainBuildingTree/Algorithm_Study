#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(const vector<int>& numbers, vector<int>& series, int idx, int length, int length_limit) {
	if (length == length_limit) {
		for (int i = 0; i < length_limit; ++i) {
			if (i) cout << ' ';
			cout << series[i];
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < (int)numbers.size(); ++i) {
		series[length] = numbers[i];
		dfs(numbers, series, i, length+1, length_limit);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> numbers;
	numbers.reserve(N);
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		numbers.emplace_back(input);
	}

	sort(numbers.begin(), numbers.end());
	auto new_end = unique(numbers.begin(), numbers.end());
	numbers.erase(new_end, numbers.end());

	vector<int> series(M, -1);
	dfs(numbers, series, 0, 0, M);

	return 0;
}