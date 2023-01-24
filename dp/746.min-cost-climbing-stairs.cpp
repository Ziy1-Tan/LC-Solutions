#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp[2] = {0, 0};
        for (int i = 2; i <= cost.size(); i++)
        {
            int sum = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> cost = {10, 15, 20};
    cout << (new Solution)->minCostClimbingStairs(cost) << endl;
    return 0;
}
