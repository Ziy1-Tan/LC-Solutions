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
    return verify(postorder, 0, postorder.size() - 1);
  }

private:
  bool verify(vector<int> &postorder, int l, int r) {
    // 只有一个元素，一定为后续
    if (l >= r) {
      return true;
    }
    int i = l;
    // 寻找右子树序列第一个元素
    while (postorder[i] < postorder[r])
      i++;
    int index = i;
    // 检查右子树序列是否合法
    while (postorder[i] > postorder[r])
      i++;

    return i == r && verify(postorder, l, index - 1) &&
           verify(postorder, index, r - 1);
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