#include <iostream>
using namespace std;

int count;
void checkCount(int n, int sum) {
    if (sum == n) {
        count++;
        return;
    }
    if (sum > n)
        return;
    
    checkCount(n, sum+1);
    checkCount(n, sum+2);
    checkCount(n, sum+3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T;
    cin >> T;

    while (T--) {
        cin >> n;
        count = 0;
        checkCount(n, 0);
        cout << count << '\n';
    }

    return 0;
}