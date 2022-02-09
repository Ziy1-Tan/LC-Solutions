// 按序打印，翻转结果
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
  vector<int> reversePrint(ListNode *head) {
    vector<int> res;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    while (dummy->next != NULL) {
      dummy = dummy->next;
      res.push_back(dummy->val);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};