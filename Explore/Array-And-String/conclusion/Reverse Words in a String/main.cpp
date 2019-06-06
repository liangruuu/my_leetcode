#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/**
 * 这道题的思路是先翻转整个字符串，再翻转各个单词字符串
 * 一. 如果要反转首先得知道单词字符串的首尾节点索引(这里就可以用两个索引i, j来指代，i在前，j在后)
 * 每次遍历完每个单词后把j的值赋值给i
 * 二. 对于这种空间复杂度限制为O(1)的情况一般涉及到覆盖原有字符串,这时往往需要设置第三个索引k
 * k的位置在i，j之前，当操作完ij之后把得到的值赋值给arr[k],因为k远远在i，j之前，
 * 所以不用担心arr[k]的值被修改,因为当arr[k]被修改时它早就被利用过了，覆盖不覆盖已经无所谓了
 */

class Solution {
public:
  string reverseWords(string s) {
    int storeIndex = 0, length = s.size();
    reverse(s.begin(), s.end());
    for (int i = 0; i < length; i++) {
      if (s[i] != ' ') {
        if (storeIndex != 0)
          s[storeIndex++] = ' ';
        int j = i;
        while (j < length && s[j] != ' ') {
          s[storeIndex++] = s[j++];
        }
        reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
        i = j;
      }
    }
    s.resize(storeIndex);
    return s;
  }
};

int main() {
  string s = "  hello world!  ";
  cout << Solution().reverseWords(s);
  return 0;
}