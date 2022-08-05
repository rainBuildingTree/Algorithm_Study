#include <iostream>
using namespace std;

template <typename T>
struct rbt_uninode {
    T data;
    rbt_uninode<T>* next = nullptr;
};

template <typename T>
struct rbt_binode {
    T data;
    rbt_binode<T>* next = nullptr;
    rbt_binode<T>* prev = nullptr;
};
template <typename T>
class rbt_stack {
    private:
        rbt_uninode<T>* head = nullptr;
        int length = 0;
    public:
        ~rbt_stack() {
            if (head)
                for (rbt_uninode<T>* k = head->next; k != nullptr;) {
                    rbt_uninode<T>* temp = k;
                    k = k->next;
                    delete temp;
                }
            delete head;
        }
        void push(T input) {
            ++length;
            if (!head) {
                head = new rbt_uninode<T>;
                head->data = input;
                return;
            }
            rbt_uninode<T>* temp = new rbt_uninode<T>;
            temp->data = input;
            temp->next = head;
            head = temp;
            temp = nullptr;
        }
        void pop() {
            if (!head)
                return;

            --length;
            if (!length) {
                delete head;
                head = nullptr;
                return;
            }

            rbt_uninode<T>* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
        int size() const {
            return length;
        }
        int empty() const {
            if (!head)
                return true;
            return false;
        }
        T top() const {
            if (head)
                return head->data;
            else
                return -1;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int repeat_numb;
    rbt_stack<int> stack;
    string current_order;

    cin >> repeat_numb;
    for (int i = 0; i < repeat_numb; ++i) {
        cin >> current_order;
        
        if (current_order == "push") {
            int input;
            cin >> input;
            stack.push(input);
        }
        else if (current_order == "pop") {
            cout << stack.top() << '\n';
            if (!stack.empty())
                stack.pop();
        }
        else if (current_order == "size")
            cout << stack.size() << '\n';
        else if (current_order == "empty")
            cout << stack.empty() << '\n';
        else if (current_order == "top")
            cout << stack.top() << '\n';
    }

    return 0;
}