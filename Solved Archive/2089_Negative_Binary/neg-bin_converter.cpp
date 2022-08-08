#include <iostream>
#include <queue>
using namespace std;

/*
1. Find a number of (-2)^exp, which has a larger magnitude, same sign, and closest to N.
2. Scan for (-2)^exp numbers, which has a smaller magnitude to the number above.
    2-1. If adding the recently scanned number to approximation results in approch to the N, add it to approximation.
        2-1-1. push 1 to queue
    2-2. If not, push 0 to queue.
3. print the queue.
2나누기 도전해보기 (나중에)
*/
int magnitude(int input) {
    if (input < 0)
        return 0-input;
    return input;
}
int sign(int input) {
    if (input < 0)
        return -1;
    else
        return 1;
}
int pow(int base, int exponent) {
    int result = 1;
    if (exponent == 0)
        return result;

    while (exponent--)
        result *= base;
    return result;
}
int main() {
    int input;
    cin >> input;

    if (input == 0) {
        cout << 0;
        return 0;
    }

    //1
    int exponent = 0;
    for (;!((magnitude(pow(-2, exponent)) >= magnitude(input)) && (((exponent % 2) ? -1 : 1) == sign(input))); ++exponent);
    
    queue<int> output;
    int approximation;
    bool value_found = false;
    int begin_exp = exponent;
    bool lower_checked = false;
    bool upper_checked = false;
    bool try_once = false;

    while (!value_found) {
        approximation = pow(-2, exponent--);
        output.push(1);
        cout << approximation << '\t' << exponent+1 << '\t' << pow(-2, exponent+1) << endl;
        while ((exponent--)+1) {
            if (magnitude(input - (approximation + pow(-2, exponent+1))) <= magnitude(input - approximation)) {
                approximation = approximation + pow(-2, exponent+1);
                output.push(1);
            }
            else {
                if ((approximation > input) && ((exponent+1)%2 == sign(input))) {
                    if (!try_once) {
                        approximation = approximation + pow(-2, exponent+1);
                        output.push(1);
                    }
                    else
                        output.push(0);
                }
                else
                    output.push(0);
            }
            cout << approximation << '\t' << exponent+1 << '\t' << pow(-2, exponent+1) << endl;
        }

        if (approximation == input)
            value_found = true;
        else {
            while (!output.empty())
                output.pop();

            if (!try_once) {
                exponent = begin_exp;
                try_once = true;
                continue;
            }
            if (lower_checked) {
                exponent = begin_exp + 2;
                upper_checked = true;
                if (!try_once) {
                    try_once = true;
                    continue;
                }
            }
            else {
                try_once = false;
                exponent = begin_exp - 2;
                lower_checked = true;
                begin_exp += 2;
            }
            if (lower_checked && upper_checked) {
                value_found = true;
            }
        }
    }
    while (!output.empty()) {
        cout << output.front();
        output.pop();
    } 
}