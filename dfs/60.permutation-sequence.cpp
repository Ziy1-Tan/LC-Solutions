#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        used.assign(n + 1, 0);
        dfs(n, k);
        return res;
    }

private:
    vector<int> used;
    string res;
    string path;
    int curr = 0;
    void dfs(int n, int k)
    {
        if (path.size() == n)
        {
            if (++curr == k)
                res = path;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (used[i])
                continue;

            used[i] = 1;
            path.push_back((char)(i + '0'));
            dfs(n, k);
            path.pop_back();
            used[i] = 0;
        }
    }
};

class Solution2
{
public:
    string getPermutation(int n, int k)
    {
        used.assign(n + 1, 0);
        dfs(n, k, 0);
        return res;
    }

private:
    static constexpr int factorial[] = {
        1,
        1,
        2,
        6,
        24,
        120,
        720,
        5040,
        40320,
        40320 * 9,
    };

    vector<int> used;
    string res;
    void dfs(int n, int k, int depth)
    {
        if (depth == n)
            return;

        int cnt = factorial[n - 1 - depth];
        for (int i = 1; i <= n; i++)
        {
            if (used[i])
                continue;

            // 产生全排列的未到达k个
            if (k > cnt)
            {
                k -= cnt;
                continue;
            }

            used[i] = 1;
            res += (char)('0' + i);
            dfs(n, k, depth + 1);
            // 不需要回溯，因为没有枚举前k-1个全排列
            return;
        }
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution2)->getPermutation(3, 3);
    cout << res << endl;
    return 0;
}
