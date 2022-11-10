#include <iostream>

struct Node {
	Node(int v) : left(nullptr), right(nullptr), val(v) {}
	int val;
	Node* left;
	Node* right;

	void Insert(int v) {
		if (v <= val) {
			if (left)
				left->Insert(v);
			else
				left = new Node(v);
		}
		else {
			if (right)
				right->Insert(v);
			else
				right = new Node(v);
		}
	}

	bool Find(int v) {
		if (v < val) {
			if (left)
				return left->Find(v);
		}
		else if (v > val) {
			if (right)
				return right->Find(v);
		}
		else {
			return true;
		}
		return false;
	}
};

struct BTree {
	void Add(int val) {
		if (!head)
			head = new Node(val);
		else
			head->Insert(val);
	}

	bool Find(int val) {
		return head->Find(val);
	}

	Node* head = nullptr;
	int maxDepth = 1;
};

int main() {
	// Get num tests
	/*int t;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		std::cin >> n >> m;

		BTree tree;
		for (int j = 0; j < n; j++) {
			int x;
			std::cin >> x;

			tree.Add(x);
		}

		for (int j = 0; j < m; j++) {
			int x;
			std::cin >> x;

			std::cout << (tree.Find(x) ? "YES" : "NO") << std::endl;
			tree.Add(x);
		}
	}*/

	char x = 0;

	std::cout << (int)(--x) << std::endl;

	system("pause");
}