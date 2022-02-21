#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <filesystem>

// g++ -std=c++17 Source.cpp -o source

std::vector<int> read_file(const std::string path)
{
	std::ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		std::cout << "Error with open file" << std::endl;
		return std::vector<int>();
	}

	std::string line;
	std::vector<int> result;

	while (!file.eof())
	{
		std::getline(file, line);
		if (line == "")
			continue;
		result.push_back(atoi(line.c_str()));
	}
	file.close();

	return result;
}

void search(std::string path, std::vector<int>* result)
{
	std::vector<int> temp;

	for (const auto &entry : std::filesystem::directory_iterator(path))
	{
		if (entry.is_regular_file())
		{
			temp = read_file(entry.path().generic_string());
			result->insert(result->end(), temp.begin(), temp.end());
		}
		else
		{
			search(entry.path().generic_string(), result);
		}
	}

	return;
}

int main()
{
	std::string path;
	path = "data";

	std::cout << "Check working directory_iterator:" << std::endl;

	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		std::cout << entry.path() << std::endl;
		std::cout << entry.is_directory() << std::endl;
		if (entry.is_directory()) {
			std::cout << entry.path() / "out" << std::endl;
		}
		std::cout << entry.is_regular_file() << std::endl;
	}

	std::cout << "\nCalculation summ:" << std::endl;

	std::vector<int>* result = new std::vector<int>;

	search(path, result);

	int summ = 0;
	for (int i = 0; i < result->size(); i++)
	{
		summ += (*result)[i];
	}

	std::cout << "Summ == " << summ << std::endl;

	system("pause");

	delete result;

	return 0;
}