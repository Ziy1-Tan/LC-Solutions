// dfs+剪枝
// 递归深度，数组越界，当前字符不等于目标字符
// 时间复杂度 O(3^kMN) k是字符串长度 MN是数组行列
// (每次搜索有3个方向(字符不能重复使用)，一共k次，任意起点出发)
// 空间复杂度 O(K)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    this->rows = board.size();
    this->cols = board[0].size();
    //任意位置搜索
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->cols; j++) {
        if (dfs(board, word, i, j, 0))
          return true;
      }
    }
    return false;
  }

private:
  int rows, cols;
  bool dfs(vector<vector<char>> &board, const string &word, int i, int j,
           int k) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k])
      return false;
    if (k == word.size() - 1)
      return true;
    // 比较过的字符标记为'\0'
    board[i][j] = '\0';
    // 上下左右四个方向搜索
    bool res = dfs(board, word, i - 1, j, k + 1) ||
               dfs(board, word, i + 1, j, k + 1) ||
               dfs(board, word, i, j - 1, k + 1) ||
               dfs(board, word, i, j + 1, k + 1);
    // 回溯
    board[i][j] = word[k];
    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<vector<char>> board{{'a'}};
  auto res = (new Solution)->exist(board, "ab");
  cout << res << endl;
  return 0;
}