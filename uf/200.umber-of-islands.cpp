#include <iostream>
#include <vector>
using namespace std;

class Solution {
  class UF {
   public:
    UF(const vector<vector<char>> &grid) {
      int r = grid.size(), c = grid[0].size();
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (grid[i][j] == '1') {
            parent_.push_back(i * c + j);
            ++cnt_;
          } else {
            parent_.push_back(-1);
          }
          rank_.push_back(0);
        }
      }
    }

    int find(int i) {
      // 将i的父节点的父节点都设置为i的祖先节点
      if (parent_[i] != i) {
        parent_[i] = find(parent_[i]);
      }

      return parent_[i];
    }

    void unite(int i, int j) {
      int rooti = find(i);
      int rootj = find(j);
      if (rooti == rootj) {
        return;
      }

      if (rank_[rooti] < rank_[rootj]) {
        swap(rooti, rootj);
      }

      if (rank_[rooti] == rank_[rootj]) {
        rank_[rooti] += 1;
      }

      parent_[rootj] = parent_[rooti];
      cnt_--;
    }

    int count() const { return cnt_; }

   private:
    vector<int> parent_;
    vector<int> rank_;
    int cnt_ = 0;
  };

 public:
  int numIslands(vector<vector<char>> &grid) {
    int r = grid.size();
    if (r == 0) {
      return 0;
    }

    int c = grid[0].size();
    if (c == 0) {
      return 0;
    }

    UF set(grid);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == '1') {
          if (i + 1 < r && grid[i + 1][j] == '1') {
            set.unite(i * c + j, (i + 1) * c + j);
          }
          if (j + 1 < c && grid[i][j + 1] == '1') {
            set.unite(i * c + j, i * c + j + 1);
          }
        }
      }
    }
    return set.count();
  }
};

int main() {
  Solution s;
  vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '1', '0', '0'},
                            {'0', '0', '0', '1', '1'}};
  cout << s.numIslands(grid) << endl;

  return 0;
}
