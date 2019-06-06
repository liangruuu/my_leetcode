#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<char> __reverseString(vector<char> &s, int index, vector<char> &subStr) {
    if (index == s.size())
      return subStr;
    subStr.insert(subStr.begin(), s[index]);
    return __reverseString(s, index + 1, subStr);
  }

public:
  void reverseString(vector<char> &s) {
    vector<char> subStr(0);
    s = __reverseString(s, 0, subStr);
  }
};

int main() {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  Solution().reverseString(s);
  for (char e:s) {
    cout << e << " ";
  }
  return 0;
}