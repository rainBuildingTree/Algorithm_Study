#include <iostream>
#include <stack>
using namespace std;

/*
MAIN:
    GET N
    CREATE an array[N]
    WHILE: repeat for N times
        GET integer
        PUSH integer into main_stack
        INCREASE array[integer-1] by 1
    
    WHILE: repeat for N times
        POP a number from main_stack
        WHILE: repeat until find a proper value
        IF compare_stack is empty
            result array -1
        IF number's frequency is bigger than compare_stack's pop
            continue
        IF number's frequency is smaller than compare_stack's pop
            PUSH number into main_stack
            result array the number
    
    PRINT result array.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    const int series_size = N;

    int* frequency_array = new int[1000000];
    int result_array[series_size];
    stack<int> main_stack;
    stack<int> compare_stack;

    for (int i = 0; i < 1000000; ++i)
        frequency_array[i] = 0;

    while (N--) {
        int temp;
        cin >> temp;
        frequency_array[temp-1] = frequency_array[temp-1] + 1;
        main_stack.push(temp);
    }
    N = series_size;

    while (N--) {
        int main_top = main_stack.top();
        main_stack.pop();

        bool found_value = false;
        while (!found_value) {
            if (compare_stack.empty()) {
                result_array[N] = -1;
                compare_stack.push(main_top);
                break;
            }

            int compare_top = compare_stack.top();

            if (frequency_array[main_top-1] >= frequency_array[compare_top-1]) {
                compare_stack.pop();
            }
            else {
                compare_stack.push(main_top);
                result_array[N] = compare_top;
                found_value = true;
            }
        }
    }

    for (int i = 0; i < series_size; ++i) {
        cout << result_array[i];
        if (i != (series_size-1))
            cout << ' ';
            
    }
    
    delete [] frequency_array;
    return 0;
}