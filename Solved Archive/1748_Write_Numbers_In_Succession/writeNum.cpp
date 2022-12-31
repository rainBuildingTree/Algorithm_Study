#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1 <= N <= 100,000,000 = 10^8
    int N;
    cin >> N;

    int size = 1;
    for (; size < 100000001; size = size * 10)
        if ((N / size) < 10)
            break;

    int index = 0;
    int cp_size = size;
    while (cp_size > 9) {
        index++;
        cp_size /= 10;
    }

    //cout << "[DEBUG] size = " << size << "\t index = " << index << '\n';    

    int result = (index + 1) * (N - size + 1);
    while (index > 0) {
        result += index * (size / 10 * 9);
        size /= 10;
        index--;
    }

    cout << result << '\n';

    return 0;
}