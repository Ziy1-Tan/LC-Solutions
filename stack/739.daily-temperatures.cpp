#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int t = st.top();
        st.pop();
        res[t] = i - t;
      }
      st.push(i);
    }

    return res;
  }
};
