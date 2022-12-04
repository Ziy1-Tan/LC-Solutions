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
        while (list1 != nullptr || list2 != nullptr)
        {
            int val1 = list1 == nullptr ? INT32_MAX : list1->val;
            int val2 = list2 == nullptr ? INT32_MAX : list2->val;
            curr->next = val1 < val2 ? list1 : list2;
            curr = curr->next;
            if (val1 < val2)
            {
                list1 = list1 == nullptr ? nullptr : list1->next;
            }
            else
            {
                list2 = list2 == nullptr ? nullptr : list2->next;
            }
        }

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
    Solution2 s;
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
