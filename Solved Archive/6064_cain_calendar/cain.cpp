#include <iostream>
using namespace std;

/*
Get the number of data
Repeat for the number of data:
    Get the data
    Check the bigger one among x and y
    Put checked bigger one to 'bigger'
    Put checked smaller one to 'smaller'
    Check and Put bigger's mod value to 'biggerMod'
    Check and Put smaller's mod value to 'smallerMod'
    Check For all i (0 <= i <= 40,000 / 'biggerMod' + 1) whether ( 'bigger' + i * biggerMod ) mod smallerMod = smaller
        If there is an i fullfilling the condition, print bigger + i * biggerMod
    Else, print -1
    Repeat until ends 
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_data, M, N, x, y, bigger, biggerMod, smaller, smallerMod;
    cin >> num_data;

    while (num_data--) {
        cin >> M >> N >> x >> y;
        if (x > y) {
            bigger = x;     biggerMod = M;
            smaller = y;    smallerMod = N;
        }
        else {
            bigger = y;     biggerMod = N;
            smaller = x;    smallerMod = M;
        }
        int upperLimit = ((M*N) / biggerMod) + 2;
        int found, foundIndex = -1;
        for (int i = 0; i < upperLimit; ++i) {
            found = bigger + i * biggerMod;
            if (found % smallerMod == smaller % smallerMod) {
                foundIndex = i;
                break;
            }
        }
        if (foundIndex == -1)
            cout << -1 << '\n';
        else
            cout << found << '\n';

    }
    return 0;
}