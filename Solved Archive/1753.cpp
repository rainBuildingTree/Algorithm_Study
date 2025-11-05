#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

// TODO: Priority Queue를 사용해서 다익스트라 시간 복잡도를 줄이기.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, E;
	cin >> V >> E;
	
	int root;
	cin >> root;

	vector<vector<pair<int, int>>> neighbors(V+1);
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		neighbors[u].push_back({v, w});
	}

	const int INF = 0x7fffffff;
	vector<int> distance(V+1, INF);
	vector<char> visited(V+1, 0);
	int num_visited = 1;

	distance[root] = 0;

	while (num_visited < V) {
		int closest_distance = INF;
		int current_vertex = -1;

		for (int i = 1; i < V+1; ++i) {
			if (visited[i] || distance[i] >= closest_distance) continue;
			closest_distance = distance[i];
			current_vertex = i;
		}

		if (current_vertex < 0) break;

		visited[current_vertex] = 1;
		++num_visited;

		for (const auto& neighbor : neighbors[current_vertex]) {
			int distance_from_current_vertex = distance[current_vertex] + neighbor.second;
			distance[neighbor.first] = min(distance[neighbor.first], distance_from_current_vertex);
		}
	}

	for (int i = 1; i < V+1; ++i)
		if (distance[i] < INF) cout << distance[i] << '\n';
		else cout << "INF\n";

	return 0;
}