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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *rev = swapPairs(head->next->next);
        ListNode *next = head->next;

        head->next->next = head;
        head->next = rev;
        return next;
    }
};

class Solution2
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy, *end = dummy;
        while (end->next != nullptr)
        {
            if (end->next->next != nullptr)
            {
                end = end->next->next;
            }
            else
            {
                break;
            }

            ListNode *start = prev->next, *next = end->next;

            end->next = start;
            prev->next = end;
            start->next = next;

            prev = start;
            end = start;
        }

        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    auto print_list = [](ListNode *node) -> void
    {
        auto curr = node;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << "\n";
    };
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution2 s;
    ListNode *swp = s.swapPairs(head);
    print_list(swp);

    return 0;
}
