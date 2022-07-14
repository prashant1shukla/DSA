// You are given a sorted array consisting of only integers where every element appears exactly twice, 
// except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.
#include <iostream>
using namespace std;
int search(int nums[], int n)
{

	// A Binary Search based method to find the element
	// that appears only once
	int start = 0, end = n - 1, mid;

	// For Edge Cases
	if (n == 1) // If only one element is in the array
		return nums[0];

	if (nums[start]
		!= nums[start + 1]) // If the first element
							// is the element that
							// appears only once
		return nums[start];

	if (nums[end]
		!= nums[end - 1]) // If Last element is the element
						// that appears only once
		return nums[end];

	// Binary Search
	while (start <= end)
	{
		mid = start + (end - start) / 2;
	
		// CASE 1
		if (nums[mid] != nums[mid - 1]
			&& nums[mid] != nums[mid + 1])
			return nums[mid];
	
		// CASE 2 and CASE 3
		else if ((nums[mid] == nums[mid + 1]
				&& mid % 2 == 0)
				|| (nums[mid] == nums[mid - 1]
					&& mid % 2 != 0))
			start = mid + 1;
	
		// CASE 4 and CASE 5
		else
			end = mid - 1;
	}

	// If no such element found
	return -1;
}

// Driver code
int main()
{
	int arr[] = { 1, 1, 2, 4, 4, 5, 5, 6, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int element = search(arr, n);

	if (element != -1)
		cout << "The required element is " << element;
	else
		cout << "There is no such element";
}

// This code is contributed by umadevi9616
