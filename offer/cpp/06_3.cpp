// 利用栈先进后出的性质，顺序遍历加入栈中，依次处栈到数组中
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stack>
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
    stack<int> s;
    ListNode *curr = head;
    while (curr != nullptr) {
      s.push(curr->val);
      curr = curr->next;
    }

    while (!s.empty()) {
      res.push_back(s.top());
      s.pop();
    }
    return res;
  }
};