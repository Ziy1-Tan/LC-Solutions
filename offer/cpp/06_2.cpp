// 到达递归深度函数返回后，添加到数组中
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> res;
  vector<int> reversePrint(ListNode *head) {
    recur(head);
    return res;
  }

  void recur(ListNode *head) {
    if (head == nullptr)
      return;
    recur(head->next);
    res.push_back(head->val);
  }
};