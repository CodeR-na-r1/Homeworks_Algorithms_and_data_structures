#include <iostream>
#include <fstream>

#include <map>

#include <chrono>
#include <cmath>

using namespace std;

int main()
{
	map<int, int> data;
	ofstream file("data.txt");
	chrono::duration<float, std::milli> time;

	if (!file.is_open())
	{
		cout << "error with open output file" << endl;
		return -1;
	}

	int max_count = pow(10, 7);
	int key = 0;

	cout << "Start calc" << endl;

	auto start_time = chrono::high_resolution_clock::now();

	for (int i = 1; i <= max_count; i *= 10)
	{
		cout << "\r" << i << " / " << max_count;
		for (; key <i; key++)
		{
			data.insert(make_pair(key, key));
		}
		time = chrono::high_resolution_clock::now() - start_time;
		file << i << " " << " " << time.count() << " " << data.size() * sizeof(int) << endl;
	}
	file.close();

	return 0;
}