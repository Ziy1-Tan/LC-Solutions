#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1);

        for (int i = 0; i < stones.size(); i++)
            for (int j = target; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);

        return sum - dp[target] - dp[target];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{2, 7, 4, 1, 8, 1};
    cout << (new Solution)->lastStoneWeightII(v) << endl;
    return 0;
}
