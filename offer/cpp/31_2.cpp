// 一个合法的push和pop序列对于同一个二叉树的前序和中序遍历
// 所以本题对应于根据前序和中序遍历序列重建二叉树
//
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    function<bool(int, int, int)> valid = [&](int root, int l, int r) {
      if (l > r)
        return true;
      //根结点值
      int rVal = pushed[root];
      int pos = -1;
      // 在中序遍历序列寻找根结点位置
      for (int i = l; i <= r; i++) {
        if (rVal == popped[i]) {
          pos = i;
          break;
        }
      }
      // 位置非法则弹出序列不合法
      if (pos == -1)
        return false;
      return valid(root + 1, l, pos - 1) &&
             valid(root + pos - l + 1, pos + 1, r);
    };
    return valid(0, 0, popped.size() - 1);
  }
};

int main(int argc, const char *argv[]) {
  vector<int> pushed{1, 2, 3, 4, 5};
  vector<int> popped{4, 5, 3, 2, 1};
  cout << boolalpha << (new Solution())->validateStackSequences(pushed, popped)
       << endl;
  return 0;
}