#include "SearchingAlgorithms.h"

#include <iostream>
#include <Bits.h>

int LinearSearch(int array[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == x)
			return i;
	}

	return -1;
}

int BinarySearch(int array[], int low, int high, int x)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		if (array[mid] == x)
			return mid;

		if (array[mid] > x)
			return BinarySearch(array, low, mid - 1, x);

		return BinarySearch(array, mid + 1, high, x);
	}

	return -1;
}

int JumpSearch(int array[], int n, int x)
{
	int step = sqrt(n);

	int prev = 0;
	while (array[min(step, n) - 1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	while (array[prev] < x)
	{
		prev++;

		if (prev == min(step, n))
			return -1;
	}

	if (array[prev] == x)
		return prev;

	return -1;
}

void TestSearch()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Linear search" << std::endl;
	int result = LinearSearch(arr, n, x);
	(result == -1) ? std::cout << "Element is not present in array"
		: std::cout << "Element is present at index " << result << std::endl;

	std::cout << "Binary search" << std::endl;
	result = BinarySearch(arr, 0, n, x);
	(result == -1) ? std::cout << "Element is not present in array"
		: std::cout << "Element is present at index " << result << std::endl;

	std::cout << "Jump search" << std::endl;
	result = JumpSearch(arr, n, x);
	(result == -1) ? std::cout << "Element is not present in array"
		: std::cout << "Element is present at index " << result << std::endl;
}