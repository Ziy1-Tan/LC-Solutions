#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findRepeatDocument(vector<int>& documents) {
    int res = 0;
    for (int i = 0; i < documents.size(); i++) {
      while (documents[i] != i) {
        if (documents[documents[i]] == documents[i]) {
          return documents[i];
        }
        swap(documents[i], documents[documents[i]]);
      }
    }
    return 0;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{2, 5, 3, 0, 5, 0};
  cout << (new Solution)->findRepeatDocument(nums) << endl;
  return 0;
}
