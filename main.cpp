#include <iostream>


// Big O Notation
// 1. ���ϱ� - ������ ������ ����� ����
//				4 * n * n = n * n
// 2. ���ϱ� - �� ���� ������ ���
//				n + 6 = n
// 3. ���� - worst case

//n���� �����͸� ó���� �� A �˰���� B �˰����� ���ϱ� ����

using Comparison = bool (*)(int, int);

bool Ascending(int x, int y)
{
	return x > y;
}

bool Desecding(int x, int y)
{
	return x < y;
}

// Time Complexity : n * n * 4 = O(n);
// Space Complexity : n + 7 = O(n);
void SequentialSort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count - 1; ++i) // n - 1
	{
		for (int j = i + 1; j < count; ++j) //
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

void SelectionSort(int numbers[], int count)
{
	int min{};
	for (int i = 0; i < count - 1; ++i) 
	{
		for (int j = i + 1; j < count; ++j) 
		{
			if (numbers[i] > numbers[j])
			{
				min = j;
			}
		}

		int temp = numbers[min];
		numbers[min] = numbers[i];
		numbers[i] = temp;
	}
}

int Add(int x, int y)
{
	return x + y; 
}

int Sum(int numbers[], int count)
{
	int total{};					
	for (int i = 0; i < count; ++i)	
	{
		total += numbers[i];		
	}
	return total;					
}

void PrintArray(int input[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	const int SIZE_ARRAY{ 10 };
	int scores[SIZE_ARRAY]{ 20, 10, 40, 30, 70, 90, 80, 60, 50, 100 };

	SelectionSort(scores, SIZE_ARRAY);

	PrintArray(scores, SIZE_ARRAY);
}