#include <iostream>


// Big O Notation
// 1. 곱하기 - 변수를 제외한 상수는 무시
//				4 * n * n = n * n
// 2. 더하기 - 더 높은 차수만 사용
//				n + 6 = n
// 3. 조건 - worst case

//n개의 데이터를 처리할 때 A 알고리즘과 B 알고리즘을 비교하기 위해

using Comparison = bool (*)(int, int);

bool Ascending(int x, int y)
{
	return x > y;
}

bool Desecding(int x, int y)
{
	return x < y;
}

// Time Complexity : n * n * 4
// Space Complexity : n + 7;
// Sequential Sort 
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

void SelectiontialSort(int numbers[], int count)
{
	int min{};

	for (int i = 0; i < count; ++i) // n - 1
	{
		for (int j = 0; j < count; ++j) //
		{
			if (numbers[i] < numbers[j])
			{
				min = i;
			}
		}
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

	SequentialSort(scores, SIZE_ARRAY, Ascending);

	PrintArray(scores, SIZE_ARRAY);
}