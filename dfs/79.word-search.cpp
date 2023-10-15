#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int n;
  int m;
  vector<vector<char>> board;
  string word;
  bool exist(vector<vector<char>>& board, string word) {
    this->n = board.size();
    this->m = board[0].size();
    this->board = board;
    this->word = word;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0] && dfs(i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(int i, int j, int k) {
    if (k >= word.size()) {
      return true;
    }
    if (i < 0 || i >= n || j < 0 || j >= m) {
      return false;
    }

    if (board[i][j] == '&') {
      return false;
    }

    char c = board[i][j];
    if (c != word[k]) {
      return false;
    }

    board[i][j] = '&';
    bool exist = dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1) ||
                 dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1);
    board[i][j] = c;
    return exist;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<char>> board{{'A'}};
  auto res = (new Solution)->exist(board, "A");
  cout << res << endl;
  return 0;
}
