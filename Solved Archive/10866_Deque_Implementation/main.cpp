#include <iostream>
#include <string>
#include "rbt_deque.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    RBT_deque<int> deque_int;
    int order_count;
    cin >> order_count;

    while (order_count--) {
        string user_order;
        cin >> user_order;
        
        if (user_order == "push_front") {
            int user_input;
            cin >> user_input;
            deque_int.push_front(user_input);
        }
        else if (user_order == "push_back") {
            int user_input;
            cin >> user_input;
            deque_int.push_back(user_input);
        }
        else if (user_order == "pop_front") {
            if (!deque_int.empty()) {
                cout << deque_int.front() << '\n';
                deque_int.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if (user_order == "pop_back") {
            if (!deque_int.empty()) {
                cout << deque_int.back() << '\n';
                deque_int.pop_back();
            }
            else
                cout << -1 << '\n';
        }
        else if (user_order == "size") {
            cout << deque_int.size() << '\n';
        }
        else if (user_order == "empty") {
            cout << deque_int.empty() << '\n';
        }
        else if (user_order == "front") {
            if (!deque_int.empty())
                cout << deque_int.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else if (user_order == "back") {
        if (!deque_int.empty())
            cout << deque_int.back() << '\n';
        else
            cout << -1 << '\n';
        }
    }
    return 0;
}