#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};

class Solution2
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;

        int dp[2] = {0, 1};
        for (int i = 2; i <= n; i++)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main(int argc, char const *argv[])
{
    cout << (new Solution2)->fib(30) << endl;
    return 0;
}
