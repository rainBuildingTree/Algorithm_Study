#include <iostream>
#include <vector>
#include <array>
using namespace std;

bool is_negative_cycle_exist(const vector<array<int, 3>>& edges, const int N) {
	const long long INF = 1e18;

	vector<long long> distance(N+1, 0);

	for (int i = 0; i < N-1; ++i)
		for (const auto& edge : edges)
			if (distance[edge[0]] < INF && distance[edge[1]] > distance[edge[0]] + edge[2]) {
				distance[edge[1]] = distance[edge[0]] + edge[2];
			}
	
	for (const auto& edge : edges)
		if (distance[edge[0]] != INF && distance[edge[1]] > distance[edge[0]] + edge[2])
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;

	while (TC--) {
		int N, M, W;
		cin >> N >> M >> W;

		vector<array<int, 3>> edges;
		for (int i = 0; i < M; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			edges.push_back({{S, E, T}});
			edges.push_back({{E, S, T}});
		}
		for (int i = 0; i < W; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			edges.push_back({{S, E, -T}});
		}

		cout << (is_negative_cycle_exist(edges, N) ? "YES\n" : "NO\n");
	}

	return 0;
}