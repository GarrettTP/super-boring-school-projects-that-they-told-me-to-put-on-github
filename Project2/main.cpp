#include <iostream>
#include <vector>
#include <algorithm>

class DataSet : public std::vector<int> {
public:
	void Sort() {
		std::sort(begin(), end());
	}

	// Compares a boys data set with a girls data set
	bool Compare(const DataSet& data) {
		for (int i = 0; i < size(); i++) {
			if (at(i) <= data.at(i)) {
				return false;
			}
		}

		return true;
	}
};

// Runs single test
bool RunTest() {
	// Get number of girls and boys
	int m, n;
	std::cin >> m >> n;

	// Create data sets
	DataSet boys;
	DataSet girls;
	for (int i = 0; i < m; i++) {
		int h;
		std::cin >> h;

		boys.push_back(h);
	}
	for (int i = 0; i < n; i++) {
		int h;
		std::cin >> h;

		girls.push_back(h);
	}

	// If less girls than boys, return false
	if (n < m)
		return false;

	// Sort data
	boys.Sort();
	girls.Sort();

	return boys.Compare(girls);
}

// Runs all tests
void Run() {
	// Get num test cases
	int numTests;
	std::cin >> numTests;

	// Run tests
	for (int i = 0; i < numTests; i++) {
		std::cout << (RunTest() ? "YES" : "NO") << std::endl;
	}
}

int main() {
	Run();
	system("pause");
}