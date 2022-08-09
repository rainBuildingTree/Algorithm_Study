// HELLO WORLD!
#include <iostream>
#include <stack>
using namespace std;

/*
MAIN:
    1. GET input and base
    2. WHILE: repeat until input becomes 1
        2.1. DIV input by base
            2.1.1. quotient becomes input
            2.1.2. remainder goes to stack
    3. PUSH 1 into stack
    4. PRINT stack
*/
int main() {
    int input;
    int base;
    cin >> input >> base;

    stack<char> output;
    while (input >= base) {
        char remainder = input % base;
        if (remainder > 9)
            remainder = 'A' - 10 + remainder;
        else
            remainder = '0' + remainder;
        output.push(remainder);
        input = input / base;
    }
    if (input > 9)
        input = 'A' - 10 + input;
    else
        input = '0' + input;
    output.push(input);

    while (!output.empty()) {
        cout << output.top();
        output.pop();
    }

    return 0;
}