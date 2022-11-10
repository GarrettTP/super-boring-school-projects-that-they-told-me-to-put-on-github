#include <iostream>
#include <string>

int Test(std::string word1, std::string word2) {
	char* ref = (char*)calloc(26, sizeof(char));

	for (int i = 0; i < word1.size(); i++)
		ref['z' - word1[i]]++;

	for (int i = 0; i < word2.size(); i++)
		ref['z' - word2[i]]--;

	int result = 0;
	for (int i = 0; i < 26; i++)
		result += abs(ref[i]);

	free(ref);

	return result;
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string word1, word2;
		std::cin >> word1 >> word2;

		std::cout << Test(word1, word2) << std::endl;
	}
}