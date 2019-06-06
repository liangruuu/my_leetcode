#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
  void __printReverse(const string &s, int index) {
    if (index == s.size())
      return;
    __printReverse(s, index + 1);
    cout << s[index];
  }

public:
  void printReverse(const string &s) {
    __printReverse(s, 0);
  }
};

int main() {
  string s = "hello";
  Solution().printReverse(s);
  return 0;
}