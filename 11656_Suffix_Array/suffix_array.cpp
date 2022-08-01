#include <iostream>
#include <string>
using namespace std;

/*
MAIN:
    GET string
    MAKE a string array having length of string.length()
    PUT all suffice into string array
    BUBBLE SORT the array
    PRINT the array
*/

int main() {
    string input;
    cin >> input;

    const int word_length = input.length();
    string suffix_array[word_length];

    for (int i = word_length - 1; i >= 0; --i) {
        if (i == (word_length - 1)) {
            suffix_array[i] = input[i];
            continue;
        }
        suffix_array[i] = input[i] + suffix_array[i+1];
    }

    for (int i = 0; i < word_length - 1; ++i)
        for (int j = i; j < word_length; ++j)
            if (suffix_array[i] > suffix_array[j]) {
                string temporary = suffix_array[i];
                suffix_array[i] = suffix_array[j];
                suffix_array[j] = temporary;
            }

    for (int i = 0; i < word_length; ++i)
        cout << suffix_array[i] + '\n';

    return 0;
}