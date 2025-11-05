#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct UnionFind {
	vector<int> parent, rank;

	UnionFind(const int n) : parent(n+1), rank(n+1, 1) {
		for (int i = 0; i < n+1; ++i)
			parent[i] = i;
	}

	int find(const int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(const int a, const int b) {
		int a_root = find(a);
		int b_root = find(b);
		if (a_root == b_root) return;
		if (rank[a_root] < rank[b_root]) swap(a_root, b_root);
		parent[b_root] = a_root;
		if (rank[a_root] == rank[b_root]) ++rank[a_root];
	}

	bool same(const int a, const int b) {
		return find(a) == find(b);
	}
};

int main() {
	int N, M;
	cin >> N >> M;

	int woke_count;
	cin >> woke_count;

	vector<int> wokes(woke_count);
	for (int i = 0; i < woke_count; ++i)
		cin >> wokes[i];

	UnionFind union_find(N);
	vector<vector<int>> parties(M);
	for (int i = 0; i < M; ++i) {
		int participant_count;
		cin >> participant_count;
		parties[i].resize(participant_count);

		for (int j = 0; j < participant_count; ++j)
			cin >> parties[i][j];

		for (int j = 1; j < participant_count; ++j)
			union_find.unite(parties[i][0], parties[i][j]);
	}

	set<int> woke_roots;
	for (const int woke : wokes)
		woke_roots.insert(union_find.find(woke));

	int can_lie_count = 0;
	for (const vector<int>& party : parties) {
		bool can_lie = true;
		for (const int participant : party)
			if (woke_roots.count(union_find.find(participant))) {
				can_lie = false;
				break;
			}
		if (can_lie) ++can_lie_count;
	}

	cout << can_lie_count;

	return 0;
}