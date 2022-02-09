// 利用排序数组的性质，不断缩小查找区间
// 当numbers[mid]=numbers[right]时，right--缩小查找区间
// 时间复杂度O(log2N)
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minArray(vector<int> &numbers) {
    if (numbers.size() == 0)
      return -1;
    int size = numbers.size();
    int left = 0, right = size - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (numbers[mid] < numbers[right])
        right = mid;
      else if (numbers[mid] > numbers[right])
        left = mid + 1;
      else
        right--;
    }
    return numbers[left];
  }
};