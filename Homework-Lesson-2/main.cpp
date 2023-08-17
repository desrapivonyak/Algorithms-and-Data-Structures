#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>

std::tuple<int, int, int> max_subarray_version1(const std::vector<int>&);
std::tuple<int, int, int> max_subarray_version2(const std::vector<int>&, int, int);
std::tuple<int, int, int> max_subarray_version3(const std::vector<int>&);

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int numTestCases = 10;

    for (int i = 0; i < numTestCases; ++i) {
        // Generate a random array size between 5 and 20
        int size = std::rand() % 16 + 5;

        // Generate random numbers for the array
        std::vector<int> nums;
        for (int j = 0; j < size; ++j) {
            int num = std::rand() % 201 - 100; // Random number between -100 and 100
            nums.push_back(num);
        }

        std::tuple<int, int, int> result = max_subarray_version1(nums);
        std::tuple<int, int, int> result1 = max_subarray_version2(nums, 0, nums.size() - 1);
        std::tuple<int, int, int> result2 = max_subarray_version3(nums);

        // Print the test case
        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Array: ";
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << "\n";

        // Print the result
        std::cout << "Start Index: " << std::get<0>(result) << "\n";
        std::cout << "End Index: " << std::get<1>(result) << "\n";
        std::cout << "Max Sum: " << std::get<2>(result) << "\n\n";
      
        std::cout << "Start Index: " << std::get<0>(result1) << "\n";
        std::cout << "End Index: " << std::get<1>(result1) << "\n";
        std::cout << "Max Sum: " << std::get<2>(result1) << "\n\n";

        std::cout << "Start Index: " << std::get<0>(result2) << "\n";
        std::cout << "End Index: " << std::get<1>(result2) << "\n";
        std::cout << "Max Sum: " << std::get<2>(result2) << "\n\n";
    }
    return 0;
}