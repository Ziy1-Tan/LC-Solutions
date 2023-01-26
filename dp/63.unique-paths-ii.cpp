#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++)
            dp[0][i] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }

        return dp[m - 1][n - 1];
    }
};

class Solution2
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = obstacleGrid[0][0] ? 0 : 1;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j])
                    dp[j] = 0;
                else if (j > 0 && obstacleGrid[i][j] == 0)
                    dp[j] = dp[j] + dp[j - 1];
            }

        return dp[n - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> obstacleGrid = {
        {0, 0},
        {1, 0},
    };
    cout << (new Solution2)->uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
