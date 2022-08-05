#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase_count;
    cin >> testcase_count;
    cin.ignore();

    while (testcase_count--) {
        
        string input;
        getline(cin, input);
        input += '\n';

        stack<char> st;

        for (char ch : input) {
            if (ch == ' ' || ch == '\n') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ch;
            }
            else
                st.push(ch);
        }
    }
    
    return 0;
}