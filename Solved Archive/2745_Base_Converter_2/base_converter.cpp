// HELLO WORLD!
#include <iostream>
#include <string>
using namespace std;

/*
MAIN:
    0. GET user inputs (string number and base)
    1. FOR: scan the input from back to front (use index)
        1.1. ADD the number recently scanned multiplied by base powered by index TO output
    2. PRINT output.
*/
int pow(int base, int exponent) {
    if (exponent == 0)
        return 1;
    int result = 1;
    while (exponent--)
        result *= base;
    return result;
}

int main() {
    string input_number;
    int base;
    cin >> input_number >> base;
    const int length = input_number.length();

    int output = 0;
    for (int i = length - 1; i >= 0; --i) {
        int number;
        if (('0' <= input_number[i]) && (input_number[i] <= '9'))
            number = input_number[i] - '0';
        else
            number = input_number[i] - 'A' + 10;
        output += number * pow(base, length - i - 1);
    }
    cout << output;
    return 0;
}