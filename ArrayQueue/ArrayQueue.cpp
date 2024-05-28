#include <iostream>

void EnQueue(int queue[], int dataSize, int &end, int value);
void DeQueue(int queue[], int &end);
void PrintQueue(int queue[], int end);

int main()
{
	int dataSize, end{};
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
		std::cout << "1 : Enqueue 2: Dequeue > ";
		std::cin >> number;

		if (number == 1)
		{
			int value;
			std::cout << "value? ";
			std::cin >> value;

			EnQueue(data, dataSize, end, value);
			PrintQueue(data, end);
		}
		else if (number == 2)
		{
			DeQueue(data, end);
			PrintQueue(data, end);
		}
	}

	delete[] data;
}

void EnQueue(int queue[], int dataSize, int &end, int value)
{
	if (end >= dataSize)
	{
		std::cout << "out of size" << std::endl;
		return;
	}

	queue[end++] = value;
}

void DeQueue(int queue[], int &end)
{
	if (end <= 0)
	{
		std::cout << "out of size" << std::endl;
		return;
	}

	for (int i = 0; i <= end; ++i)
	{
		queue[i] = queue[i + 1];
	}

	end--;
}

void PrintQueue(int queue[], int end)
{
	std::cout << "----Queue----" << std::endl;
	for (int i = 0; i < end; ++i)
	{
		std::cout << queue[i] << " ";
	}
	std::cout << std::endl;
}