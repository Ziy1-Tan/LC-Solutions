// 滑动窗口，用i、j分别表示滑动窗口的左右边界，[i,j)内的代表当前的序列
// 左边界右移时，窗口内的和减小，右边界有移时，窗口内的和增大
// 滑动条件：sum[i,j)<target,说明还不够大，j++;sum[i,j)>target,说明太大了，i++
// sum[i,j)==target时，找到一个解，i++,寻找以i+1为起点的连续序列
// 时间复杂度O(N) 左右边界只会向右移，所以复杂度为线性的
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> findContinuousSequence(int target) {
    int l = 1, r = 1; // 分别代表窗口左右边界
    int sum = 0;      // 代表窗口内所有数的和
    vector<vector<int>> res;
    // 当l>target/2时，
    // 序列和为 target/2 + (target/2+1) = target+1 必大于 target
    while (l <= target / 2) {
      if (sum < target) {
        sum += r;
        r++;
      } else if (sum > target) {
        sum -= l;
        l++;
      } else {
        vector<int> tmp;
        for (int i = l; i < r; i++) {
          tmp.push_back(i);
        }
        res.emplace_back(tmp);
        // 从i+1开始寻找起来
        sum -= l;
        l++;
      }
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().findContinuousSequence(15);
  for (const auto &arr : res) {
    for (const auto elem : arr) {
      cout << " " << elem;
    }
    cout << '\n';
  }
  return 0;
}