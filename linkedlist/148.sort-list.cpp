struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
using namespace std;
// 超时
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = head;
        while (slow != nullptr)
        {
            ListNode *fast = slow->next, *min = slow->next;
            while (fast != nullptr)
            {
                if (fast->val <= min->val)
                {
                    min = fast;
                }
                fast = fast->next;
            }
            if (min != nullptr && min->val <= slow->val)
            {
                int tmp = min->val;
                min->val = slow->val;
                slow->val = tmp;
            }
            slow = slow->next;
        }

        return dummy->next;
    }
};

class Solution2
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = head;
        int length = 0;
        while (p != nullptr)
        {
            length++;
            p = p->next;
        }

        for (int step = 1; step < length; step *= 2)
        {
            ListNode *curr = dummy.next, *tail = &dummy;
            while (curr != nullptr)
            {
                // 找到两段相邻的链表并合并
                ListNode *list1 = curr;
                ListNode *list2 = split(curr, step);
                curr = split(list2, step);

                tail->next = merge(list1, list2);
                while (tail->next != nullptr)
                {
                    tail = tail->next;
                }
            }
        }

        return dummy.next;
    }

private:
    // 切割为head为头结点的长度为n的链表，返回切割后的下一个节点
    ListNode *split(ListNode *head, int n)
    {
        ListNode *p = head;
        while (--n > 0 && p != nullptr)
        {
            p = p->next;
        }

        if (p == nullptr)
        {
            return p;
        }

        ListNode *next = p->next;
        p->next = nullptr;
        return next;
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
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

        return dummy.next;
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
    ListNode *head = init_list({4, 2, 1, 3});
    ListNode *sorted = s.sortList(head);
    print_list(sorted);
    return 0;
}
