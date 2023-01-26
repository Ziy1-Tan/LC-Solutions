#include <deque>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        return dfs(num, 0, 0, 0, 0);
    }

private:
    bool dfs(const string &num, int begin, int cnt, unsigned long long prev1, unsigned long long prev2)
    {
        if (begin >= num.size())
            return cnt > 2;

        unsigned long long curr = 0;
        for (int i = begin; i < num.size(); i++)
        {
            if (num[begin] == '0' && i > begin)
                return false;

            curr = curr * 10 + (num[i] - '0');
            if (cnt >= 2)
            {
                long sum = prev1 + prev2;
                if (curr > sum)
                    return false;
                if (curr < sum)
                    continue;
            }

            if (dfs(num, i + 1, cnt + 1, curr, prev1))
                return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution)->isAdditiveNumber("199100199");
    cout << res << endl;
    return 0;
}
