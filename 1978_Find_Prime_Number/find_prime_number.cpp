// HELLO WORLD!
#include <iostream>
using namespace std;

bool is_prime(int input) {
    if (input < 2)
        return false;
    else {
        for (int i = 2; i*i <= input; ++i)
            if ((input % i) == 0)
                return false;
    }
    return true;
}

int main() {
    int order_count;
    int prime_count = 0;
    cin >> order_count;

    int current;
    while (order_count--) {
        cin >> current;
        if (is_prime(current))
            ++prime_count;
    }
    cout << prime_count;
    return 0;
}