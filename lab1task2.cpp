#include<iostream>
using namespace std;

int Binarysearch(int arr[], int key, int size)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (key < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	
	if (low>high)
	{
		cout << "Not Found" << endl;
		return -1;
	}
}
int main()
{
	const int size = 10;
	int arr[size] = {22,23,35,36,38,40,42,43,44,49};
	
	int key;
	cout << "Enter key to search in Array: ";
	cin >> key;
	int index = Binarysearch(arr, key, size);
	if (index != -1)
		cout << key << " found at index " << index << endl;
	return 0;
}