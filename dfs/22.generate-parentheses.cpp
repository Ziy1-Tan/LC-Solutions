#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        dfs("", 0, 0, n);
        return res;
    }

private:
    vector<string> res;
    // 左括号数不大于右括号
    void dfs(string path, int left, int right, int n)
    {
        if (left > n || right > left)
            return;

        if (path.size() == 2 * n)
        {
            res.push_back(path);
            return;
        }

        dfs(path + '(', left + 1, right, n);
        dfs(path + ')', left, right + 1, n);
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution)->generateParenthesis(3);
    auto pv = [](const vector<string> res)
    {
        for (auto &&i : res)
        {
            cout << i << " ";
        }
        cout << '\n';
    };
    pv(res);
    return 0;
}
