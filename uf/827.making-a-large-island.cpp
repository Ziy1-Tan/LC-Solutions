#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
private:
    constexpr static int dx[] = {-1, 1, 0, 0};
    constexpr static int dy[] = {0, 0, -1, 1};
    class UF
    {
    public:
        UF(const vector<vector<int>> &grid)
        {
            int r = grid.size(), c = grid[0].size();
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        parent_.push_back(i * c + j);
                        size_.push_back(1);
                    }
                    else
                    {
                        parent_.push_back(-1);
                        size_.push_back(0);
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
            size_[rootj] += size_[rooti];
        }

        int size(int i) const
        {
            return size_[i];
        }

    private:
        vector<int> parent_;
        vector<int> size_;
    };

public:
    int largestIsland(vector<vector<int>> &grid)
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

        int res = 0;
        bool allOne = true;
        UF set(grid);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (i + 1 < r && grid[i + 1][j] == 1)
                    {
                        set.unite(i * c + j, (i + 1) * c + j);
                    }
                    if (j + 1 < c && grid[i][j + 1] == 1)
                    {
                        set.unite(i * c + j, i * c + j + 1);
                    }
                }
            }
        }

        unordered_set<int> used;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                used.clear();
                int cnt = 0;
                if (grid[i][j] == 0)
                {
                    allOne = false;
                    cnt = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
                        {
                            continue;
                        }
                        int root = set.find(x * c + y);

                        if (used.count(root))
                        {
                            continue;
                        }

                        cnt += set.size(root);
                        used.insert(root);
                    }
                }

                res = max(res, cnt);
            }
        }

        return allOne ? grid.size() * grid[0].size() : res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid{
        {0, 0},
        {0, 0},
    };
    cout << s.largestIsland(grid) << endl;
    return 0;
}
