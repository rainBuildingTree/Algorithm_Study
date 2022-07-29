#include "RBT_Node.h"

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