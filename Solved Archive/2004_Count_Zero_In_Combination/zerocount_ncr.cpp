#include <iostream>
using namespace std;

int main() {
    int input_m, input_n, a = 0, b = 0, c = 0, aa = 0, ba = 0, ca = 0;
    cin >> input_n >> input_m;

    for (unsigned int i = 5; i <= input_n; i = i*5)
        a += input_n / i;
    for (unsigned int i = 2; i <= input_n; i = i*2)
        aa += input_n / i;

    for (unsigned int i = 5; i <= input_m; i = i*5)
        b += input_m / i;
    for (unsigned int i = 2; i <= input_m; i = i*2)
        ba += input_m / i;
    
    for (unsigned int i = 5; i <= input_n - input_m; i = i*5)
        c += (input_n-input_m) / i;
    for (unsigned int i = 2; i <= input_n - input_m; i = i*2)
        ca += (input_n-input_m) / i;
    
    cout << (((a-b-c) <= (aa - ba - ca)) ? (a-b-c) : (aa - ba - ca));
    return 0;
}