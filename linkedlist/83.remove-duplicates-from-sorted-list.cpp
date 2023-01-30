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
        if (!head || !head->next)
            return head;

        head->next = deleteDuplicates(head->next);
        if (head->next && head->val == head->next->val)
        {
            auto removed = head->next;
            head->next = removed->next;
            delete removed;
        }
        return head;
    }
};

class Solution2
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
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
    ListNode *head = init_list({1, 1, 2, 3, 3});
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
    Solution s;
    print_list(s.deleteDuplicates(head));
    return 0;
}
