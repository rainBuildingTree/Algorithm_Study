#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	int N_a, N_b;
	cin >> N_a;
	vector<pair<int,int>> A(N_a);
	for (int i = 0; i < N_a; ++i) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end(), cmp);
	cin >> N_b;
	vector<pair<int,int>> B(N_b);
	for (int i = 0; i < N_b; ++i) {
		cin >> B[i].first;
		B[i].second = i;
	}
	sort(B.begin(), B.end(), cmp);

	vector<int> result;

	bool found_match = true;
	int a_idx_begin = 0;
	int b_idx_begin = 0;
	int a_last_idx = -1;
	int b_last_idx = -1;
	while (found_match) {
		found_match = false;
		int a_idx = a_idx_begin;
		int b_idx = b_idx_begin;
		while (a_idx < A.size() && b_idx < B.size()) {
			bool is_continue = false;
			if (A[a_idx].second < a_last_idx) {
				++a_idx;
				is_continue = true;
			}
			if (B[b_idx].second < b_last_idx) {
				++b_idx;
				is_continue = true;
			}
			if (is_continue)
				continue;

			if (A[a_idx].first == B[b_idx].first) {
				a_idx_begin = a_idx+1;
				b_idx_begin = b_idx+1;
				a_last_idx = A[a_idx].second;
				b_last_idx = B[b_idx].second;
				found_match = true;
				result.push_back(A[a_idx].first);
				break;
			}
			if (A[a_idx].first > B[b_idx].first)
				++a_idx;
			else
				++b_idx;
		}
	}

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); ++i) {
		if (i) cout << ' ';
		cout << result[i];
	}

	return 0;
}