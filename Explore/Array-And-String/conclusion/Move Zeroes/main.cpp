#include <iostream>
#include <vector>

using namespace std;

/**
 * 双指针，一前一后，后面的指针i覆盖前面的指针j
 */
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int length = nums.size();
    if (length == 0)
      return;
    int i = 0, j = 0;
    while (i < length) {
      if (nums[i] != 0) {
        nums[j++] = nums[i];
      }
      i++;
    }
    for (int i = j; i < length; i++) {
      nums[i] = 0;
    }
  }
};

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution().moveZeroes(nums);
  for (int e: nums) {
    cout << e << " ";
  }
  return 0;
}