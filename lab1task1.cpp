#include<iostream>
using namespace std;

int searchArr(int arr[],int key,int size)
{
	
	int ran=0;
	for (int i = 0; i < size; i++)
	{
		ran=i;
		if (arr[i] == key)
		{
			return i ;
			
		}
	}
	if (ran <= size)
	{
		cout << "Not Found" << endl;
		return -1;
	}
}
int main()
{
	const int size = 10;
	int arr[size];
	cout << "Enter 10 Elements of Array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	int key;
	cout << "Enter key to search in Array: ";
	cin >> key;
	int index=searchArr(arr, key, size);
	if(index!=-1)
	cout <<key<< " found at index " << index << endl;
}