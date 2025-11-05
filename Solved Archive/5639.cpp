#include <iostream>
using namespace std;

struct Node {
	int *key;
	Node *left, *right;

	Node(int key) : key(new int(key)), left(nullptr), right(nullptr) {}
	~Node() {
		delete key; 
		delete left; 
		delete right; 
		left = nullptr; 
		right = nullptr; 
	}

	void insert(int in_key) {
		if (in_key < *key) {
			if (left) left->insert(in_key);
			else left = new Node(in_key);
		}
		else {
			if (right) right->insert(in_key);
			else right = new Node(in_key);
		}
	}

	void postorder() {
		if (left) left->postorder();
		if (right) right->postorder();
		cout << *key << '\n';
	}
};

struct BST {
	Node *root;

	BST() : root(nullptr) {}
	BST(int key) : root(new Node(key)) {}
	~BST() {
		delete root;
		root = nullptr;
	}

	void insert(int key) {
		if (!root) 
			root = new Node(key);
		else
			root->insert(key);
	}

	void postorder() {
		if (!root)
			return;
		root->postorder();
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	BST bst;
	int input;
	while (cin >> input)
		bst.insert(input);

	bst.postorder();

	return 0;
}