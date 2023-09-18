struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) {
      return "";
    }
    string res("[");
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p) {
        res += to_string(p->val);
        q.push(p->left);
        q.push(p->right);
      } else {
        res += "null";
      }
      res += ",";
    }
    res.pop_back();
    return res + "]";
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    data = data.substr(1);
    data.pop_back();
    queue<TreeNode *> q;
    vector<string> nums;
    string val;
    stringstream ss(data);
    while (getline(ss, val, ',')) {
      nums.push_back(val);
    }

    auto root = new TreeNode(stoi(nums[0]));
    q.push(root);
    int i = 1;
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (i >= nums.size()) break;
      if (nums[i] != "null") {
        p->left = new TreeNode(stoi(nums[i]));
        q.push(p->left);
      }
      i++;
      if (nums[i] != "null") {
        p->right = new TreeNode(stoi(nums[i]));
        q.push(p->right);
      }
      i++;
    }
    return root;
  }
};

int main(int argc, char const *argv[]) {
  string str{"[-1,0,1]"};
  Codec codec;
  cout << codec.serialize(codec.deserialize(str)) << endl;
  return 0;
}
