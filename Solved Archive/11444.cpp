#include <iostream>
#include <array>
using namespace std;

const long long MOD = 1000000007;

struct Matrix {
	array<array<long long, 2>, 2> matrix;
};

Matrix multiply(Matrix a, Matrix b) {
	Matrix c;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			c.matrix[i][j] = 0;
			c.matrix[i][j] += ((a.matrix[i][0] % MOD) * (b.matrix[0][j] % MOD)) % MOD;
			c.matrix[i][j] += ((a.matrix[i][1] % MOD) * (b.matrix[1][j] % MOD)) % MOD;
			c.matrix[i][j] %= MOD;
		}
	return c;
}

Matrix power(Matrix m, long long n) {
	if (n == 0)
		return { {{ {{1, 0}}, {{0, 1}} }} };
	if (n == 1)
		return m;
	if (n % 2 == 0) {
		Matrix half = power(m, n/2);
		return multiply(half, half);
	}
	if (n % 2 == 1) {
		Matrix half = power(m, (n-1)/2);
		return multiply(m, multiply(half, half));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	Matrix m = {
		{{ {{1, 1}}, {{1, 0}} }}
	};

	Matrix r = power(m, n-1);

	cout << r.matrix[0][0] % MOD;

	return 0;
}