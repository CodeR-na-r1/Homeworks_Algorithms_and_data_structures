#include <iostream>
#include <string>

using namespace std;

unsigned char my_hash(string data)
{
	unsigned char res = 0;

	for (int i = 0; i < 8; i++)	// по битам
	{
		for (int j = 0; j < data.length(); j++)	// по строкам
		{
			res ^= ((data[j] >> i) & 1) << i;
		}
	}

	return res;
}

int main()
{
	string input;

	cout << "Enter input: ";

	cin >> input;

	cout << "Hash == " << my_hash(input);
	cout << " (";

	unsigned char value = my_hash(input);
	for (int i = 7; i >= 0; i--)
	{
		cout << ((value >> i) & 1);
	}

	cout << ")" << endl;

	return 0;
}