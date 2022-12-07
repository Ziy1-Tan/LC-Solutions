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
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head, *slow = head;
        while (k-- != 0)
        {
            fast = fast->next;
        }

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
