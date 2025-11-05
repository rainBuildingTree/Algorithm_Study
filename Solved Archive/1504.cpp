#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <cmath>
using namespace std;

const int INF = 0x3fffffff;

int shortest_path(const vector<vector<pair<int,int>>>& edges,
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>& p_queue,
vector<int>& visited, vector<int>& distances, const int start, const int end
) {
	while (!p_queue.empty()) p_queue.pop();
	for (int i = 0; i < (int)visited.size(); ++i) {
		visited[i] = 0;
		distances[i] = INF;
	}

	p_queue.push({0, start});
	distances[start] = 0;
	while (!p_queue.empty()) {
		int current_node = p_queue.top().second;
		p_queue.pop();

		if (visited[current_node]) continue;
		visited[current_node] = 1;

		for (const pair<int,int>& edge : edges[current_node]) {
			int next_node = edge.second;
			int distance = edge.first;
			if (distances[next_node] > distances[current_node] + distance) {
				distances[next_node] = distances[current_node] + distance;
				p_queue.push({distances[next_node], next_node});
			}
		}
	}

	return distances[end];
}

int main() {
	int N, E;
	cin >> N >> E;

	vector<vector<pair<int,int>>> edges(N+1);
	for (int i = 0; i < E; ++i) {
		int start, end, distance;
		cin >> start >> end >> distance;
		edges[start].push_back({distance, end});
		edges[end].push_back({distance, start});
	}

	int start_node = 1;
	int end_node = N;
	int mid_node_a, mid_node_b;
	cin >> mid_node_a >> mid_node_b;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> empty_p_queue;
	vector<int> visited(N+1, 0);
	vector<int> distances(N+1, 0);

	int mid_mid = shortest_path(edges, empty_p_queue, visited, distances, 
								mid_node_a, mid_node_b);
	if (mid_mid >= INF) {
		cout << -1;
		return 0;
	}

	int start_mid_a = shortest_path(edges, empty_p_queue, visited, distances, 
									start_node, mid_node_a);
	int start_mid_b = shortest_path(edges, empty_p_queue, visited, distances, 
									start_node, mid_node_b);
	int mid_a_end = shortest_path(edges, empty_p_queue, visited, distances, 
								  mid_node_a, end_node);
	int mid_b_end = shortest_path(edges, empty_p_queue, visited, distances, 
								  mid_node_b, end_node);
	
	if (start_mid_a >= INF || mid_b_end >= INF) {
		if (start_mid_b >= INF || mid_a_end >= INF) {
			cout << -1;
			return 0;
		}
		cout << start_mid_b + mid_mid + mid_a_end;
		return 0;
	}
	if (start_mid_b >= INF || mid_a_end >= INF) {
		cout << start_mid_a + mid_mid + mid_b_end;
		return 0;
	}

	int path_a = start_mid_a + mid_mid + mid_b_end;
	int path_b = start_mid_b + mid_mid + mid_a_end;
	cout << min(path_a, path_b);


	return 0;
}