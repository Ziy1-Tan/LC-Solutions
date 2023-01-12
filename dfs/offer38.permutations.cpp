#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        sort(s.begin(), s.end());
        used.assign(s.size(), 0);
        dfs(s, "");
        return res;
    }

private:
    vector<string> res;
    vector<int> used;
    void dfs(const string &s, string path)
    {
        if (path.size() == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (used[i])
                continue;

            if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
                continue;
            used[i] = 1;
            dfs(s, path + s[i]);
            used[i] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution)->permutation("aabc");
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << " ";
        cout << '\n';
    };
    pv(res);
    return 0;
}
