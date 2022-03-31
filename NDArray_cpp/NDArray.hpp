#pragma once

#include <type_traits>

#include <iostream>

#include <cassert>

template<typename T, typename Enable = void>
class NDArray;

template <class T>
class NDArray <T, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, float>::value || std::is_same<T, double>::value>::type>
{
public:

	NDArray(int size, T fill = 0)	 // �������� ������� ������� ��������� ������� and �������� ������� ������������ ������
	{
		this->ptr = new T[size];
		this->size = size;

		this->ndim = 1;
		this->shape.first = 1;
		this->shape.second = size;

		for (int i = 0; i < this->size; i++)
		{
			this->ptr[i] = fill;
		}
		
		return;
	}

	NDArray(int size_rows, int size_cols, T fill) : NDArray(size_rows * size_cols, fill)	 // �������� ������� ���������� ������� ��������� ������� and �������� ���������� ������� ������������ ������
	{
		this->ndim = size_rows > 1 ? 2 : 1;
		this->shape.first = size_rows;
		this->shape.second = size_cols;

		return;
	}

	static NDArray ones(int size_rows, int size_cols)	 // �������� ������� ������������ ���������
	{
		return NDArray(size_rows, size_cols, 1);
	}

	static NDArray random_values(int size_rows, int size_cols)	 // �������� ������� ������������ ���������� ���������
	{
		NDArray res(size_rows, size_cols, 0);

		for (int i = 0; i < res.get_size_rows(); i++)
		{
			for (int j = 0; j < res.get_size_cols(); j++)
			{
				res[std::pair<int, int>(i, j)] = rand();
			}
		}

		return res;
	}

	T& operator[](std::pair<int, int> indexes)
	{
		if (this->ndim == 1)
		{
			assert((indexes.first + indexes.second) < this->size);	// ��� ����� �������� ������ � � ������ � �� ������ �������� ����
			return this->ptr[indexes.first + indexes.second];
		}
		else if (this->ndim == 2)
		{
			assert((indexes.first * this->shape.second + indexes.second) < this->size);	// ��� ����� �������� ������ � � ������ � �� ������ �������� ����
			return this->ptr[indexes.first * this->shape.second + indexes.second];
		}
		else
		{
			throw "Current NDIM not supported in operator []";
		}
	}

	T& operator[](int index)
	{
		if (this->ndim == 1)
		{
			assert(index < this->size);
			return this->ptr[index];
		}
		else
		{
			throw "Current NDIM not supported in operator [] with one parameter";
		}
	}

	int get_size()
	{
		return this->size;
	}

	int get_size_rows()
	{
		return this->shape.first;
	}

	int get_size_cols()
	{
		return this->shape.second;
	}

	~NDArray()
	{
		delete[] this->ptr;

		return;
	}

private:
	T* ptr;
	int size;

	int ndim;
	std::pair<int, int> shape;	// first == quantity rows and second == quantity columns || vector
};