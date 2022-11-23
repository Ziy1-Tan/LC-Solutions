#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {

        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (grid[i][k] == 1)
                {
                    return dfs(grid, i, k);
                }
            }
        }
        return 0;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int k)
    {
        if (i < 0 || k < 0 || i >= grid.size() || k >= grid[0].size())
        {
            return 1;
        }

        if (grid[i][k] == 0)
        {
            return 1;
        }

        if (grid[i][k] == 2)
        {
            return 0;
        }

        grid[i][k] = 2;
        return dfs(grid, i - 1, k) +
               dfs(grid, i + 1, k) +
               dfs(grid, i, k - 1) +
               dfs(grid, i, k + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid{
        {1, 1},
        {1, 1},
    };
    cout << s.islandPerimeter(grid) << endl;

    return 0;
}
