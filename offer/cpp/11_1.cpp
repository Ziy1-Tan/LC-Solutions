#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minArray(vector<int> &numbers) {
    if (numbers.size() == 0)
      return -1;
    int size = numbers.size();
    int min = numbers[0];
    for (int i = 0; i < size - 1; i++) {
      if (numbers[i] > numbers[i + 1])
        min = numbers[i + 1];
    }
    return min;
  }
};