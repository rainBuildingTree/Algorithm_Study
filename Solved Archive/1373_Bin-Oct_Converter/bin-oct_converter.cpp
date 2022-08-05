// HELLO WORLD!
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int pow(int base, int exponent) {
    int result = 1;
    if (exponent == 0)
        return result;

    while (exponent--)
        result *= base;
    
    return result;
}

int main() {
    while (true) {
        cout << "@@@ IF YOU WANT TO QUIT ENTER 'Q'@@@\n";
        cout << "Please put binary number to convert:   ";
        string input;
        cin >> input;

        if ((input == "Q") || (input == "q"))
            break;

        stack<int> output;
        int current = 0;
        int multiplier = 0;
        for (int i = input.length() - 1; i >= 0; --i) {
            current += (input[i] - '0') * pow(2, multiplier++);
            if ((multiplier == 3) || (i == 0)) {
                output.push(current);
                multiplier = 0;
                current = 0;
            }
        }

        cout << "The converted octal number is:   ";
        while (!output.empty()) {
            cout << output.top();
            output.pop();
        }
        cout << "\n\n\n";
    }
    return 0;
}