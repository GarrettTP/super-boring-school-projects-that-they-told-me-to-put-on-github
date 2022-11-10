#include <iostream>

struct Node {
	Node(int d) : data(d), next(nullptr) {}
	Node* next;
	int data;
};

// Reverse a section of the list
void Reverse(Node* start, Node* end) {
	Node* next = nullptr;
	Node* current = start->next;
	Node* prev = end->next;

	start->next = end;

	while (current != end) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	end->next = prev;
}

// Traverse the list, print node data
void Output(Node* begin) {
	Node* current = begin;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
}

void Run() {
	// Get sample size
	int n;
	std::cin >> n;

	Node* begin = nullptr;

	// Create linked list
	Node* prev = nullptr;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;

		Node* newNode = new Node(x);

		if (prev)
			prev->next = newNode;

		prev = newNode;

		if (!begin)
			begin = newNode;
	}

	// Traverse linked list, finding subsets
	Node* entryPoint = new Node(-1);
	entryPoint->next = begin;

	Node* current = entryPoint;
	Node *b = entryPoint, *e = nullptr;
	bool even = false;
	while (true) {
		if (current != nullptr && current->data % 2 == 0) {
			e = current;
			even = true;
		}
		else {
			if (even)
				Reverse(b, e);

			if (current)
				b = current;

			even = false;
		}

		if (current)
			current = current->next;
		else
			break;
	}

	Output(entryPoint->next);
}

int main() {
	Run();
}