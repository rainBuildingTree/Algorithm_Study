#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> left_stack;
    stack<char> right_stack;

    string input_first;
    getline(cin, input_first);

    for (char character : input_first)
        left_stack.push(character);

    int order_count;
    cin >> order_count;

    while (order_count--) {
        char user_input;
        cin >> user_input;

        // 현재 작성위치 ("|")의 왼쪽과 오른쪽을 각각 스택에 저장
        // 왼쪽으로 이동시 오른쪽 스택에서 pop해서 왼쪽 스택에 push
        // 오른쪽으로 이동시 왼쪽 스택에서 pop해서 오른쪽 스택에 push
        // 백스페이스 입력시 왼쪽 스택에서 하나 pop해서 버리기
        // 글자 입력시 입력 받아서 왼쪽 스택에 push하기
        switch (user_input) {
            case 'L':
                if (left_stack.empty())
                    break;
                right_stack.push(left_stack.top());
                left_stack.pop();
                break;
            case 'D':
                if (right_stack.empty())
                    break;
                left_stack.push(right_stack.top());
                right_stack.pop();
                break;
            case 'B':
                if (left_stack.empty())
                    break;
                left_stack.pop();
                break;
            case 'P':
                char input;
                cin >> input;
                left_stack.push(input);
                break;
        }

    }

    // 왼쪽 스택내용을 순서대로 pop해서 임시 스택(output_stack)에 순서대로 push
    // 임시 스택에서 순서대로 pop한 char들을 출력
    // 오른쪽 스택에서 순서대로 pop한 char들을 출력
    stack<char> output_stack;
    while (!left_stack.empty()) {
        output_stack.push(left_stack.top());
        left_stack.pop();
    }
    while (!output_stack.empty()) {
        cout << output_stack.top();
        output_stack.pop();
    }
    while (!right_stack.empty()) {
        cout << right_stack.top();
        right_stack.pop();
    }
    return 0;
}