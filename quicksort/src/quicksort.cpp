#include <algorithm>
#include <vector>

namespace {
int partition(std::vector<int> &arr, int low, int high) {
  auto const pivot{arr[high]};
  auto i{(low - 1)};

  for (auto j{low}; j < high; ++j) {
    if (arr[j] < pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quicksort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    auto const pivot{partition(arr, low, high)};

    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}
} // namespace

void quicksort(std::vector<int> &arr) {
  if (!arr.empty()) {
    quicksort(arr, 0, arr.size() - 1);
  }
}
