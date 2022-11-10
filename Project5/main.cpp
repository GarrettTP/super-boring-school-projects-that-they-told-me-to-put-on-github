#include <iostream>

void Run() {
	int n, k;
	std::cin >> n >> k;

	int sum = 0;
	int* in = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		in[i] = x;

		if (i < k)
			sum += x;
	}

	int max = 0;
	for (int i = 0; i < k; i++) {
		sum = sum + in[n-i-1] - in[k-i-1];
		if (sum > max)
			max = sum;
	}

	free(in);

	std::cout << max << std::endl;
}


int main() {
	Run();
	system("pause");
}