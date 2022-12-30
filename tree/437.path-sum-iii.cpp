struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return cnt;
    }

private:
    int cnt = 0;
    void dfs(TreeNode *root, long sum)
    {
        if (!root)
            return;

        sum -= root->val;
        if (sum == 0)
            cnt++;

        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};

class Solution2
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        this->targetSum = targetSum;
        dfs(root, 0);
        return cnt;
    }

private:
    int cnt = 0;
    int targetSum;
    unordered_map<long, int> prefix{{0L, 1}};
    void dfs(TreeNode *root, long currSum)
    {
        if (!root)
            return;

        currSum += root->val;
        cnt += prefix[currSum - targetSum];
        prefix[currSum] += 1;

        dfs(root->left, currSum);
        dfs(root->right, currSum);

        prefix[currSum] -= 1;
    }
};

int main(int argc, char const *argv[])
{
    auto r = new TreeNode(8);
    r->left = new TreeNode(9);
    r->left->right = new TreeNode(-1);
    auto res = (new Solution2)->pathSum(r, 8);
    cout << res << endl;
    return 0;
}
