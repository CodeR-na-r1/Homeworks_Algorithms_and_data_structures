#include <iostream>
#include <fstream>
#include <vector>
#include <random>

//#include <corecrt_math_defines.h>
#define M_PI       3.14159265358979323846   // pi

using namespace std;

float my_random(const float min, const float max)
{
    return min + (static_cast<float>((float)rand() / RAND_MAX)) * (max - min);
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "Error with parameters" << endl;
        return -1;
    }

    srand(554);

    int n = atoi(argv[1]);

    fstream file;
    file.open(argv[2], ios::out);

    if (!file.is_open())
    {
        cout << "Error with opening file" << endl;
        return -2;
    }

    for (int i = 0; i < n; i++)
    {
        file << my_random(-M_PI, M_PI) << " " << my_random(-M_PI, M_PI) << " " << my_random(-M_PI, M_PI) << endl;
    }
    file.close();

    cout << "First program end" << endl;

    cout << "\n<------------------>\n" << endl;

    return 0;
}