#include <vector>

void swap(int&, int&);

void selection_sort(std::vector<int>& array) {
  for(int i = 0; i < array.size() - 1; ++i) {
    int min_index = i;
    for(int j = i + 1; j < array.size(); ++j) {
      if(array[j] < array[min_index]) {
        min_index = j;
      }
    }
    swap(array[i], array[min_index]);
  }
}