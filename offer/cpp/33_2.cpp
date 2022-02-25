// 单调栈法，采用栈+（root->right->left）方式遍历序列
// 当栈为空和栈顶元素比当前元素小时，说明遍历到右子树，压入栈
// 当栈顶元素比当前元素大时，移除栈元素直到栈顶元素比当前元素小
// 重复上述过程直到遍历完整个序列
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  bool verifyPostorder(vector<int> &postorder) {
    int n = postorder.size();
    if (n <= 1)
      return true;

    stack<int> stack;
    int parent = INT_MAX;

    for (int i = n - 1; i >= 0; i--) {
      int cur = postorder[i];

      // 如果碰到左子树节点，则找到该左子树节点的根结点
      while (!stack.empty() && stack.top() > cur) {
        //如果栈中元素仍比当前节点大，则说明还在右子树
        parent = stack.top();
        stack.pop();
      }

      //栈为空或没有比cur大的节点，说明该节点无限大，不符合BST定义
      if (cur > parent)
        return false;

      stack.push(cur);
    }

    return true;
  }
};

int main(int argc, const char *argv[]) {
  //   vector<int> nums{1, 6, 3, 2, 5};
  vector<int> nums{4, 8, 6, 12, 16, 14, 10};
  Solution s;
  auto res = s.verifyPostorder(nums);

  cout << boolalpha << res << endl;

  return 0;
}