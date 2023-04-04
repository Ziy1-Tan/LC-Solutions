#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int i = 0;
    for (auto&& elem : pushed) {
      st.push(elem);
      while (!st.empty() && st.top() == popped[i]) {
        st.pop();
        i++;
      }
    }
    return st.empty() && i == popped.size();
  }
};

int main(int argc, char const* argv[]) {
  vector<int> pushed{1, 2, 3};
  vector<int> popped{3, 1, 2};
  cout << boolalpha;
  cout << (new Solution)->validateStackSequences(pushed, popped) << endl;
  return 0;
}
