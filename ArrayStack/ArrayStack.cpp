// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

//자기 참조 구조체
struct Bullet
{
	int damage;
	float speed;
	float size;

	Bullet *pNext;
};

void Push(int stack[], int dataSize, int &top, int value);
void Pop(int stack[], int &top);
void PrintStack(int stack[], int top);

int main()
{
	int dataSize, top{};
	std::cout << "Input data Size : ";
	std::cin >> dataSize;

	int *data = new int[dataSize];
	if (!data)
	{
		std::cout << "memeory leak in main()" << std::endl;
		return -1;
	}

	while (true)
	{
		int number;
		std::cout << "1 : push 2: pop > ";
		std::cin >> number;

		if (number == 1)
		{
			int value;
			std::cout << "value? ";
			std::cin >> value;

			Push(data, dataSize, top, value);
			PrintStack(data, top);
		}
		else if (number == 2)
		{
			Pop(data, top);
			PrintStack(data, top);
		}
	}

	delete[] data;
}

void Push(int stack[], int dataSize, int &top, int value)
{
	if (top >= dataSize)
	{
		std::cout << "out of size" << std::endl;
		return;
	}

	stack[top++] = value;
}

void Pop(int stack[], int &top)
{
	if (top < 0)
	{
		std::cout << "out of size" << std::endl;
		return;
	}

	stack[top--];
}

void PrintStack(int stack[], int top)
{
	std::cout << "----Stack----" << std::endl;
	for (int i = top - 1; i >= 0; --i)
	{
		std::cout << stack[i] << std::endl;
	}
}