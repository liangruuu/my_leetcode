#include <iostream>
#include <vector>

using namespace std;
/**
 * https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/discuss/20573/A-concise-C++-implementation-based-on-Directions
 * 螺旋矩阵，一般在二维矩阵中方向矩阵directors是一个常用的trick, directors每个元素由用户自定义, 一般第一个位行，第二个为列
 * 如{0, 1}表示行不变，列+1, 从几何上来看就是向右平移一个单位
 * 定义了一个方向矩阵之后需要在循环中每次对行索引和列索引分别加上directors元素上行列对应干的值
 * 这个方向矩阵在回溯法在二维平面上的应用是重点方法
 */

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<vector<int>> directors = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0}
    };
    vector<int> arr;
    int r = matrix.size();
    if (r == 0) return arr;
    int c = matrix[0].size();
    if (c == 0) return arr;
    vector<int> steps = {c, r - 1};
    int iDir = 0;
    int ir = 0, ic = -1;
    while (steps[iDir % 2]) {
      for (int i = 0; i < steps[iDir % 2]; i++) {
        ir += directors[iDir][0];
        ic += directors[iDir][1];
        arr.push_back(matrix[ir][ic]);
      }
      steps[iDir % 2]--;
      iDir = (iDir + 1) % 4;
    }
    return arr;
  }
};

int main() {
  vector<vector<int>> matrix = {
      {1, 2,  3,  4},
      {5, 6,  7,  8},
      {9, 10, 11, 12}
  };
  vector<int> arr;
  arr = Solution().spiralOrder(matrix);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}