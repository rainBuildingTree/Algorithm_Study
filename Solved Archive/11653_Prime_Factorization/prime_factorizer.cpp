// HELLO WORLD!
#include <iostream>

using namespace std;

/*
MAIN:
    0. GET input
    1. WHILE: input is not 1
        1.1. FOR: look for divider that divides input clearly.
            1.1.1. input becomes input / divider
            1.1.2. PRINT divider and newline
*/

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int input;
    cin >> input;
    int count = 10;

    while (true) {
        bool prime_factor_found = false;
        for (int i = 2; i*i <= input; ++i) {
            if ((input % i) == 0) {
                input /= i;
                cout << i << '\n';
                prime_factor_found = true;
                break;
            }
        }
        if (!prime_factor_found)
            break;
    }
    if (input != 1)
        cout << input;

    return 0;
}