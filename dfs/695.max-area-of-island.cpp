#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &grid, int i, int k)
    {
        if (i < 0 || k < 0 || i >= grid.size() || k >= grid[0].size())
            return 0;

        if (grid[i][k] != 1)
        {
            return 0;
        }

        grid[i][k] = 2;
        return 1 +
               dfs(grid, i - 1, k) +
               dfs(grid, i + 1, k) +
               dfs(grid, i, k - 1) +
               dfs(grid, i, k + 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (grid[i][k] == 1)
                {
                    res = max(res, dfs(grid, i, k));
                }
            }
        }
        return res;
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
