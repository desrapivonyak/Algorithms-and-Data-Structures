#include <tuple>
#include <vector>
#include <limits>

//Brute force algorithm
std::tuple<int, int, int> max_subarray_version1(const std::vector<int> &nums) {
  int max_sum = std::numeric_limits<int>::min();
  int start_i = -1;
  int end_i = -1;
  int curr_sum = 0;

  for(int i = 0; i < nums.size(); ++i) {
    curr_sum = 0;
    for(int j = i; j < nums.size(); ++j) {
      curr_sum += nums[j];
      if(curr_sum > max_sum) {
        start_i = i;
        max_sum = curr_sum;
        end_i = j;
      }
    }
  }
  if(max_sum <= 0) return {-1, -1, 0};
  return {start_i, end_i, max_sum};
}

//Algorithm with O(n) time complexity
std::tuple<int, int, int> max_subarray_version3(const std::vector<int> &nums) {
  int start_i = 0;
  int end_i = 0;
  int max_sum = 0;
  int curr_sum = 0;
  int tmp = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (curr_sum + nums[i] > nums[i]) {
      curr_sum += nums[i];
    } else {
      curr_sum = nums[i];
      tmp = i;
    }
    if (curr_sum > max_sum) {
      max_sum = curr_sum;
      start_i = tmp;
      end_i = i;
    }
  }
  if (max_sum <= 0)
    return {-1, -1, 0};
  return {start_i, end_i, max_sum};
}

//Algorithm with O(nlogn) complexity
std::tuple<int, int, int> max_cross_subarray(const std::vector<int> &nums, int low, int mid, int high) {
  int left_sum = std::numeric_limits<int>::min();
  int max_left_index = mid;
  int max_sum = 0;

  for(int i = mid; i >= low; --i) {
    max_sum += nums[i];
    if(left_sum < max_sum) {
      left_sum = max_sum;
      max_left_index = i;
    }
  }

  int right_sum = std::numeric_limits<int>::min();
  int max_right_index = mid + 1;
  max_sum = 0;

  for(int i = mid + 1; i <= high; ++i) {
    max_sum += nums[i];
    if(max_sum > right_sum) {
      right_sum = max_sum;
      max_right_index = i;
    }
  }
  return {max_left_index, max_right_index, left_sum + right_sum};
}

std::tuple<int, int, int> max_subarray_version2(const std::vector<int> &nums, int low, int high) {
  std::tuple<int, int, int> left;
  std::tuple<int, int, int> right;
  std::tuple<int, int, int> cross;
  
  if(low == high) {
    return {low, high, nums[low]};
  }
  
  int mid = low + (high - low) / 2;
  left = max_subarray_version2(nums, low, mid);
  right = max_subarray_version2(nums, mid + 1, high);
  cross = max_cross_subarray(nums, low, mid, high);
  
  if(std::get<2>(left) >= std::get<2>(right) && std::get<2>(left) >= std::get<2>(cross)) {
    return left;
  }
  else if(std::get<2>(right) >= std::get<2>(left) && std::get<2>(right) >= std::get<2>(cross)) {
    return right;
  }
  else {
    return cross;
  }
}