// hash表+双向链表实现
// hash负责O(1)检索，双向链表负责维护最近访问的节点序列
// get操作时，若key不存在返回-1,存在则将key对应的node移到链表头部
// put操作时，若key存在，根据key定位到node,修改node值后移动到链表头部
// 若key不存在，生成node插入到链表头部，若超出cache capacity，则删除链表尾部节点
// 时间复杂度O(1)
// 空间复杂度O(N) 最多使用capacity+1的空间
#include <iostream>
#include <unordered_map>
using namespace std;

struct DLinkedNode {
  int key;
  int value;
  DLinkedNode *prev;
  DLinkedNode *next;
  DLinkedNode(int key_, int value_, DLinkedNode *prev_ = nullptr,
              DLinkedNode *next_ = nullptr)
      : key{key_}, value(value_), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
    head = new DLinkedNode(-1, -1);
    tail = new DLinkedNode(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    // 不存在返回-1
    if (!cache.count(key)) {
      return -1;
    }
    // 存在则返回，对应node移动到头部
    DLinkedNode *node = cache.at(key);
    moveToHead(node);

    return node->value;
  }

  void put(int key, int value) {
    // key存在则更新value，移动到头部
    if (cache.count(key)) {
      DLinkedNode *node = cache.at(key);
      node->value = value;
      moveToHead(node);
      return;
    }
    // key不存在新增节点移动到头部，判断是否超出capacity
    DLinkedNode *node = new DLinkedNode(key, value);
    addToHead(node);
    cache[key] = node;
    size++;
    // 删除尾节点
    if (size > capacity) {
      DLinkedNode *removed = removeTail();
      cache.erase(removed->key);
      delete removed;
      --size;
    }
  }

private:
  unordered_map<int, DLinkedNode *> cache;
  DLinkedNode *head;
  DLinkedNode *tail;
  int capacity;
  int size;

  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addToHead(DLinkedNode *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

  void moveToHead(DLinkedNode *node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkedNode *removeTail() {
    DLinkedNode *removed = tail->prev;
    removeNode(removed);
    return removed;
  }
};

int main(int argc, const char *argv[]) {
  LRUCache cache(2);
  cache.put(2, 1);
  cache.put(1, 1);
  cache.put(2, 3);
  cache.put(4, 1);
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;

  return 0;
}