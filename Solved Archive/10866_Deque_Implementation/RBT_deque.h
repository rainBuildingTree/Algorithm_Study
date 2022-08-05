template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <typename T>
class RBT_deque {
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int length = 0;
    public:
        void push_front(T input) {
            ++length;
            if (!head) {
                head = new Node<T>;
                head->data = input;
                tail = head;
                return;
            }
            Node<T>* temp = tail;
            tail = new Node<T>;
            tail->data = input;
            tail->prev = temp;
            temp->next = tail;
        }
        void push_back(T input) {
            ++length;
            if (!head) {
                head = new Node<T>;
                head->data = input;
                tail = head;
                return;
            }
            Node<T>* temp = head;
            head = new Node<T>;
            head->data = input;
            head->next = temp;
            temp->prev = head;
        }
        void pop_front() {
            if (!head)
                return;

            --length;
            if (!length) {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            temp = nullptr;

            if (!tail)
                head = nullptr;
        }
        void pop_back() {
            if (!head)
                return;
            
            --length;
            if (!length) {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }

            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            temp = nullptr;

            if (!head)
                tail = nullptr;

        }

        int size() const {
            return length;
        }
        bool empty() const {
            if (!head)
                return true;
            return false;
        }
        T front() const {
            if (!head)
                return -1;
            return tail->data;
        }
        T back() const {
            if (!head)
                return -1;
            return head->data;
        }
};