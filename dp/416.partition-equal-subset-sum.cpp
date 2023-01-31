#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        vector<int> dp(sum + 1);

        for (int i = 0; i < nums.size(); i++)
            for (int j = sum; j >= nums[i]; j--)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);

        return dp[sum] == sum;
    }
};

class Solution2
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, 0));

        for (int i = nums[0]; i <= sum; i++)
            dp[0][i] = nums[0];

        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j <= sum; j++)
            {
                if (j < nums[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[0]] + nums[0]);
            }

        return dp[nums.size() - 1][sum] == sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 2};
    cout << boolalpha;
    cout << (new Solution2)->canPartition(nums) << endl;
    return 0;
}
