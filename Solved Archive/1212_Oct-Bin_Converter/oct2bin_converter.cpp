//HELLO WORLD!
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    
    if (input == "0") {
        cout << 0;
        return 0;
    }

    queue<string> output;
    int length = input.length();
    for (int i = 0; i < length; ++i) {
        if (i == 0) {
            switch (input[i]) {
                case '1':
                    output.push("1");
                    break;
                case '2':
                    output.push("10");
                    break;
                case '3':
                    output.push("11");
                    break;
                case '4':
                    output.push("100");
                    break;
                case '5':
                    output.push("101");
                    break;
                case '6':
                    output.push("110");
                    break;
                case '7':
                    output.push("111");
                    break;
            }
        }
        else {
            switch (input[i]) {
                case '0':
                    output.push("000");
                    break;
                case '1':
                    output.push("001");
                    break;
                case '2':
                    output.push("010");
                    break;
                case '3':
                    output.push("011");
                    break;
                case '4':
                    output.push("100");
                    break;
                case '5':
                    output.push("101");
                    break;
                case '6':
                    output.push("110");
                    break;
                case '7':
                    output.push("111");
                    break;
            }
        }
    }

    while (!output.empty()) {
        cout << output.front();
        output.pop();
    }
}