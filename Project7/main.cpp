#include <iostream>
#include <algorithm>

struct Node {
	Node(int v) : left(nullptr), right(nullptr), val(v) {}
	int val;
	Node* left;
	Node* right;

	int Insert(int v) {
		if (v < val) {
			if (left)
				return left->Insert(v) + 1;
			else
				left = new Node(v);
			return 1;
		}
		else {
			if (right)
				return right->Insert(v) + 1;
			else
				right = new Node(v);
			return 1;
		}
	}
};

struct BTree {
	void Add(int val) {
		if (!head)
			head = new Node(val);
		else
			maxDepth = std::max(head->Insert(val)+1, maxDepth);
	}

	Node* head = nullptr;
	int maxDepth = 1;
};


int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;

		BTree tree;
		for (int j = 0; j < n; j++) {
			int x;
			std::cin >> x;

			tree.Add(x);
		}

		std::cout << tree.maxDepth << std::endl;
	}

	system("pause");
}