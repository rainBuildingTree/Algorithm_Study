#include <iostream>
using namespace std;

int main() {
    int a = 99999;
    a /= 10;
    a /= 10;
    a /= 10;
    a /= 10;
    cout << a << endl;
    return 0;
}