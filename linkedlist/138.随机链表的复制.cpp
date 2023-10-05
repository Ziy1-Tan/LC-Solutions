/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return head;
    }

    unordered_map<Node*, Node*> map;
    Node* p = head;
    Node *dummy = new Node(-1), *q = dummy;
    while (p) {
      q->next = new Node(p->val);
      map.insert({p, q->next});
      q = q->next;
      p = p->next;
    }

    p = head, q = dummy->next;
    while (p) {
      if (p->random) {
        q->random = map[p->random];
      }
      p = p->next;
      q = q->next;
    }

    return dummy->next;
  }
};

class Solution2 {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return head;
    }
    Node* p = head;
    // 复制到原节点后
    while (p) {
      Node* q = new Node(p->val);
      q->next = p->next;
      p->next = q;
      p = q->next;
    }
    // 复制random指针
    p = head;
    while (p) {
      if (p->random) {
        p->next->random = p->random->next;
      }
      p = p->next->next;
    }
    // 拆分奇偶位置
    Node* res = head->next;
    p = head;
    while (p) {
      Node* newNode = p->next;
      if (newNode) {
        p->next = newNode->next;
      }
      p = newNode;
    }
    return res;
  }
};
// @lc code=end
