#include <iostream>
#include <fstream>

#include <vector>
#include <map>

#include <chrono>
#include <cmath>
#include <thread>
#include <windows.h>

using namespace std;

int main()
{
	//map<int, int> data;
	vector<int> data;
	ofstream file("data.txt");
	chrono::duration<float, std::milli> time;

	if (!file.is_open())
	{
		cout << "error with open output file" << endl;
		return -1;
	}

	int max_count = pow(10, 8);
	int key = 0;

	thread t([&key, max_count]() {while (key < max_count) { cout << '\r' << key; Sleep(2000); }});

	auto start_time = chrono::high_resolution_clock::now();

	for (int i = 1; i <= max_count; i *= 10)
	{
		for (; key <i; key++)
		{
			data.push_back(key);
			//data.insert(make_pair(key, key));
		}
		time = chrono::high_resolution_clock::now() - start_time;
		cout << endl<<i<<" "<< (i == data.size()) << " " << time.count() << " " << data.capacity()  << endl;
	}
	t.join();
	file.close();

	return 0;
}