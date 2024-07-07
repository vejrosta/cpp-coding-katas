#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>
#include <vector>


int partition(std::vector<int>& arr, int low, int high) {
	int pivot{arr[high]};
	int i{(low - 1)};

	for (int j{low}; j < high; ++j) {
		if (arr[j] < pivot) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quicksort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivot{partition(arr, low, high)};

		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

void quicksort(std::vector<int>& arr) {
    if (!arr.empty()) {
        quicksort(arr, 0, arr.size() - 1);
    }
}

#endif // QUICKSORT_H