#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> edges(n+1);
	for (int i = 0; i < m; ++i) {
		int s, e, t;
		cin >> s >> e >> t;
		edges[s].push_back({ e, t });
	}

	int start, end;
	cin >> start >> end;

	const int INF = 0x3fffffff;
	vector<int> distance(n + 1, INF);
	distance[start] = 0;

	vector<int> before(n + 1, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_queue;
	p_queue.push({ 0, start });

	while (!p_queue.empty()) {
		int current_distance = p_queue.top().first;
		int current_vertex = p_queue.top().second;
		p_queue.pop();

		if (current_distance > distance[current_vertex]) continue;

		for (auto& edge : edges[current_vertex]) {
			int next = edge.first;
			int dist = edge.second;
			int new_dist = current_distance + dist;
			if (new_dist < distance[next]) {
				distance[next] = new_dist;
				before[next] = current_vertex;
				p_queue.push({ new_dist, next });
			}
		}
	}

	cout << distance[end] << '\n';

	stack<int> backtrack_stack;
	int path_len = 0;
	int target_vertex = end;
	while (target_vertex != start && before[target_vertex] != -1) {
		backtrack_stack.push(target_vertex);
		++path_len;
		target_vertex = before[target_vertex];
	}
	++path_len;
	backtrack_stack.push(start);

	cout << path_len << '\n';

	cout << backtrack_stack.top();
	backtrack_stack.pop();

	while (!backtrack_stack.empty()) {
		cout << ' ' << backtrack_stack.top();
		backtrack_stack.pop();
	}

	return 0;
}