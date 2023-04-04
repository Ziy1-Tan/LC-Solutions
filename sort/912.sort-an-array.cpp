#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    sortArray(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void sortArray(vector<int>& nums, int begin, int end) {
    if (begin >= end) {
      return;
    }
    std::srand(std::time(nullptr));
    int p = std::rand() % (end - begin + 1) + begin;
    swap(nums[p], nums[begin]);
    int l = begin;
    int r = end;
    while (l < r) {
      while (l < r && nums[l] < nums[r]) r--;
      if (l < r) {
        swap(nums[l], nums[r]);
        l++;
      }
      while (l < r && nums[l] < nums[r]) l++;
      if (l < r) {
        swap(nums[l], nums[r]);
        r--;
      }
    }
    sortArray(nums, begin, l - 1);
    sortArray(nums, l + 1, end);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{5, 2, 3, 1};
  auto ans = (new Solution)->sortArray(nums);
  auto pv = [](const auto res) {
    for (auto&& i : res) cout << i << " ";
    cout << '\n';
  };
  pv(ans);
  return 0;
}
