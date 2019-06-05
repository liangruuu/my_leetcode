#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
 * 双指针做法，一个在前，一个在后
 */
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int length = nums.size();
    if (length == 0)
      return 0;
    int i = 1, j = 1;
    while (i < length) {
      if (nums[i] != nums[i - 1]) {
        nums[j++] = nums[i];
      }
      i++;
    }
    return j;
  }
};

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int len = Solution().removeDuplicates(nums);
  for (int i = 0; i < len; i++) {
    cout << nums[i] << " ";
  }
  return 0;
}