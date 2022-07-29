#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase_count = 0;
    cin >> testcase_count;
    cin.ignore();

    while (testcase_count--) {
        string input;
        getline(cin, input);
        
        int temp = 0;
        bool result = true;

        for (char c : input) {
            if (c == '(') ++temp;
            else if (c == ')') --temp;
            if (temp < 0) result = false;
        }

        if (temp != 0) result = false;

        cout << ((result == true) ? "YES" : "NO") << '\n';
    }
    return 0;
}