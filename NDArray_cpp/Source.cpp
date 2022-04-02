﻿#include <iostream>

#include "NDArray.hpp"

using namespace std;

int main()
{
	NDArray<int> arr(3, 3, 2);
	std::cout << arr[pair<int, int>(0, 1)] << std::endl;

	arr[pair<int, int>(2, 2)] = 8;

	std::cout << arr[pair<int, int>(0, 1)] << std::endl;
	std::cout << arr[pair<int, int>(2, 2)] << std::endl;

	
	NDArray<int> arr_1(3);
	NDArray<int> arr_2(3);
	for (int i = 0; i < arr_1.get_size(); i++)
	{
		arr_1[i] = i;
		arr_2[i] = i + 1;
	}

	std::cout << "Arr 1 == " << arr_1 << std::endl;
	std::cout << "Arr 2 == " << arr_2 << std::endl;

	auto res = arr_1 * arr_2;
	std::cout << "Res multiply === " << res << std::endl;

	//std::cout << arr[1];
	//NDArray<int>::random_values(1);
	
	return 0;
}