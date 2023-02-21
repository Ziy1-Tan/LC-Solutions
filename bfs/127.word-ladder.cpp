#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<int> used(wordList.size());
        queue<string> q;
        q.push(beginWord);
        int cnt = 1;
        while (!q.empty())
        {
            cnt++;
            int size = q.size();
            while (size-- > 0)
            {
                string str = q.front();
                q.pop();
                for (int i = 0; i < wordList.size(); i++)
                {
                    if (used[i])
                        continue;

                    if (!isAlike(str, wordList[i]))
                        continue;

                    if (wordList[i] == endWord)
                        return cnt;

                    used[i] = 1;
                    q.push(wordList[i]);
                }
            }
        }
        return 0;
    }

private:
    bool isAlike(const string &s1, const string &s2)
    {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                cnt++;
            if (cnt > 1)
                break;
        }
        return cnt == 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    auto res = (new Solution)->ladderLength("hit", "cog", words);
    cout << res << endl;
    return 0;
}
