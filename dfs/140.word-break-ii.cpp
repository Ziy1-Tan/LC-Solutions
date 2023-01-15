#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        this->wordDict = wordDict;
        dfs(s, 0);
        return res;
    }

private:
    vector<string> wordDict;
    vector<string> res;
    vector<string> path;
    void dfs(const string &s, int begin)
    {
        if (begin == s.size())
        {
            string tmp;
            for (auto &&i : path)
                tmp += i + " ";
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }

        for (int i = begin; i < s.size(); i++)
        {
            const string tmp = s.substr(begin, i - begin + 1);
            if (find(wordDict.begin(), wordDict.end(), tmp) == wordDict.end())
                continue;

            path.push_back(tmp);
            dfs(s, i + 1);
            path.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    string s{"catsanddog"};
    vector<string> dict{"cat", "cats", "and", "sand", "dog"};
    auto res = (new Solution)->wordBreak(s, dict);
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << '\n';
    };
    pv(res);
    return 0;
}
