#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int length;
    cin >> input;
    for (char ch : input)
        ++length;
    cout << length;

    return 0;
}