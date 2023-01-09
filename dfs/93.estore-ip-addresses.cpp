#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
            return {};

        for (auto &&i : s)
            if (!isdigit(i))
                return {};

        dfs(s);
        return res;
    }

private:
    vector<string> res;
    vector<string> path;
    void dfs(string s)
    {
        if (path.size() == 4)
        {
            string tmp = "";
            for (auto &&i : path)
                tmp += i + '.';
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }

        if (path.size() == 3)
        {
            if (isValid(s))
            {
                path.push_back(s);
                dfs("");
                path.pop_back();
            }
            return;
        }

        for (int i = 1; i <= 3; i++)
        {
            string tmp = s.substr(0, i);
            if (!isValid(tmp))
                continue;
            path.push_back(tmp);
            dfs(i < s.size() ? s.substr(i) : "");
            path.pop_back();
        }
    }

    bool isValid(const string &tmp)
    {
        if (tmp.empty() || tmp.size() < 0 || tmp.size() > 3)
            return false;

        if (tmp.size() != 1 && tmp[0] == '0')
            return false;

        int val = stoi(tmp);
        if (val < 0 || val > 255)
            return false;

        return true;
    }
};

class Solution2
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
            return {};

        for (auto &&i : s)
            if (!isdigit(i))
                return {};

        dfs(s, 0, 4);
        return res;
    }

private:
    vector<string> res;
    vector<string> path;
    void dfs(const string &s, int begin, int rest)
    {
        if (begin == s.size())
        {
            if (rest == 0)
            {
                string tmp;
                for (auto &&c : path)
                    tmp += c + '.';
                tmp.pop_back();
                res.push_back(tmp);
            }
            return;
        }

        for (int i = 1; i <= 3; i++)
        {
            if (begin >= s.size())
                break;

            if (!isValid(s, begin, i))
                continue;

            path.push_back(s.substr(begin, i));
            dfs(s, begin + i, rest - 1);
            path.pop_back();
        }
    }

    bool isValid(const string &s, int begin, int n)
    {
        const auto &tmp = s.substr(begin, n);
        if (tmp.size() < 0 || tmp.size() > 3)
            return false;

        if (tmp.size() > 1 && tmp[0] == '0')
            return false;

        int val = stoi(tmp);
        if (val < 0 || val > 255)
            return false;

        return true;
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution2)->restoreIpAddresses("101023");
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i;
        cout << '\n';
    };

    for (auto &&i : res)
        pv(i);

    return 0;
}
