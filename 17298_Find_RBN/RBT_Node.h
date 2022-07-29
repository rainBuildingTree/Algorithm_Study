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