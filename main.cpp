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

// Time Complexity : n * n * 4 = O(n^2)
// Space Complexity : O(n)
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

// Time Complexity : (n * (n - 1)) / 2 = O(n^2);
// Space Complexity :O(1)
void SelectionSort(int numbers[], int count)
{
	for (int i = 0; i < count - 1; ++i) 
	{
		int min{i};
		for (int j = i + 1; j < count; ++j) 
		{
			if (numbers[min] > numbers[j])
			{
				min = j;
			}
		}

		if (min != i)
		{
			int temp = numbers[i];
			numbers[i] = numbers[min];
			numbers[min] = temp;
		}
	}
}

//Time Complexity : O(n^2)
//Space Complexity : O(1) 
void BubleSort(int numbers[], int count)
{
	for (int phase = 0; phase < count - 1; ++phase)
	{
		for (int k = 0; k < count - 1 - phase; ++k)
		{
			if (numbers[k] > numbers[k + 1])
			{
				int temp = numbers[k];
				numbers[k] = numbers[k + 1];
				numbers[k + 1] = temp;
			}
		}
	}
}

//Time Complexity : O(n^2)
//Space Complexity : O(1)
void InsertionSort(int numbers[], int count)
{
	for (int i = 1; i < count; ++i)
	{
		int j = i - 1;
		int target = numbers[i];

		while (j >= 0 && target < numbers[j])
		{
			numbers[j + 1] = numbers[j];
			--j;
		}

		numbers[j + 1] = target;
	}
}

/*---------------------------------------------------------------------------*/

void Merge(int numbers[], int start, int half, int end, int temp[])
{
	int i = start;
	int j = half + 1;
	int tempIndex{};

	//����
	while (i <= half && j <= end)
	{
		if (numbers[i] < numbers[j])
		{
			temp[tempIndex++] = numbers[i++];
		}
		else
		{
			temp[tempIndex++] = numbers[j++];
		}
	}

	//�迭���� �����ִ°� ����
	while (i <= half)
	{
		temp[tempIndex++] = numbers[i++];
	}
	while (j <= end)
	{
		temp[tempIndex++] = numbers[j++];
	}

	//���յ� ��� ���� �迭�� ����
	for (int k = 0; k <= tempIndex; ++k)
	{
		numbers[start + k] = temp[k];
	}
}

// Time Complexity : O(nlogn)
// Space Complexity : O(n)
void MergeSort(int numbers[], int start, int end, int temp[])
{
	if (start >= end)
	{
		return;
	}

	//���� �����÷ο� ����
	int half = start + (end - start) / 2;

	MergeSort(numbers, start, half, temp);
	MergeSort(numbers, half + 1, end, temp);

	Merge(numbers, start, half, end, temp);
}
//MergeSort�� ����(temp �޸�)�� �����ϴ� ����
void QuickSort(int numbers[], int start, int end)
{
	int i = start;
	int j = end;
	int pivot = numbers[(start + end) / 2];

	do
	{
		while (numbers[i] < pivot)
		{
			i++;
		}
		while (numbers[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;

			i++;
			j--;
		}
	} while (i <= j);

	if (start < j)
	{
		QuickSort(numbers, start, j);
	}
	
	if (i < end)
	{
		QuickSort(numbers, i, end);
	}
}

void PrintArray(int numbers[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	const int SIZE_ARRAY{ 10 };
	int scores[SIZE_ARRAY]{ 20, 10, 40, 30, 70, 90, 80, 60, 50, 100 };


	//SequentialSort(scores, SIZE_ARRAY, Ascending);
	//SelectionSort(scores, SIZE_ARRAY);
	//BubleSort(scores, SIZE_ARRAY);
	//InsertionSort(scores, SIZE_ARRAY);

	/*int temp[SIZE_ARRAY]{};
	MergeSort(scores, 0, SIZE_ARRAY - 1, temp);*/

	//QuickSort(scores, 0, SIZE_ARRAY - 1);

	PrintArray(scores, SIZE_ARRAY);
	
}