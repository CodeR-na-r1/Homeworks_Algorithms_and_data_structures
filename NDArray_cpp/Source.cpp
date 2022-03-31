#include <iostream>

#include "NDArray.hpp"

using namespace std;

int main()
{
	NDArray<int> arr(3, 3, 2);

	arr[pair<int, int>(2, 2)] = 8;

	std::cout << arr[pair<int, int>(0, 1)] << std::endl;
	std::cout << arr[pair<int, int>(2, 2)];
	//std::cout << arr[1];

	//NDArray<int>::random_values(1, 1);

	return 0;
}