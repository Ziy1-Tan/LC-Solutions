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
    queue<TreeNode *> q;
    q.push(root);
    string ans{"["};
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (node) {
        ans += to_string(node->val);
        q.push(node->left);
        q.push(node->right);
      } else {
        ans += "null";
      }
      ans += ',';
    }

    ans.pop_back();
    return ans + "]";
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    data.pop_back();
    data = data.substr(1);
    vector<string> nums;
    string val;
    stringstream ss(data);
    while (getline(ss, val, ',')) {
      nums.push_back(val);
    }
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(nums[0]));
    q.push(root);
    int i = 1;
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (i >= nums.size()) continue;
      if (nums[i] != "null") {
        node->left = new TreeNode(stoi(nums[i]));
        q.push(node->left);
      }
      i++;
      if (nums[i] != "null") {
        node->right = new TreeNode(stoi(nums[i]));
        q.push(node->right);
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
