//*******************************************************************
//iterative approach
// perform insertion sort on arr[]
void insertionSort_iterative(int arr[], int n)
{
	// Start from second element (element at index 0 
	// is already sorted)
	for (int i = 1; i < n; i++) 
	{
		int value = arr[i];
		int j = i;
		
		// Find the index j within the sorted subset arr[0..i-1]
		// where element arr[i] belongs
		while (j > 0 && arr[j - 1] > value) 
		{
			arr[j] = arr[j - 1];
			j--;
		}

		// Note that subarray arr[j..i-1] is shifted to
		// the right by one position i.e. arr[j+1..i]
		
		arr[j] = value;
	}
}
//*******************************************************************
// recursive function to perform insertion sort on subarray arr[i..n]
void insertionSort_recursive(int arr[], int i, int n)
{ 
	int value = arr[i];
	int j = i;

	// Find index j within the sorted subset arr[0..i-1]
	// where element arr[i] belongs
	while (j > 0 && arr[j - 1] > value) 
	{
		arr[j] = arr[j - 1];
		j--;
	}

	arr[j] = value;

	// Note that subarray arr[j..i-1] is shifted to
	// the right by one position i.e. arr[j+1..i]
 
	if (i + 1 <= n) {
		insertionSort_recursive(arr, i + 1, n);
	}
}
//***************************************************
// Function to print n elements of the array arr
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
//***************************************************
//***************************************************
int main(void)
{
	int arr[] = { 3, 8, 5, 4, 1, 9, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
  
  
  //call recursive approach
	// Start from second element (element at index 0 
	// is already sorted)
	insertionSort_recursive(arr, 1, n - 1);
  
  //call iterative approach
  	insertionSort_iterative(arr, n);

	// print the sorted array
	printArray(arr, n);

	return 0;
}
 
