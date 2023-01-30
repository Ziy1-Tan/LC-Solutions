#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
private:
    unordered_map<int, int> island_size;
    constexpr static int dx[] = {-1, 1, 0, 0};
    constexpr static int dy[] = {0, 0, -1, 1};
    void dfs(vector<vector<int>> &grid, int i, int k, int mask)
    {
        if (i < 0 || k < 0 || i >= grid.size() || k >= grid[0].size())
        {
            return;
        }

        if (grid[i][k] != 1)
        {
            return;
        }

        grid[i][k] = mask;
        island_size[mask]++;
        dfs(grid, i - 1, k, mask);
        dfs(grid, i + 1, k, mask);
        dfs(grid, i, k - 1, mask);
        dfs(grid, i, k + 1, mask);
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int res = 0;
        bool allOne = true;
        int mask = 2;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (grid[i][k] == 1)
                {
                    dfs(grid, i, k, mask);
                    mask++;
                }
            }
        }

        // 遍历所有0格子，连接相邻岛屿
        unordered_set<int> used;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int cnt = 1;
                used.clear();
                if (grid[i][j] == 0)
                {
                    allOne = false;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
                        {
                            continue;
                        }

                        int mask = grid[x][y];
                        if (used.count(mask))
                        {
                            continue;
                        }

                        cnt += island_size[mask];
                        used.insert(mask);
                    }
                }
                res = max(res, cnt);
            }
        }

        return allOne ? grid.size() * grid[0].size() : res;
    }
};

class Solution2
{
private:
    int dfs(vector<vector<int>> &grid, int i, int j, int mask)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return 0;
        }

        if (grid[i][j] == 0 || grid[i][j] == mask)
        {
            return 0;
        }

        grid[i][j] = mask;
        int cnt = 1 +
                  dfs(grid, i - 1, j, mask) +
                  dfs(grid, i + 1, j, mask) +
                  dfs(grid, i, j - 1, mask) +
                  dfs(grid, i, j + 1, mask);
        return cnt;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int res = 0;
        bool allOne = true;
        int mask = 2;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    allOne = false;
                    grid[i][j] = 1;
                    // 可以优化，把每个岛屿大小存起来
                    res = max(res, dfs(grid, i, j, mask));
                    grid[i][j] = 0;
                    mask++;
                }
            }
        }

        return allOne ? grid.size() * grid[0].size() : res;
    }
};

int main(int argc, char const *argv[])
{
    Solution2 s;
    vector<vector<int>> grid{
        {0, 1},
        {1, 0},
        {0, 1},
    };
    cout << s.largestIsland(grid) << endl;
    return 0;
}
