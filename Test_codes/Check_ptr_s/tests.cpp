// tests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int ptr[8][8] = { 0 };
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ptr[i][j] = 8 * i + j;
            std::cout << ptr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    auto x = (*(ptr + 1)) +1;   // 9
    std::cout << *(ptr + 1);   // 8

    int* temp = new int[10];
    for (int j = 0; j < 10; j++)
    {
        temp[j] = j;
    }
    int* y = new (temp)int[8];  // !!!!!!!!!!   (Указываем что память берем уже с выделенного участка)
    for (int j = 0; j < 10; j++)    // для y мы выходим за рамки (можно только для temp)
    {
        std::cout << std::endl << *(y + j) << std::endl;
    }
    y = nullptr;
    delete[] temp;
}
