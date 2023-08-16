#include <vector>

void swap(int&, int&);

void bubble_sort(std::vector<int> &array) {
  for (int i = 0; i < array.size(); ++i) {
    for (int j = 0; j < array.size(); ++j) {
      if (array[i] < array[j]) {
        swap(array[i], array[j]);
      }
    }
  }
}