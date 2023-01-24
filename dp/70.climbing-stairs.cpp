#include <iostream>
#include <unordered_map>
using namespace std;
// 超时
class Solution
{
public:
    unordered_map<int, int> map = {{1, 1}, {2, 2}};
    int climbStairs(int n)
    {
        if (map.count(n))
            return map[n];

        int curr = climbStairs(n - 1) + climbStairs(n - 2);
        map[n] = curr;
        return curr;
    }
};

class Solution2
{
public:
    int climbStairs(int n)
    {
        if (n < 3)
            return n;

        int dp[2] = {1, 2};
        for (int i = 0; i <= n; i++)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }

        return dp[1];
    }
};
