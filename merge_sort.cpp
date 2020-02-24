#include <iostream>

using namespace std;

// A function to merge the two half into a sorted data.
void Merge(int arr[], int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int a, b, c, temp[high-low+1];
	a = low;
	c = 0;
	b = mid + 1;

	// Merge the two parts into temp[].
	while (a <= mid && b <= high)
	{
		if (arr[a] < arr[b])
		{
			temp[c] = arr[a];
			c++;
			a++;
		}
		else
		{
			temp[c] = arr[b];
			c++;
			b++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (a <= mid)
	{
		temp[c] = arr[a];
		c++;
		a++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (b <= high)
	{
		temp[c] = arr[b];
		c++;
		b++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (a = low; a <= high; a++)
	{
		arr[a] = temp[a-low];
	}
}

// A function to split array into two parts.
void MergeSort(int arr[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);

		// Merge them to get sorted output.
		Merge(arr, low, high, mid);
	}
}

int main()
{
    cout<<"Program to implement merge sorting"<<endl;
    cout<<"<--------------------------------------->"<<endl;
	int arrSize;
	cout<<"Enter the array size to be sorted: "<<endl;;
	cin>>arrSize;

	int arr[arrSize];
	for(int i = 0; i < arrSize; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}

	MergeSort(arr, 0, arrSize-1);

	// Displaying the sorted data.
	cout<<"Sorted Data Display "<<endl;
	for (int i = 0; i < arrSize; i++)
        cout<<arr[i]<<",";

	return 0;
}
