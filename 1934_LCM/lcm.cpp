// HELLO WORLD!
#include <iostream>
using namespace std;

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
    int a, b, order_count;
    cin >> order_count;
    while(order_count--) {
        cin >> a >> b;
        cout << get_LCM(a, b, get_GCD(a, b)) << '\n';
    }
    return 0;
}
