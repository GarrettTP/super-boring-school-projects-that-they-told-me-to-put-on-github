#include <iostream>
#include <vector>
#include <algorithm>

// Stores a list of prices and handles queries
class DataSet : public std::vector<int> {
public:
	void Sort() {
		std::sort(begin(), end());
	}

	int RunQuery(int maxPrice) {
		return std::upper_bound(begin(), end(), maxPrice - 1) - begin();
	}
};


void run() {
	// Capture num unique video games
	int n;
	std::cin >> n;

	// Capture array of prices
	DataSet prices;
	prices.reserve(n);

	for (int i = 0; i < n; i++) {
		int price;
		std::cin >> price;

		prices.push_back(price);
	}

	// Sort prices
	prices.Sort();

	// Capture Q number of queries
	int q;
	std::cin >> q;

	// Run queries
	std::vector<int> queries;
	queries.reserve(q);

	for (int i = 0; i < q; i++) {
		int query;
		std::cin >> query;

		std::cout << prices.RunQuery(query) << std::endl;
	}
}


int main() {
	run();
}