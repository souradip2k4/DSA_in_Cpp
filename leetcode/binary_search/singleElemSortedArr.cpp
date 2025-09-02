// https://leetcode.com/problems/single-element-in-a-sorted-array/
// 540. Single Element in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	if (n == 1) {
		return arr[0];
	}

	if (arr[0] != arr[1]) {

		return arr[0];
	}
	if (arr[n - 1] != arr[n - 2])
	{
		return arr[n - 1];
	}

	int l = 1, r = n - 2;
	int mid = l + (r - l) / 2;

	while (l <= r)
	{
		if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
			return arr[mid];
		}
		else if (mid % 2 == 0)
		{
			if (arr[mid] == arr[mid - 1])
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		else
		{
			if (arr[mid] == arr[mid + 1])
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}

		mid = l + (r - l) / 2;
	}

	return -1;
}

int main()
{
	// (1,1) (even, odd) -> Left half
	// (3,3), (4,4), (8,8) (odd, even) -> right half
	vector<int> arr1 = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };

	cout << singleNonDuplicate(arr1) << endl;
}