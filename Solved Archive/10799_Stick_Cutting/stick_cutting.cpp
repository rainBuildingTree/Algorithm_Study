#include <iostream>
using namespace std;

/*
MAIN:
    VARIABLES: sticks on cut, sticks done cut, input
    GET input
    FOR scan input as a character
        IF current is '('
            ++sticks on cut
        IF current is ')'
            --sticks on cut
            IF is laser
                sticks done cut += sticks on cut
            IF NOT
                sticks done cut++
    
    PRINT sticks done cut;
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numb_on_cut = 0;
    int numb_done_cut = 0;
    string input;
    
    cin >> input;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(')
            ++numb_on_cut;
        else if (input[i] == ')') {
            --numb_on_cut;
            if (input[i-1] == '(')
                numb_done_cut += numb_on_cut;
            else
                ++numb_done_cut;
        }
    }
    cout << numb_done_cut << '\n';
    return 0;
}