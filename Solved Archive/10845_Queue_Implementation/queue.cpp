#include <iostream>
#include <string>
using namespace std;

/*
struct node
이중연결 linked list
data
next
prev

push: (head)
SET head to be new node having user input data. new head's next is former head.

pop: (tail)
IF tail is null pointer
    PRINT -1
    RETURN
PRINT tail's data
tail's prev's next to be nullptr and delete tail by allocate tail to be tail's prev and delete temp

size: (head)
scan from head to tail check length

empty: (head)
IF head is nullptr then print 1 else 0

front (head)
IF head is nullptr then print -1
PRINT head's data

back (tail)
IF tail is nullptr then print -1
print tail's data
*/

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

Node* push(Node* head, int input) {
    Node* temp = new Node;
    temp->data = input;
    if (!head)
        return temp;
    temp->next = head;
    temp->next->prev = temp;
    return temp;
}

Node* pop(Node* tail) {
    if (!tail) {
        cout << -1 << '\n';
        return nullptr;
    }
    cout << tail->data << '\n';
    Node* temp = tail->prev;
    if (temp)
        temp->next = nullptr;
    delete tail;
    return temp;
}

void size(Node* head) {
    int length = 0;
    for (Node* k = head; k != nullptr; k=k->next)
        ++length;
    cout << length << '\n';
}

void empty(Node* head) {
    if (!head) {
        cout << 1 << '\n';
        return;
    }
    cout << 0 << '\n';
}

void front(Node* head) {
    if (!head) {
        cout << -1 << '\n';
        return;
    }
    cout << head->data << '\n';
}

void back(Node* tail) {
    if (!tail) {
        cout << -1 << '\n';
        return;
    }
    cout << tail->data << '\n';
}

/*
main:
et cetera

get user input to count order_count

WHILE: loop for order_count:
    GET input
    IF push
        GET input
        func push
    ELIF pop
        func pop
    ELIF empty
        func empty
    ELIF size
        func size
    ELIF front
        func front
    ELIF back
        func back
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int order_count;
    cin >> order_count;


    Node* head = nullptr;
    Node* tail = nullptr;
    while (order_count--) {
        string user_order;
        cin >> user_order;
        if (user_order == "push") {
            int user_input;
            cin >> user_input;
            head = push(head, user_input);
            if (!tail)
                tail = head;
        }
        else if (user_order == "pop") {
            tail = pop(tail);
            if (!tail)
                head = tail;

        }
        else if (user_order == "empty") {
            empty(head);
        }
        else if (user_order == "size") {
            size(head);
        }
        else if (user_order == "front") {
            back(tail);
        }
        else if (user_order == "back") {
            front(head);
        }
    }
    return 0;
}