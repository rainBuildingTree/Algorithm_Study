// HELLO WORLD!
#include <iostream>
using namespace std;

int factorial(int input) {
    int result = 1;
    if (input == 0)
        return result;
    for (int i = 2; i <= input; ++i)
        result *= i;
    return result;
}

int main() {
    int input;
    cin >> input;
    cout << factorial(input);
    return 0;
}