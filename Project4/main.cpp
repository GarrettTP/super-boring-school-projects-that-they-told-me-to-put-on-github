#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Stack {
public:
	Stack() {}

	void Push(T& val) {
		m_data.push_back(val);
		m_top++;
	}

	T Pop() {
		T back = m_data.back();
		m_data.pop_back();
		m_top--;
		return back;
	}

	int Size() {
		return m_top;
	}

	T& operator[](int i) {
		return m_data[i];
	}
	
private:
	unsigned int m_top = 0;
	std::vector<T> m_data;
};

enum InputType {
	PUSH = 1, PUSH_MULT = 2, POP_PRINT_TOP = 3, POP_MULT_PRINT_SUM = 4, PRINT_SUM = 5
};

void Run() {
	// Create stack
	Stack<int> stack;

	// Get number of queries
	int q;
	std::cin >> q;

	// Process queries
	for (int i = 0; i < q; i++) {
		int t;
		std::cin >> t;

		switch ((InputType)t) {
		case PUSH:
			int x;
			std::cin >> x;

			stack.Push(x);
			break;
		case PUSH_MULT:
		{
			int n, x;
			std::cin >> n >> x;

			for (int j = 0; j < n; j++)
				stack.Push(x);
			break;
		}
		case POP_PRINT_TOP:
			if (stack.Size() > 0)
				std::cout << stack.Pop() << std::endl;
			else
				std::cout << 0 << std::endl;

			break;
		case POP_MULT_PRINT_SUM:
		{
			int n;
			std::cin >> n;

			int sum = 0;
			for (int j = 0; j < std::min(n, stack.Size()); j++) {
				sum += stack.Pop();
			}
			std::cout << sum << std::endl;
			break;
		}
		case PRINT_SUM:
			int sum = 0;
			for (int j = 0; j < stack.Size(); j++) {
				sum += stack[j];
			}
			std::cout << sum << std::endl;
			break;
		}
	}
}

int main() {
	Run();
	system("pause");
}