/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <array>
#include <string>
using namespace std;

class Trie {
 public:
  Trie() : isEnd(false) { std::fill_n(next.begin(), 26, nullptr); }

  void insert(string word) {
    Trie* node = this;
    for (auto&& c : word) {
      if (!node->next[c - 'a']) {
        node->next[c - 'a'] = new Trie();
      }
      node = node->next[c - 'a'];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie* node = this;
    for (auto& c : word) {
      node = node->next[c - 'a'];
      if (!node) {
        return false;
      }
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    Trie* node = this;
    for (auto& c : prefix) {
      node = node->next[c - 'a'];
      if (!node) {
        return false;
      }
    }
    return true;
  }

  bool isEnd;
  array<Trie*, 26> next;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
