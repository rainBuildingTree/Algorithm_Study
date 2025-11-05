#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A, B;
	cin >> A >> B;

	unordered_map<long long, long long> distance;
	queue<long long> bfs_queue;
	bfs_queue.push(A);
	distance[A] = 1;

	while (!bfs_queue.empty()) {
		long long popped = bfs_queue.front();
		bfs_queue.pop();

		long long twice = popped << 1;
		if (twice <= B && distance.find(twice) == distance.end()) {
			bfs_queue.push(twice);
			distance[twice] = distance[popped]+1;
		}
		
		long long add_one = popped * 10 + 1;
		if (add_one <= B && distance.find(add_one) == distance.end()) {
			bfs_queue.push(add_one);
			distance[add_one] = distance[popped]+1;
		}	
	}

	if (distance.find(B) == distance.end())
		cout << -1;
	else
		cout << distance[B];

	return 0;
}