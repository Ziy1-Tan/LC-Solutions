#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        dfs(s, 0);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<string> path;
    void dfs(const string &s, int begin)
    {
        if (begin == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = begin; i < s.size(); i++)
        {
            string tmp = s.substr(begin, i - begin + 1);
            if (!isPalindrome(tmp))
                continue;
            path.push_back(tmp);
            dfs(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &str)
    {
        int l = 0, r = str.size() - 1;
        while (l <= r)
        {
            if (str[l] != str[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution)->partition("aab");
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << " ";
        cout << '\n';
    };
    for (auto &&i : res)
    {
        pv(i);
    }

    return 0;
}
