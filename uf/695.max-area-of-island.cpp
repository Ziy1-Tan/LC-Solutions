#include <vector>
#include <iostream>
using namespace std;

class Solution
{
    class UFSet
    {
    public:
        UFSet(const vector<vector<int>> &grid)
        {
            int r = grid.size(), c = grid[0].size();
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        parent_.push_back(i * c + j);
                        cnt_.push_back(1);
                        max_ = 1;
                    }
                    else
                    {
                        parent_.push_back(-1);
                        cnt_.push_back(0);
                    }
                }
            }
        }

        int find(int i)
        {
            // 将i的父节点的父节点都设置为i的祖先节点
            if (parent_[i] != i)
            {
                parent_[i] = find(parent_[i]);
            }

            return parent_[i];
        }

        void unite(int i, int j)
        {
            int rooti = find(i);
            int rootj = find(j);

            if (rooti == rootj)
            {
                return;
            }
            
            parent_[rooti] = rootj;
            cnt_[rootj] += cnt_[rooti];
            max_ = std::max(cnt_[rootj], max_);
        }

        int max() const
        {
            return max_;
        }

    private:
        vector<int> parent_;
        vector<int> cnt_;
        int max_ = 0;
    };

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int r = grid.size();
        if (r == 0)
        {
            return 0;
        }

        int c = grid[0].size();
        if (c == 0)
        {
            return 0;
        }
        UFSet set(grid);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (grid[i][k] == 1)
                {
                    if (i + 1 < r && grid[i + 1][k] == 1)
                    {
                        set.unite(i * c + k, (i + 1) * c + k);
                    }
                    if (k + 1 < c && grid[i][k + 1] == 1)
                    {
                        set.unite(i * c + k, i * c + k + 1);
                    }
                }
            }
        }

        return set.max();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid{
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}
