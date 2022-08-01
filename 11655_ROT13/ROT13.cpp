#include <iostream>
#include <string>
using namespace std;

/*
MAIN:
    GET a sentence
    FOR: scan the sentence
        SET alphabet_number = (int)current
        IF alphabet
            IF lower-case
                CAL alphabet_number = alphabet_number - 'a'
                CAL (alphabet_number + 16) % 26
                CAL alphabet_number = alphabet_number + 'a'
            ELSE
                CAL alphabet_number = alphabet_number - 'A'
                CAL (alphabet_number + 16) % 26
                CAL alphabet_number = alphabet_number + 'A'
        PRINT (char)alphabet_number;
*/

int main() {
    string sentence;
    int current_alphabet_number;
    getline(cin, sentence);
    for (char current : sentence) {
        current_alphabet_number = (int)current;
        if ((current >= 'A') && (current <= 'Z')) {
            current_alphabet_number -= 'A';
            current_alphabet_number += 13;
            current_alphabet_number %= 26;
            current_alphabet_number += 'A';
        }
        else if ((current >= 'a') && (current <= 'z')) {
            current_alphabet_number -= 'a';
            current_alphabet_number += 13;
            current_alphabet_number %= 26;
            current_alphabet_number += 'a';
        }
        cout << (char)current_alphabet_number;
    }   
    return 0;
}