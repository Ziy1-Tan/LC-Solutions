#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.empty())
            dfs(digits, 0, "");
        return res;
    }

private:
    vector<string> letters{"", "", "abc", "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void dfs(const string &digits, int i, string path)
    {
        if (i >= digits.size())
        {
            res.push_back(path);
            return;
        }

        const string &chars = letters[digits[i] - '0'];
        for (auto &&c : chars)
            dfs(digits, i + 1, path + c);
    }
};

int main(int argc, char const *argv[])
{
    auto s = "29";
    auto res = (new Solution)->letterCombinations(s);
    auto pv = [](const vector<string> res)
    {
        for (auto &&i : res)
            cout << i << " ";
        cout << '\n';
    };
    pv(res);
    return 0;
}
