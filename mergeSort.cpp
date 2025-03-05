#include <iostream>
#includer <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	std::vector<int> L(n1), R(n2);
	
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m +1 +j];
		
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i <n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		arr[k] = R[j];
		j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main() {
	std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
	mergeSort(numbers, 0, number.size() - 1);
	
	std::cout << "Sorted array: ";
	for (int num: numbers) {
		std::cout << num << " ";
	}
	std:: cout << std::endl;
	return 0;
}