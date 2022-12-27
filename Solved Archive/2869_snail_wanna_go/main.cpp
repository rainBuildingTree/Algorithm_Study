#include <iostream>
using namespace std;

// input_data[0]: the distance a snail goes up in daytime.
// input_data[1]: the distance the snail slep down at night.
// input_data[2]: the distance the snail need to go up.

int* get_input() {
    int* data = new int[3];
    for (int i = 0; i < 3; ++i)
        cin >> data[i];
    return data;
}

int calculate_date(int* data) {
    int ans = (data[2] - data[0]) / (data[0] - data[1]) + (((data[2] - data[0]) % (data[0] - data[1]) == 0) ? 0 : 1) + 1;
    delete [] data;
    return ans;
}

void printInt(int message) {
    cout << message << '\n';
}

int main() {
    printInt(calculate_date(get_input()));
    return 0;
}