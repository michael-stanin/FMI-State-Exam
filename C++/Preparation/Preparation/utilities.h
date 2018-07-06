#pragma once

template<class T>
void customSwap(T& left, T& right)
{
	T temp(left);
	left = right;
	right = temp;
}

template<class T, size_t N>
void customSwap(T(&left)[N], T(&right)[N])
{
	for (size_t i = 0; i < N; i++) {
		customSwap(left[i], right[i]);
	}
}

template<class T, size_t N>
constexpr size_t customSize(T(&)[N])
{
	return N;
}

template<class T, size_t N>
void printArr(T(&arr)[N])
{
	for (size_t i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	cout << endl;
}

// Merges the two halves arr[left..mid] and arr[mid+1..right] of arr[]
void merge(int arr[], const int& left, const int& right, const int& mid)
{
	int i, j, k;
	const int n1 = mid - left + 1;
	const int n2 = right - mid;

	// Create temp arrays
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	
	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	// Merge the temp arrays back into arr[left..right]
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i++];
		}
		else {
			arr[k] = R[j++];
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		arr[k++] = L[i++];
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		arr[k++] = R[j++];
	}

	// Cleanup
	delete L;
	delete R;
	L = nullptr;
	R = nullptr;
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right) {
		// Find the middle point to divide the array into two halves
		const int mid = (left + right) / 2;
		
		// Call mergeSort for the first half
		mergeSort(arr, left, mid);

		// Call mergeSort for the second half
		mergeSort(arr, mid + 1, right);

		// Merge the two halves sorted in previous steps
		merge(arr, left, right, mid);
	}

	return;
}

template<class T>
struct IComparator
{
	virtual bool operator()(T& left, T& right) = 0;
};

template<class T>
struct DigitComparator : public IComparator<T>
{
	bool operator()(T& left, T& right) override
	{
		return left > right;
	}
};

template<class T>
struct CharComparator : public IComparator<T>
{
	bool operator()(T& left, T& right) override
	{
		return strcmp(&left, &right) > 0;
	}
};

template<class T>
void bubbleSort(T* arr, int len, IComparator<T>& cmp)
{
	for (int i = len - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (cmp(arr[j], arr[j + 1])) {
				customSwap(arr[j], arr[j + 1]);
			}
		}
	}
}