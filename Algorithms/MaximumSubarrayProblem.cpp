#include "MaximumSubarrayProblem.h"
#include <iostream>
#include <utility>
#include <vector>

std::pair < std::pair<int, int>, int > FindMaxCrossingSubarray(std::vector<int> A, int low, int mid, int high)
{
	int max_left, max_right;
	std::pair<std::pair<int, int>, int> result;

	int left_sum = INT_MIN;
	int sum = 0;
	int i = mid;
	for(auto it = A.begin() + (mid + 1); it != A.begin(); it--, i--)
	{
		sum += *(it - 1);
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	int right_sum = INT_MIN;
	sum = 0;
	i = mid + 1;
	for (auto it = A.begin() + (mid + 2); it != A.end(); it++, i++)
	{
		sum += *(it - 1);
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}

	return std::make_pair(std::make_pair(max_left, max_right), left_sum + right_sum);
}

std::pair < std::pair<int, int>, int > FindMaximumSubarray(std::vector<int> A, int low, int high)
{
	if (high == low)
	{
		return std::make_pair(std::make_pair(low, high), A[low]);
	}
	else
	{
		int mid = (low + high) / 2;
		std::pair<std::pair<int, int>, int> left = FindMaximumSubarray(A, low, mid);
		std::pair<std::pair<int, int>, int> right = FindMaximumSubarray(A, mid+1, high);
		std::pair<std::pair<int, int>, int> cross = FindMaxCrossingSubarray(A, low, mid, high);

		if (left.second >= right.second && left.second >= cross.second)
			return std::make_pair(std::make_pair(left.first.first, left.first.second), left.second);
		else if (right.second >= left.second && right.second >= cross.second)
			return std::make_pair(std::make_pair(right.first.first, right.first.second), right.second);
		else
			return std::make_pair(std::make_pair(cross.first.first, cross.first.second), cross.second);
	}
}

void TestMaximumSubarrayProblem()
{
	std::vector<int> A;

	A.push_back(13);
	A.push_back(-3);
	A.push_back(-25);
	A.push_back(20);
	A.push_back(-3);
	A.push_back(-16);
	A.push_back(-23);
	A.push_back(18);
	A.push_back(20);
	A.push_back(-7);
	A.push_back(12);
	A.push_back(-5);
	A.push_back(-22);
	A.push_back(15);
	A.push_back(-4);
	A.push_back(-7);

	auto x = FindMaximumSubarray(A, 0, A.size() - 1);

	std::cout << x.first.first << std::endl;
	std::cout << x.first.second << std::endl;
	std::cout << x.second << std::endl;
}