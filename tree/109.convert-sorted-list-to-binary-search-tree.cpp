struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
#include <tuple>
using namespace std;
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return nullptr;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode *fast = head, *slow = head, *prev = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        prev->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(0);
    Solution s;
    auto r = s.sortedListToBST(head);
    return 0;
}
