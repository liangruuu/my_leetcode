#include <iostream>
#include <vector>

using namespace std;
/**
 * 在解二维数组有关的题目时一般需要注意行索引和列索引的关系
 * 比如这题：当(rIndex+cIndex) % 2== 0时是从右下到左上，当(rIndex+cIndex) % 2 == 1时是从左上到右下
 * 但是还需要区分特殊情况，特殊情况一般在rIndex == 0 || rIndex == m - 1(cIndex == 0 || cIndex == m - 1)
 */

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0)
      return vector<int>(0);
    int r = 0, c = 0, m = matrix.size(), n = matrix[0].size();
    vector<int> arr(n * m);
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = matrix[r][c];
      if ((r + c) % 2 == 0) {
        if (c == n - 1)
          r++;
        else if (r == 0)
          c++;
        else {
          r--;
          c++;
        }
      } else {
        if (r == m - 1)
          c++;
        else if (c == 0)
          r++;
        else {
          r++;
          c--;
        }
      }
    }
    return arr;
  }
};

void print_vec(const vector<int> &vec) {
  for (int e:vec) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  print_vec(Solution().findDiagonalOrder(matrix));
  return 0;
}