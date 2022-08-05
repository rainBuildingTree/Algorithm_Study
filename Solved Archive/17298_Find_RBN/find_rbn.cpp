#include <iostream>
#include "RBT_Stack.h"
using namespace std;
/*
MAIN:
    GET the N
    GET input and save it on a main_stack
    PREPARE a compare_stack
    WHILE: repeat for N times
        POP from main_stack
        COMPARE with top of the compare_stack
        IF popped one is bigger
            POP from compare_stack until finding bigger one
        IF popped one is smaller
            TOP of the compare_stack is RBN(N-th)
        IF stack is empty
            LET RBN(N-th) of it is -1;
// PUT found RBN into an array[N]

    PRINT the array
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 1000000;
    //cin >> N;
    const int series_size = N;

    rbt_stack<int> main_stack;

    while (--N) {
        //int temp;
        //cin >> temp;
        main_stack.push(N);
        cout << N;
    }
    main_stack.push(100000001);
    cout << "input_completed!\n";
    rbt_stack<int> compare_stack;
    N = series_size;
    int result_array[series_size];

    while (N--) {
        int main_top = main_stack.top();
        main_stack.pop();

        bool value_found = false;
        while (!value_found) {

            if (compare_stack.empty()) {
                result_array[N] = -1;
                compare_stack.push(main_top);
                value_found = true;
                continue;
            }

            int compare_top = compare_stack.top();

            if (main_top >= compare_top) {
                compare_stack.pop();
                continue;
            }
            
            if (main_top < compare_top) {
                compare_stack.push(main_top);
                result_array[N] = compare_top;
                value_found = true;
            }
        }
    }

    for (int i = 0; i < series_size; ++i) {
        cout << result_array[i];
        if (i != (series_size - 1))
            cout << ' ';
    }
    
    return 0;
}