#include <vector>

void merge(std::vector<int>& nums, int first, int mid, int last) {
  int first_1 = first;
  int last_1 = mid;
  int first_2 = mid + 1;
  int last_2 = last;
  std::vector<int> tmp(last - first + 1);
  int index = 0;
  while(first_1 <= last_1 && first_2 <= last_2) {
    if(nums[first_1] <= nums[first_2]) {
      tmp[index] = nums[first_1];
      ++index;
      ++first_1;
    }
    else {
      tmp[index] = nums[first_2];
      ++index;
      ++first_2;
    }
  }
  while(first_1 <= last_1) {
    tmp[index] = nums[first_1];
    ++index;
    ++first_1;
  }

  while(first_2 <= last_2) {
    tmp[index] = nums[first_2];
    ++index;
    ++first_2;
  }

  for(int i = 0; i < index; i++) {
    nums[first + i] = tmp[i];
  }
}

void merge_sort(std::vector<int>& nums, int first, int last) {
  int mid = first + (last - first)/ 2;
  if(first < last) {
    merge_sort(nums, first, mid);
    merge_sort(nums, mid + 1, last);
    merge(nums, first, mid, last);
  }
}