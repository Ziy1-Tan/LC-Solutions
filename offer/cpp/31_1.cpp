// 利用stack模拟压栈序列，判断最后是否能完全模拟
// 时间复杂度O(N) 最多一次入栈一次处栈 2N
// 空间复杂度O(N)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    int i = 0;
    // pushed依次压栈
    for (auto num : pushed) {
      s.push(num);
      // 若栈顶等于弹出序列元素popped[i]
      while (!s.empty() && s.top() == popped[i]) {
        s.pop();
        i++;
      }
    }
    return s.empty();
  }
};

int main(int argc, const char *argv[]) {
  vector<int> pushed{1, 2, 3, 4, 5};
  vector<int> popped{4, 5, 3, 1, 2};
  cout << boolalpha << (new Solution())->validateStackSequences(pushed, popped)
       << endl;
  return 0;
}