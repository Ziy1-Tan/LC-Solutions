// 迭代写法，正向遍历链表，使用三个指针pre、cur和tmp分别保存前向节点
// 当前遍历到的节点和cur的后向节点
// 时间复杂度O(N)
// 空间复杂度O(1) 指针大小为常数
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr, *cur = head, *tmp = nullptr;

    while (cur != nullptr) {
      // 暂存cur的next节点
      tmp = cur->next;
      // 翻转
      cur->next = pre;
      // 更新，进入下一次迭代
      pre = cur;
      cur = tmp;
    }

    return pre;
  }
};

int main(int argc, const char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);

  auto rev = (new Solution())->reverseList(head);
  while (rev) {
    cout << rev->val << endl;
    rev = rev->next;
  }
  return 0;
}