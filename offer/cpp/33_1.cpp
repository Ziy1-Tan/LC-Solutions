// 递归分治法，将后序遍历序列划分为左右子树
// 首先获取根结点值，在找到第一个大于根结点的值的位置，将遍历序列划分为左右子树遍历序列
// 时间复杂度 O(N^2)
// 每次遍历都需要减去一个根结点，一共遍历N次，树退化为链表时，每次递归都需要遍历整个数组
// 空间复杂度 O(N) 树退化为链表，递归深度为N
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool verifyPostorder(vector<int> &postorder) {
    int n = postorder.size();
    if (n <= 1)
      return true;

    int rootPos = n - 1;
    int rootVal = postorder[rootPos];

    int index = n - 1;
    for (int i = 0; i < n - 1; i++) {
      if (postorder[i] > rootVal) {
        index = i;
        break;
      }
    }

    return verfiy(postorder, 0, index - 1, rootVal, INT_MIN) &&
           verfiy(postorder, index, rootPos - 1, INT_MAX, rootVal);
  }

private:
  bool verfiy(const vector<int> &postorder, int l, int r, int upper,
              int lower) {
    if (l >= r)
      return true;

    int rootPos = r;
    int rootVal = postorder[rootPos];

    //检查是否越界
    for (int i = l; i <= r; i++) {
      if (postorder[i] < lower || postorder[i] > upper)
        return false;
    }

    //划分左右子树
    int index = rootPos;
    for (int i = l; i <= r - 1; i++) {
      if (postorder[i] > rootVal) {
        index = i;
        break;
      }
    }

    return verfiy(postorder, l, index - 1, rootVal, INT_MIN) &&
           verfiy(postorder, index, rootPos - 1, INT_MAX, rootVal);
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