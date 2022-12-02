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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == 1)
        {
            return reverseN(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

private:
    ListNode *sucessor = nullptr;
    // 反转链表的前n个节点
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1)
        {
            sucessor = head->next;
            return head;
        }

        ListNode *rev = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = sucessor;
        return rev;
    }
};

class Solution2
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        // prev定位到left的前一个节点，curr定位到left节点
        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
            curr = curr->next;
        }

        // 每次将curr后的元素插入到prev之后
        for (int i = 0; i < right - left; i++)
        {
            ListNode *removed = curr->next;
            curr->next = removed->next;

            removed->next = prev->next;
            prev->next = removed;
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
    ListNode *node = init_list({1, 2, 3, 4, 5});
    Solution2 s;
    ListNode *rev = s.reverseBetween(node, 2, 4);
    print_list(rev);
    return 0;
}
