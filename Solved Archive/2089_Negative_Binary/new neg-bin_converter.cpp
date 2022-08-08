// HELLO WORLD!
#include <iostream>
#include <stack>
using namespace std;

/*
1. GET input
2. IF input is 0, print 0 and end.
3. WHILE: divide input by -2 until input become 1.
    3-1. input is quotient, and keep remainder into a stack.
    3-2. if remainder is -1, quotient++ and remainder = -1.
4. PUSH 1 into stack.
5. PRINT from stack.
*/

int main() {
    int input;
    cin >> input;

    if (!input) {
        cout << 0;
        return 0;
    }

    stack<int> result;
    while (input != 1) {
        int quotient = input / (-2);
        int remainder = input % (-2);

        if (remainder == -1) {
            ++quotient;
            remainder = 1;
        }

        input = quotient;
        result.push(remainder);
    }
    result.push(1);

    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }

    return 0;
}