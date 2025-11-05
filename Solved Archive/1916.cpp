#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int,int>>> adjacency_list(N+1);
	for (int i = 0; i < M; ++i) {
		int start, end, distance;
		cin >> start >> end >> distance;
		adjacency_list[start].push_back({distance, end});
	}
	int start_vertex, destination_vertex;
	cin >> start_vertex >> destination_vertex;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> p_queue;
	p_queue.push({0, start_vertex});

	const int INF = 0x3fffffff;
	vector<char> visited(N+1, 0);
	vector<int> distances(N+1, INF);
	distances[start_vertex] = 0;

	while (!p_queue.empty()) {
		int current_distance = p_queue.top().first;
		int current_vertex = p_queue.top().second;
		p_queue.pop();

		if (visited[current_vertex]) continue;
		distances[current_vertex] = current_distance;
		visited[current_vertex] = 1;

		for (const auto& adjacent_info : adjacency_list[current_vertex]) {
			if (distances[adjacent_info.second] > current_distance + adjacent_info.first) {
				distances[adjacent_info.second] = current_distance + adjacent_info.first;
				p_queue.push({distances[adjacent_info.second], adjacent_info.second});
			}
		}
	}
	
	cout << distances[destination_vertex];

	return 0;
}