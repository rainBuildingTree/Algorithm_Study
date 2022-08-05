#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
MAIN:
    GET string of equation

    CREATE a result queue;
    CREATE a operators stack;
    CREATE a char variable "keeped" = '\0';

    FOR: scan for equation string.
        IF current is alphabet
            PUSH it into result queue
        ELSE
            IF * or /
                IF something keeped in advance
                    PUSH keeped into result
                SAVE recently scanned character into keeped.
            ELIF + or -
                IF something keeped in advance
                    PUSH keeped into result
                    SET result as '\0';
                IF operators.top is '-' or '+'
                    POP from operators and PUSH it into result.
                PUSH current into operators
            ELIF (
                IF keeped is not '\0'
                    PUSH keeped into operators
                    keeped = '\0'
                PUSH current into operators
            ELIF )
                IF keeped is not '\0'
                    PUSH keeped into result
                    keeped = '\0'
                WHILE: until popped thing is not '('
                    POP from operators and PUSH it into result.
                IF opeartors' top is * or /
                    SET keeped back to pop of operators
    
    IF keeped is not '\0'
        PUSH keeped into result
    IF operators is not empty
        POP from opeartors and PUSH it into result
    
    PRINT result queue by POP.
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string equation;
    cin >> equation;

    queue<char> result;
    stack<char> operators;
    char keeped = '\0';

    for (char ch : equation) {
        if ((ch >= 'A') && (ch <= 'Z'))
            result.push(ch);
        else if ((ch == '*') || (ch == '/')) {
            if (keeped != '\0')
                result.push(keeped);
            keeped = ch;
        }
        else if ((ch == '+') || (ch == '-')) {
            if (keeped != '\0') {
                result.push(keeped);
                keeped = '\0';
            }
            if (!operators.empty()) {
                char op_top = operators.top();
                if ((op_top == '+') || (op_top == '-')) {
                    operators.pop();
                    result.push(op_top);
                }
            }
            operators.push(ch);
        }
        else if (ch == '(') {
            if (keeped != '\0') {
                operators.push(keeped);
                keeped = '\0';
            }
            operators.push(ch);
        }
        else if (ch == ')') {
            if (keeped != '\0') {
                result.push(keeped);
                keeped = '\0';
            }
            char popped = operators.top();
            operators.pop();
            while (popped != '(') {
                result.push(popped);
                popped = operators.top();
                operators.pop();
            }
            if (!operators.empty()) {
                char op_top = operators.top();
                if ((op_top == '*') || (op_top == '/')) {
                    operators.pop();
                    keeped = op_top;
                }
            }
        }
    }
    if (keeped != '\0')
        result.push(keeped);
    
    if (!operators.empty()) {
        result.push(operators.top());
        operators.pop();
    }

    while (!result.empty()) {
        cout << result.front();
        result.pop();
    }

    return 0;
}