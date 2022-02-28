// 利用快排性质，经过一次快排后，左部分都比基准元素小，右半部分比基准元素大
// 判断每次快排后基准元素的位置，基准元素比k大，则k个小数在左半部分，反之在右半部分，若基准元素与k相等，说明左半部分正好k个小数，则返回左半部分数组
// 时间复杂度 O(N) 每次递归范围N N/2 N/4 求和得2N-1
// 空间复杂度 O(logN) 平均递归深度为logN
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (k >= arr.size())
      return arr;
    return quickSort(arr, k, 0, arr.size() - 1);
  }

  vector<int> quickSort(vector<int> &arr, int k, int l, int r) {
    int i = l, j = r;
    // 首先进行一次快速排序
    while (i < j) {
      // 第一个比基准元素小的(顺序不能换！)
      while (i < j && arr[j] >= arr[l])
        j--;
      // 第一个比基准大的
      while (i < j && arr[i] <= arr[l])
        i++;

      swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);
    // 判断k和i的大小，减少搜索范围
    if (i < k)
      return quickSort(arr, k, i + 1, r);
    else if (i > k)
      return quickSort(arr, k, l, i - 1);
    vector<int> res(k);
    res.assign(arr.begin(), arr.begin() + k);
    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> arr{0, 1, 2, 1};
  auto res = (new Solution())->getLeastNumbers(arr, 1);
  for (auto e : res) {
    cout << e << endl;
  }
  return 0;
}