#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> queue_main;
    queue<int> queue_print;

    for (int i = 1; i <= N; ++i) // O(N)
        queue_main.push(i);

    while (!queue_main.empty()) {
        for (int i = 1; i < K; ++i) {
            queue_main.push(queue_main.front());
            queue_main.pop();
        }
        queue_print.push(queue_main.front());
        queue_main.pop();
    }

    cout << '<';
    while (!queue_print.empty()) {
        cout << queue_print.front();
        queue_print.pop();
        if (!queue_print.empty())
            cout << ", ";
    }
    cout << '>';
    return 0;
}