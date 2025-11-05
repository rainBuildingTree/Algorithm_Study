#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	const int INF = 0x3fffffff;
	vector<int> distances(100001, INF);
	vector<int> counts(100001, 0);

	queue<int> bfs_queue;
	bfs_queue.push(N);
	distances[N] = 0;
	counts[N] = 1;
	while (!bfs_queue.empty()) {
		int popped = bfs_queue.front();
		bfs_queue.pop();

		if (popped > 0) {
			if (distances[popped-1] == INF) {
				distances[popped-1] = distances[popped] + 1;
				counts[popped-1] = counts[popped];
				bfs_queue.push(popped-1);
			}
			else if (distances[popped-1] == distances[popped] + 1)
				counts[popped-1] += counts[popped];
		}
		if (popped < 100000) {
			if (distances[popped+1] == INF) {
				distances[popped+1] = distances[popped] + 1;
				counts[popped+1] = counts[popped];
				bfs_queue.push(popped+1);
			}
			else if (distances[popped+1] == distances[popped] + 1)
				counts[popped+1] += counts[popped];
		}
		if (popped < 50001) {
			if (distances[popped << 1] == INF) {
				distances[popped<<1] = distances[popped] + 1;
				counts[popped<<1] = counts[popped];
				bfs_queue.push(popped<<1);
			}
			else if (distances[popped<<1] == distances[popped] + 1)
				counts[popped<<1] += counts[popped];
		}
	}
	cout << distances[K] << '\n' << counts[K];

	return 0;
}