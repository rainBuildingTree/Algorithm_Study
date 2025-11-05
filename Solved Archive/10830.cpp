#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	const int size = (int)a.size();

	vector<vector<int>> result(size, vector<int>(size, 0));
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < size; ++k) {
				result[i][j] += (a[i][k] * b[k][j]) % 1000;
				result[i][j] %= 1000;
			} 
		}

	return result;
}

vector<vector<int>> power(vector<vector<int>>& base, const long long b) {
	const int size = (int)base.size();

	vector<vector<int>> result(size, vector<int>(size, 0));
	if (b == 0) {
		for (int i = 0; i < size; ++i)
			result[i][i] = 1;
		return result;
	}
	
	if (b == 1) {
		return base;
	}

	vector<vector<int>> half = power(base, b/2);
	if (b % 2 == 0) {
		return multiply(half, half) ;
	}
	else {
		return multiply(base, multiply(half, half));
	}

}

int main() {
	long long N, B;
	cin >> N >> B;

	vector<vector<int>> base(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> base[i][j];
			base[i][j] %= 1000;
		}

	vector<vector<int>> result = power(base, B);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j) cout << ' ';
			cout << result[i][j];
		}
		cout << '\n';
	}
	return 0;
}