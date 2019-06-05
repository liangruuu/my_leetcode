#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/**
 * 数字相加需要考虑进位，直接把sum的初值赋值成进位carry
 * 还需要考虑的是最高位仍有进位的情况及carry!=0但是i,j已经遍历完
 */
class Solution {
public:
  string addBinary(string a, string b) {
    string s = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
      int sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';
      s += (sum % 2) + '0';
      carry = sum / 2;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};

int main() {
  string a = "1011", b = "1010";
  string s = Solution().addBinary(a, b);
  cout << s << endl;
  return 0;
}