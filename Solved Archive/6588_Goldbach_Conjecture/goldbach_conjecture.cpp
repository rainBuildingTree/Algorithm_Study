#include <iostream>
using namespace std;

/*
MAIN:
    1. Make a prime number database [0, 1000000]
    2. WHILE: repeat until the input is 0
        2-1. Get user input; if input is 0 then break
        2-2. Find closest and smaller prime number from input number from database
        2-3. If found, check for (input - found prime number) is a prime nubmer and odd.
            2-3-1. IF yes, keep two values.
            2-3-2. IF no, find next closest and smaller prime number from database.
                2-3-2-1. IF cannot find proper number in the range of [input/2, input], then goldbach is wrong.
        2-4. CHECK if goldbach is correct
            2-4-1. IF yes, PRINT the keeped prime numbers in the proper format
            2-4-2. IF no, PRINT "Goldbach's conjecture is wrong"
*/

int main() {

    const int lower_limit = 0;
    const int upper_limit = 1000000;
    bool* prime_database = new bool[upper_limit + 1];
    
    prime_database[0] = false;
    prime_database[1] = false;
    for (int i = 2; i <= upper_limit; ++i)
        prime_database[i] = true;
    
    for (int i = 2; i <= upper_limit; ++i) {
        if (prime_database[i] == true) {
            bool there_is_something_to_delete = (i*2 <= upper_limit);
            bool something_deleted = false;
            if (there_is_something_to_delete)
                for (int j = 2; j*i <= upper_limit; ++j)
                    if (prime_database[j*i] == true) {
                        something_deleted = true;
                        prime_database[j*i] = false;
                    }
            if (!something_deleted)
                break; 
        }
    }

    int TESTCASE_COUNT = 100000;
    while (TESTCASE_COUNT--) {
        int input, adder_a, adder_b;
        bool check_goldbach_right = false;
        cin >> input;

        if (input == 0)
            break;

        for (int i = input - 1; i >= input/2-1; --i) {
            if ((i%2 == 1) && (prime_database[i]))
                if (prime_database[input-i]) {
                    adder_a = i;
                    adder_b = input - i;
                    check_goldbach_right = true;
                    break;
                }
        }

        if (check_goldbach_right)
            cout << input << " = " << adder_b << " + " << adder_a << '\n';
        else
            cout << "Goldbach's conjecture is wrong!\n";
    }

    return 0;
}