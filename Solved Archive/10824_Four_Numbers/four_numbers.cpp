#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, C, D;
    cin >> A >> B >> C >> D;
    string AB_str = A+B;
    string CD_str = C+D;
    unsigned long long AB_int = stoll(AB_str);
    unsigned long long CD_int = stoll(CD_str);
    cout << AB_int + CD_int;
    return 0;   
}