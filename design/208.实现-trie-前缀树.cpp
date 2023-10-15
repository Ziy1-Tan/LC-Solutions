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
  Trie() : isEnd(false) { fill_n(children.begin(), 26, nullptr); }

  void insert(string word) {
    Trie* node = this;
    for (auto&& c : word) {
      if (!node->children[c - 'a']) {
        node->children[c - 'a'] = new Trie();
      }
      node = node->children[c - 'a'];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie* node = this;
    for (auto& c : word) {
      if (!node->children[c - 'a']) {
        return false;
      }
      node = node->children[c - 'a'];
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    Trie* node = this;
    for (auto& c : prefix) {
      if (!node->children[c - 'a']) {
        return false;
      }
      node = node->children[c - 'a'];
    }
    return true;
  }

 private:
  bool isEnd;
  array<Trie*, 26> children;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
