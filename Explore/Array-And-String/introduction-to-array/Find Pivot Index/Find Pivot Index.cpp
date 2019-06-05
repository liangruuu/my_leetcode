class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int curSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if((sum - nums[i]) / 2.0 == curSum){
        return i;
      }
      curSum += nums[i];
    }
    return -1;
  }
};