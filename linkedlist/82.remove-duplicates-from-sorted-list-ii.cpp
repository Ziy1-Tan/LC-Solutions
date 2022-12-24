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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // head结点可能需要改动，增加一个dummy节点
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr = &dummy;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            if (curr->next->val == curr->next->next->val)
            {
                int x = curr->next->val;
                while (curr->next != nullptr && curr->next->val == x)
                {
                    curr->next = curr->next->next;
                }
            }
            else
            {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

class Solution2
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        if (head->val != head->next->val)
        {
            head->next = deleteDuplicates(head->next);
        }
        else
        {
            int x = head->val;
            while (head->next != nullptr && head->next->val == x)
            {
                head = head->next;
            }
            head = deleteDuplicates(head->next);
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{
    auto init_list = [](initializer_list<int> l) -> ListNode *
    {
        if (l.size() == 0)
            return nullptr;
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        for (const auto i : l)
        {
            if (head == nullptr)
            {
                head = new ListNode(i);
                curr = head;
            }
            else
            {
                curr->next = new ListNode(i);
                curr = curr->next;
            }
        }
        return head;
    };
    ListNode *head = init_list({1, 1, 1, 3, 4, 4, 4, 4, 5});
    Solution2 s;
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
    print_list(s.deleteDuplicates(head));
    return 0;
}
