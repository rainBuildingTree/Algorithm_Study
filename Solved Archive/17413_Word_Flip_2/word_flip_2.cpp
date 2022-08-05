#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
MAIN:
    GET string S
    FOR scan S
        IF current char is '<' then check if it is a tag
        IF it is a tag then skip until '>'
        
        ELSE space is there
        skip

        ELSE
        KEEP the beginning of the word
        PUT word into a stack until empty
        POP from stack from the point kept as a beginning of the word
    
    PRINT edited sentence
*/

int main() {
    string sentence_input;
    getline(cin, sentence_input);

    stack<char> stack_flipper;

    int sentence_length = sentence_input.size();
    int flip_start_at;
    bool checking_tag = false;
    bool flipping = false;
    for (int i = 0; i < sentence_length; ++i) {
        char c = sentence_input[i];

        if (c == '<')
            checking_tag = true;
        else if (c == '>') {
            checking_tag = false;
            continue;
        }

        if (flipping) {
            bool finish_flipping = false;
            if (c == ' ')
                finish_flipping = true;
            else if (checking_tag)
                finish_flipping = true;
            else if (i == (sentence_length - 1)) {
                finish_flipping = true;
                stack_flipper.push(c);
                ++i;
            }

            if (finish_flipping) {
                for (int j = flip_start_at; j < i; ++j) {
                    sentence_input[j] = stack_flipper.top();
                    stack_flipper.pop();
                }
                flipping = false;
                continue;
            }

            stack_flipper.push(c);
        }
        else {
            if (!checking_tag) {
                flip_start_at = i;
                flipping = true;
                stack_flipper.push(c);
            }
        }
    }

    cout << sentence_input << endl;

    return 0;
}