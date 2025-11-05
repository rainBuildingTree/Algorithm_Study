#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> neighbors(n+1);
	for (int i = 0; i < n-1; ++i) {
		int s, e, w;
		cin >> s >> e >> w;
		neighbors[s].push_back({e, w});
		neighbors[e].push_back({s, w});
	}

	stack<int> dfs_stack;
	dfs_stack.push(1);

	vector<int> distance(n+1, -1);
	distance[1] = 0;

	int farthest_distance = 0;
	int farthest_vertex = 1;
	while (!dfs_stack.empty()) {
		int current_vertex = dfs_stack.top();
		int current_distance = distance[current_vertex];
		if (current_distance > farthest_distance) {
			farthest_vertex = current_vertex;
			farthest_distance = current_distance;
		}
		dfs_stack.pop();

		for (const auto& neighbor : neighbors[current_vertex]) {
			if (distance[neighbor.first] > -1) continue;
			distance[neighbor.first] = current_distance + neighbor.second;
			dfs_stack.push(neighbor.first);
		}
	}
	stack<int> dfs_stack2;
	dfs_stack2.push(farthest_vertex);

	vector<int> distance2(n+1, -1);
	distance2[farthest_vertex] = 0;

	farthest_distance = 0;
	while (!dfs_stack2.empty()) {
		int current_vertex = dfs_stack2.top();
		int current_distance = distance2[current_vertex];
		if (current_distance > farthest_distance) {
			farthest_vertex = current_vertex;
			farthest_distance = current_distance;
		}
		dfs_stack2.pop();

		for (const auto& neighbor : neighbors[current_vertex]) {
			if (distance2[neighbor.first] > -1) continue;
			distance2[neighbor.first] = current_distance + neighbor.second;
			dfs_stack2.push(neighbor.first);
		}
	}
	cout << farthest_distance << '\n';

	return 0;
}