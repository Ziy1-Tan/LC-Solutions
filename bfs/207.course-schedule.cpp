#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> inDegree(numCourses);
    vector<vector<int>> adj(numCourses);
    for (const auto &p : prerequisites) {
      inDegree[p[1]]++;
      adj[p[0]].push_back(p[1]);
    }

    queue<int> q;
    // 入度为0的节点入队，不需要前置课程
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      numCourses--;
      int i = q.front();
      q.pop();

      for (const auto &j : adj[i]) {
        // 入度为0的节点入队，不需要前置课程
        if (--inDegree[j] == 0) {
          q.push(j);
        }
      }
    }
    return numCourses == 0;
  }
};

class Solution2 {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> flags(numCourses);
    vector<vector<int>> adj(numCourses);
    for (const auto &pre : prerequisites) {
      adj[pre[1]].push_back(pre[0]);
    }

    for (int i = 0; i < numCourses; i++)
      if (!dfs(i, adj, flags)) {
        return false;
      }

    return true;
  }

 private:
  // 检查以i为起点的图有没有环,
  // 遍历该节点时，设置为1，遍历完该节点的所有邻接节点后，设置为-1
  bool dfs(int i, const vector<vector<int>> &adj, vector<int> &flags) {
    if (flags[i] == -1) {
      return true;
    }
    if (flags[i] == 1) {
      return false;
    }
    flags[i] = 1;
    for (const auto j : adj[i]) {
      if (!dfs(j, adj, flags)) {
        return false;
      }
    }
    flags[i] = -1;
    return true;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> pre = {{1, 0}};
  cout << (new Solution2)->canFinish(2, pre) << endl;
  return 0;
}
