#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> series(N);
	for (int i = 0; i < N; ++i)
		cin >> series[i];

	vector<int> i_memo(N, 1);
	for (int i = 0; i <	N; ++i) {
		for (int j = 0; j < i; ++j) {
			i_memo[i] = series[i] > series[j]
			? (i_memo[j]+1 > i_memo[i] ? i_memo[j]+1 : i_memo[i])
			: i_memo[i];
		}
	}
	vector<int> d_memo(N, 1);
	for (int i = N-1; i >= 0; --i) {
		for (int j = N-1; j > i; --j) {
			d_memo[i] = series[i] > series[j]
			? (d_memo[j]+1 > d_memo[i] ? d_memo[j]+1 : d_memo[i])
			: d_memo[i];
		}
	}

	int max_len = 1;
	for (int i = 0; i < N; ++i) {
		max_len = max(max_len, i_memo[i] + d_memo[i] - 1);
	}
	cout << max_len;

		
	return 0;
}