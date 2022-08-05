#include <iostream>
#include <string>
using namespace std;

/*
MAIN:
    GET sentence input

    CREATE integer array with 26 length
    SET all members in array to be 0

    FOR: scan for whole sentence
        SET array[recently scanned alphabet - 'a'] += 1
    
    FOR scan the array.
        PRINT member of array
        IF current member is not a last member in the array
            PRINT space
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string sentence;
    cin >> sentence;

    int* array = new int[26];
    for (int i = 0; i < 26; ++i)
        array[i] = 0;

    for (char current : sentence)
        ++array[current - 'a'];

    for (int i = 0; i < 26; ++i) {
        cout << array[i];
        if (i != 25)
            cout << ' ';
    }
    
    return 0;
}