#include <iostream>
#include <stack>
using namespace std;

/*
#INCLUDE iostream, stack

DECLARE a stack<int>
DECLARE a stack<char>
DECLARE a input stack<int>
DECLARE a series stack<int>
DECLARE a boolean variable "possible" with true

GET the length of the series

FOR: repeat for 'length' times
    PUSH the input into input stack

WHILE: input stack is not empty
    PUSH the top of input stack into series stack
    POP from the input stack

WHILE length is bigger than 0
    PUSH the length value into stack_input
    SET length to be (length - 1)

WHILE: series stack is not empty
    IF series stack's top equals to the top of the stack<int>
        POP from stack<int>
        PUSH '-' to stack<char>
    ELIF series stack's top is bigger than the top of the stack
        PUSH input stack's top into stack<int> and pop input stack's top until stack's top equals to current series member
        PUSH '+' to stack<char>
        POP from stack
        PUSH '-' to stack<char>
    ELSE series stack's top is smaller than the top of the stack
        SET possible to be false
        BREAK
    POP from series stack

IF possible is false
    PRINT "NO"
ELSE
    WHILE: stack<char> is not empty
        PRINT stack<char>'s top
        PRINT newline character
        POP stack<char>
        


*/

int main() {
    stack<int> stack_int;
    stack<char> stack_char;
    stack<int> stack_input;
    stack<int> stack_series;
    bool possible = true;

    int series_length;
    cin >> series_length;
    
    for (int i = 0; i < series_length; ++i) {
        int temp_input;
        cin >> temp_input;
        stack_input.push(temp_input);
    }

    while (!stack_input.empty()) {
        stack_series.push(stack_input.top());
        stack_input.pop();
    }

    while (series_length > 0)
        stack_input.push(series_length--);

    stack_int.push(0);
    while (!stack_series.empty()) {

        if (stack_series.top() == stack_int.top()) {
            stack_int.pop();
            stack_char.push('-');
        }
        else if (stack_series.top() > stack_int.top()) {
            while (stack_series.top() > stack_int.top()) {
                stack_int.push(stack_input.top());
                stack_input.pop();
                stack_char.push('+');
            }
            stack_int.pop();
            stack_char.push('-');
        }
        else {
            possible = false;
            break;
        }
        stack_series.pop();
    }
    if (!possible)
        cout << "NO\n";
    else {
        stack<char> stack_temp;
        while (!stack_char.empty()) {
            stack_temp.push(stack_char.top());
            stack_char.pop();
        }
        while (!stack_temp.empty()) {
            cout << stack_temp.top() << '\n';
            stack_temp.pop();
        }
    }

    return 0;
}