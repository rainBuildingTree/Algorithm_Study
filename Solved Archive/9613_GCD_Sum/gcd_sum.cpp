#include <iostream>
using namespace std;

/*
GET_GCD(A, B):
    1. IF B is 0 then return B.
    2. IF not return GET_GCD(B, A%B)

GET_MAX(A, B):
    RETURN (A >= B) ? A : B;

GET_MIN(A, B):
    RETURN (A <= B) ? A : B

MAIN_FUNC(int*):
    MAKE result var
    DOUBLE FOR: search all combination of array
        add GCD of each combinations into result
    RETURN result.

MAIN:
    0. GET order count
    1. WHILE: repeat for order count
        GET input count
        MAKE array for input
        GET input into array
        PRINT "MAIN_FUNC(array)"
        DELETE array
*/
int get_gcd(int a, int b) {
    if (b == 0)
        return a;
    return get_gcd(b, a%b);
}

int get_max(int a, int b) {
    return ((a >= b) ? a : b);
}
int get_min(int a, int b) {
    return ((a <= b) ? a : b);
}

long long main_func(int* array, int length) {
    long long result = 0;
    for (int i = 0; i < (length - 1); ++i)
        for (int j = i+1; j < length; ++j) {
            int larger = get_max(array[i], array[j]);
            int smaller = get_min(array[i], array[j]);
            result += get_gcd(larger, smaller);
        }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int order_count;
    cin >> order_count;

    while (order_count--) {
        int input_count;
        cin >> input_count;

        int array_length = input_count;
        int* array = new int[array_length];

        for (int i = 0; i < array_length; ++i)
            cin >> array[i];

        cout << main_func(array, array_length) << '\n';
        
        delete [] array;
    }
    return 0;
}