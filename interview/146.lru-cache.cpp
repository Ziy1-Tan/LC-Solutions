#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std;

class LRUCache {
  struct ListNode {
    int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    ListNode() : key(-1), val(-1), next(nullptr), prev(nullptr) {}
  };

 public:
  LRUCache(int capacity) : capacity_(capacity), size_(0) {
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int key) {
    if (!cache_.count(key)) return -1;
    ListNode *node = cache_[key];
    removeNode(node);
    addToHead(node);
    return node->val;
  }

  void put(int key, int value) {
    if (!cache_.count(key)) {
      ListNode *node = new ListNode(key, value);
      cache_.emplace(key, node);

      addToHead(node);

      size_++;
      if (size_ > capacity_) {
        ListNode *removed = tail_->prev;
        removeNode(removed);

        cache_.erase(removed->key);
        delete removed;
        size_--;
      }
    } else {
      ListNode *node = cache_[key];
      node->val = value;

      removeNode(node);
      addToHead(node);
    }
  }

 private:
  void removeNode(ListNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addToHead(ListNode *node) {
    node->prev = head_;
    node->next = head_->next;
    head_->next->prev = node;
    head_->next = node;
  }

 private:
  unordered_map<int, ListNode *> cache_;
  ListNode *head_ = new ListNode, *tail_ = new ListNode;
  int capacity_;
  int size_;
};

int main(int argc, char const *argv[]) {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  cache.put(4, 4);
  cout << cache.get(1) << endl;
  cout << cache.get(3) << endl;
  cout << cache.get(4) << endl;

  return 0;
}
