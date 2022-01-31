#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Cities
{
	string reg;
	string name;
	double lat;
	double lng;
};

int main()
{
	const char* name = "cities.txt";
	ifstream in;
	in.open(name);

	if (!in.is_open())
	{
		cout << "Error with open input file" << endl;
		return -1;
	}

	struct Cities temp;
	string shortes_name;
	getline(in, shortes_name);
	in >> shortes_name >> shortes_name;
	in.seekg(ios::beg, 0);
	getline(in, temp.reg);

	while (!in.eof())
	{
		in >> temp.reg >> temp.name >> temp.lat >> temp.lng;

		if (in.fail())
		{
			break;
		}

		if (temp.name.size()<shortes_name.size())
			shortes_name = temp.name;
	}

	in.close();

	cout << "Shortes name of city: " << shortes_name << endl;

	return 0;
}