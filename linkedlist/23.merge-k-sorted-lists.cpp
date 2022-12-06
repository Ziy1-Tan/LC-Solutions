struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        ListNode *res = lists.front();
        for (int i = 1; i < lists.size(); i++)
        {
            res = mergeTwoLists(res, lists[i]);
        }

        return res;
    }

private:
    // 可以改成迭代形式
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

class Solution2
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](const ListNode *list1, const ListNode *list2)
        {
            int val1 = list1 == nullptr ? INT32_MAX : list1->val;
            int val2 = list2 == nullptr ? INT32_MAX : list2->val;
            return val1 > val2;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp, lists);
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        while (!q.empty())
        {
            ListNode *tmp = q.top();
            q.pop();
            if (tmp == nullptr)
            {
                continue;
            }

            curr->next = tmp;
            curr = curr->next;
            tmp = tmp->next;
            q.push(tmp);
        }

        return dummy->next;
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
    vector<ListNode *> lists{init_list({1, 4, 5}), init_list({1, 3, 4}), init_list({2, 6})};
    Solution2 s;
    ListNode *res = s.mergeKLists(lists);
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
    print_list(res);
    return 0;
}
