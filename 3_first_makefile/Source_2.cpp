#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Error with parameters" << endl;
        return -1;
    }

    fstream file;
    
    file.open(argv[1], ios::in);

    if (!file.is_open())
    {
        cout << "Error with opening file" << endl;
        return -2;
    }

    float x;
    float angle;
    int count_kit(0);
    while (!file.eof())
    {
        file >> x;    // x
        angle = 2 * sin(x);

        file >> x;    // y
        angle *= sin(x);

        file >> x;    // z
        angle += cos(x);

        cout << "Angle for kit: " << ++count_kit << ": " << angle << endl;
    }

    file.close();

    cout << "Second program end" << endl;

    getchar();

    return 0;
}