struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> set;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (set.count(curr))
            {
                return true;
            }
            set.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};

class Solution2
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
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
    ListNode *head = init_list({1, 2, 3, 4});
    head->next->next->next = head;
    Solution s;
    cout << s.hasCycle(head) << endl;
    return 0;
}
