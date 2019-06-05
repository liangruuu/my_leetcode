#include <iostream>
#include <vector>

using namespace std;
// https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/discuss/119387/C++JavaPython-Concise-One-Pass-Solution-with-Explanation

// 找到两个最大的数max1，max2，若max1 > max2 * 2，则max1大于所有数组内的元素*2
// 否则max1只要存在一个数max2，使得max1 < max2 * 2，不满足题意

class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    int max1 = 0, max2 = 0, maxIndex = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > max1) {
        max2 = max1;
        max1 = nums[i];
        maxIndex = i;
      } else if (nums[i] > max2) {
        max2 = nums[i];
      }
    }
    if (max1 >= 2 * max2)
      return maxIndex;
    else
      return -1;
  }
};

int main() {
  return 0;
}