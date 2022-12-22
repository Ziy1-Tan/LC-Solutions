struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = (list1 == nullptr) ? list2 : list1;

        return dummy->next;
    }
};

class Solution2
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(5);
    Solution s;
    ListNode *ret = s.mergeTwoLists(head, head1);
    [](ListNode *node) -> void
    {
        auto curr = node;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    }(ret);
    return 0;
}
