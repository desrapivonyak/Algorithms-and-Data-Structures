#include <vector>

int binary_search_iterative(const std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  
  while(left <= right) {
    int mid = left + (right - left) / 2;
    if(nums[mid] == target) {
      return mid;
    }
    if(target > nums[mid]) {
      left = mid + 1;
    }
    if(target < nums[mid]) {
      right = mid - 1;
    }
  }
  return -1;
}

int binary_search_recursive(const std::vector<int>& nums, int target, int left, int right) {
  int mid = left + (right - left) / 2;
  if(nums[mid] == target) {
    return mid;
  }
  if(left > right) {
    return -1;
  }
  if(nums[mid] > target) {
    return binary_search_recursive(nums, target, left, mid - 1);
  }
  else if(nums[mid] < target) {
    return binary_search_recursive(nums, target, mid + 1, right);
  }
}