#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
MAIN:
    GET input_count
    GET equation as string
    GET values for alphabet in double
    FOR: scan equation string
        IF alphabet
            PUSH proper values into calculator stack
        IF not alphabet
            POP top two members in caculator stack
            CALCULATE properly in double
            PUSH result into calculator stack
    
    PRINT top of the calculator stack
    
    RETURN 0;
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int input_count;
    string equation;
    cin >> input_count >> equation;

    double* values = new double[input_count];
    for (int i = 0; i < input_count; ++i)
        cin >> values[i];
    
    stack<double> calculator_stack;
    for (char ch : equation) {
        if ((ch >= 'A') && (ch <= 'Z'))
            calculator_stack.push(values[ch - 'A']);
        else {
            const double value_a = calculator_stack.top();
            calculator_stack.pop();
            double value_b = calculator_stack.top();
            calculator_stack.pop();
            switch (ch) {
                case '+':
                    value_b += value_a;
                    break;
                case '-':
                    value_b -= value_a;
                    break;
                case '*':
                    value_b *= value_a;
                    break;
                case '/':
                    value_b /= value_a;
                    break;
            }
            calculator_stack.push(value_b);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << calculator_stack.top();

    return 0;
}