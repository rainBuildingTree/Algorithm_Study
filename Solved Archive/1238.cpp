#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, X;
	cin >> N >> M >> X;

	const int INF = 0x2fffffff;
	vector<vector<pair<int, int>>> distance(N+1);
	vector<vector<pair<int, int>>> reverse_distance(N+1);
	for (int i = 0; i < M; ++i) {
		int start, end, t;
		cin >> start >> end >> t;
		distance[start].push_back({end, t});
		reverse_distance[end].push_back({start, t});
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> visit_queue;
	visit_queue.push({0,X});

	vector<char> visited(N+1, 0);
	int num_visited = 0;

	vector<int> distance_from_X(N+1, INF);
	distance_from_X[X] = 0;
	
	while (!visit_queue.empty()) {
		int current_distance = visit_queue.top().first;
		int current_vertex = visit_queue.top().second;
		visit_queue.pop();

		if (visited[current_vertex]) continue;

		visited[current_vertex] = 1;
		++num_visited;
		if (num_visited >= N) break;

		for (const auto& distance_info : distance[current_vertex]) {
			int calculated_distance = current_distance + distance_info.second;
			if (calculated_distance < distance_from_X[distance_info.first]) {
				distance_from_X[distance_info.first] = calculated_distance;
				visit_queue.push({calculated_distance, distance_info.first});
			}
		}
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> r_visit_queue;
	r_visit_queue.push({0,X});
	
	vector<char> r_visited(N+1, 0);
	num_visited = 0;

	vector<int> r_distance_from_X(N+1, INF);
	r_distance_from_X[X] = 0;

	while (!r_visit_queue.empty()) {
		int current_distance = r_visit_queue.top().first;
		int current_vertex = r_visit_queue.top().second;
		r_visit_queue.pop();

		if (r_visited[current_vertex]) continue;

		r_visited[current_vertex] = 1;
		++num_visited;
		if (num_visited >= N) break;

		for (const auto& distance_info : reverse_distance[current_vertex]) {
			int calculated_distance = current_distance + distance_info.second;
			if (calculated_distance < r_distance_from_X[distance_info.first]) {
				r_distance_from_X[distance_info.first] = calculated_distance;
				r_visit_queue.push({calculated_distance, distance_info.first});
			}
		}
	}

	int max_distance = 0;
	for (int i = 1; i < N+1; ++i)
		max_distance = max(max_distance, distance_from_X[i] + r_distance_from_X[i]);

	cout << max_distance;

	return 0;
}