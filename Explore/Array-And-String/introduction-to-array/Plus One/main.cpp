//
// Created by liangruuu on 2019/6/4.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int size = digits.size();
    for (int i = size - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      } else
        digits[i] = 0;
    }
    vector<int> newDigits(size + 1);
    newDigits[0] = 1;
    return newDigits;
  }
};

int main(void) {
  vector<int> digits(4);
  for (int i = 0; i < 4; i++) {
    cin >> digits[i];
  }
  vector<int> newDigits = Solution().plusOne(digits);
  for (int i = 0; i < newDigits.size(); i++) {
    cout << newDigits[i] << " ";
  }
}