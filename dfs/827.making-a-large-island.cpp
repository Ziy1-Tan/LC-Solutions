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
        unordered_set<int> used_islands;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid[0].size(); k++)
            {
                int cnt = 1;
                used_islands.clear();
                if (grid[i][k] == 0)
                {
                    allOne = false;
                    for (int l = 0; l < 4; l++)
                    {
                        int x = i + dx[l];
                        int y = k + dy[l];
                        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
                        {
                            continue;
                        }

                        if (used_islands.count(grid[x][y]))
                        {
                            continue;
                        }

                        cnt += island_size[grid[x][y]];
                        used_islands.insert(grid[x][y]);
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
    int dfs(vector<vector<int>> &grid, int i, int k, int mask)
    {
        if (i < 0 || k < 0 || i >= grid.size() || k >= grid[0].size())
        {
            return 0;
        }

        if (grid[i][k] == 0 || grid[i][k] == mask)
        {
            return 0;
        }

        grid[i][k] = mask;
        int cnt = 1 +
                  dfs(grid, i - 1, k, mask) +
                  dfs(grid, i + 1, k, mask) +
                  dfs(grid, i, k - 1, mask) +
                  dfs(grid, i, k + 1, mask);
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
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (grid[i][k] == 0)
                {
                    allOne = false;
                    grid[i][k] = 1;
                    // 可以优化，把每个岛屿大小存起来
                    res = max(res, dfs(grid, i, k, mask));
                    grid[i][k] = 0;
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
