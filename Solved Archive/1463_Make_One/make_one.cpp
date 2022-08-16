// HELLO WORLD!
#include <iostream>
#include <vector>
using namespace std;

/*
1. 3으로 나눌 수 있는 경우 -> 3으로 나눈다.
2. 3으론 못나누고 2로는 나눌 수 있는경우.
	2.1. 2로 나누고 2로 또 나눌 수 있는 경우 -> 2로 나눈다.
	2.2. 2로 한번만 나눌 수 있는 경우 -> -1을 해서 3으로 나눌 수 있으면 그렇게 가고, 아니면 2로 나눈다.
3. 1, 2에 포함되지 않는경우 -1을 한다.

vector<Pair> memo

int recur_fuc
    0. CHECK if input is 1, then return 1
    1. CHECK for memo whether the input's result exists
        1.1. IF yes, return count from memo
    2. CHECK for count of input / 3
    3. CHECK for count of input / 2, if count is smaller, replace the count
    4. CHECK for count of input - 1, if count is smaller, replace the count
    5. KEEP input and count into memo.
    6. RETURN count + 1
    

MAIN:
    0. GET input
    1. GET count from recursive func
    2. PRINT recursive func
*/
int memo[1000001]
;

int main_func(int input) {
    if (input == 1)
        return 0;

    int count = memo[input];
    if (count) {
        //cout << input << " : " << count << '\n';
        return count;
    }
    
    int adder = 1000000;
    if (!(input % 3))
        adder = main_func(input / 3);
    if (!(input % 2)) {
        int temp = main_func(input / 2);
        adder = ((temp < adder) ? temp : adder);
    }
    int temp = main_func(input - 1);
    adder = ((temp < adder) ? temp : adder);

    count = adder + 1;

    memo[input] = count;
    //cout << "memoed: memo[" << input << "] is: " << count << '\n';
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int input;
    cin >> input;
    int count = main_func(input);
    cout << count << '\n';

    //for (int i  = 0; i <= input; ++i)
        //cout << memo[i] << ' ';

    return 0;
}