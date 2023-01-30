#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
            for (int j = 1; j < i; j++)
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    cout << (new Solution)->integerBreak(10) << endl;
    return 0;
}
