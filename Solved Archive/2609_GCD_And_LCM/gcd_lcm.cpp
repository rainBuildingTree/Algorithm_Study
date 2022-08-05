#include <iostream>
using namespace std;


/*
get_GCD(int A, int B) {
    if (B == 0)
        return A;
    else
        return get_GCD(B, A%B);
}

get_LCM(int A, int B, int GCD) {
    return (A/GCD) * (B/GCD);
}

MAIN:
    GET input
    cout << get_GCD(A, B) << '\n' << get_LCM(A, B, get_GCD(A, B));
*/

int get_GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return get_GCD(b, a%b);
}

int get_LCM(int a, int b, int gcd) {
    return (a/gcd)*(b/gcd)*gcd;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << get_GCD(a, b) << '\n' << get_LCM(a, b, get_GCD(a, b));
    return 0;
}