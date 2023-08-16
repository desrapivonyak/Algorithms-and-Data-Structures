#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &);
void selection_sort(std::vector<int> &);
void insertion_sort(std::vector<int> &);

int binary_search_iterative(const std::vector<int>&, int);
int binary_search_recursive(const std::vector<int>&, int, int, int);

void swap(int &num1, int &num2) {
  int tmp = num1;
  num1 = num2;
  num2 = tmp;
}

void tests_sorting() {
  // Random Input
  std::vector<int> random_input = {5, 2, 9, 1, 5, 6};
  std::vector<int> random_expected = {1, 2, 5, 5, 6, 9};

  // Sorted Input
  std::vector<int> sorted_input = {1, 2, 3, 4, 5, 6};
  std::vector<int> sorted_expected = {1, 2, 3, 4, 5, 6};

  // Reverse Sorted Input
  std::vector<int> reverse_sorted_input = {9, 7, 5, 4, 3, 1};
  std::vector<int> reverse_sorted_expected = {1, 3, 4, 5, 7, 9};

  // Duplicate Elements
  std::vector<int> duplicate_input = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  std::vector<int> duplicate_expected = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};

  // Large Input
  std::vector<int> large_input = {10000, 5000, 100000, 25000, 75000, 30000};
  std::vector<int> large_expected = {5000, 10000, 25000, 30000, 75000, 100000};

  // Already Partially Sorted
  std::vector<int> partially_sorted_input = {1, 2, 5, 3, 6, 4};
  std::vector<int> partially_sorted_expected = {1, 2, 3, 4, 5, 6};

  // Empty Input
  std::vector<int> empty_input = {};
  std::vector<int> empty_expected = {};

  // Single Element
  std::vector<int> single_element_input = {42};
  std::vector<int> single_element_expected = {42};

  // All Same Elements
  std::vector<int> all_same_input = {7, 7, 7, 7, 7};
  std::vector<int> all_same_expected = {7, 7, 7, 7, 7};

  // Mixed Positive and Negative Numbers
  std::vector<int> mixed_input = {-5, 10, -3, 8, 0, -2};
  std::vector<int> mixed_expected = {-5, -3, -2, 0, 8, 10};

  // Perform sorting
  /*bubble_sort(random_input);
  bubble_sort(sorted_input);
  bubble_sort(reverse_sorted_input);
  bubble_sort(duplicate_input);
  bubble_sort(large_input);
  bubble_sort(partially_sorted_input);
  bubble_sort(mixed_input);

  selection_sort(random_input);
  selection_sort(sorted_input);
  selection_sort(reverse_sorted_input);
  selection_sort(duplicate_input);
  selection_sort(large_input);
  selection_sort(partially_sorted_input);
  selection_sort(mixed_input);*/

  insertion_sort(random_input);
  insertion_sort(sorted_input);
  insertion_sort(reverse_sorted_input);
  insertion_sort(duplicate_input);
  insertion_sort(large_input);
  insertion_sort(partially_sorted_input);
  insertion_sort(mixed_input);

  // Compare with expected outputs
  bool passed = true;
  if (random_input != random_expected || sorted_input != sorted_expected ||
      reverse_sorted_input != reverse_sorted_expected ||
      duplicate_input != duplicate_expected || large_input != large_expected ||
      partially_sorted_input != partially_sorted_expected ||
      empty_input != empty_expected ||
      single_element_input != single_element_expected ||
      all_same_input != all_same_expected || mixed_input != mixed_expected) {
    passed = false;
  }

  if (passed) {
    std::cout << "All test cases passed!" << std::endl;
  } else {
    std::cout << "Some test cases failed!" << std::endl;
  }
}

void tests_searching() {
  std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17};
  
  int testCases[] = {7, 1, 17, 10, 2};
    
  for (int target : testCases) {
    // int result = binary_search_iterative(sortedArray, target);
    int result = binary_search_recursive(sortedArray, target, 0, sortedArray.size() - 1);
    if (result != -1) {
      std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
      std::cout << "Element " << target << " not found" << std::endl;
    }
  }
}