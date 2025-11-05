#include <iostream>
#include <vector>
using namespace std;

long long power(long long b, long long p, long long X) {
    b %= X;
    if (p == 0) return 1;
    long long half = power(b, p/2, X);
    long long res = (half * half) % X;
    if (p & 1) res = (res * b) % X;
    return res;
}

int main() {
	int M;
	cin >> M;

	const long long large_prime = 1000000007LL;

	vector<long long> values(M);
	for (int i = 0; i < M; ++i) {
		long long a, b;
		cin >> a >> b;
		values[i] = (b * power(a, large_prime-2, large_prime)) % large_prime;
	}

	long long sum = 0;
	for (const long long value : values) {
		sum = (sum + value) % large_prime;
	}

	cout << sum;

	return 0;
}