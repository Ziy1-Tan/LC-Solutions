#include <iostream>
#include <vector>
using namespace std;

void doFmt(int cnt, int n) {
  int i = cnt;
  while (i > 0) {
    if (cnt % i == 0 && n % i == 0) {
      cnt = cnt / i;
      n = n / i;
      break;
    }
    i--;
  }
  cout << cnt << "/" << n << endl;
}

int main(int argc, char const *argv[]) {
  int n;
  vector<int> nums;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  int cnt = 0;
  int currIdx = 0;
  for (int i = 0; i < n; i++) {
    currIdx = i;
    int turn = 0;
    while (true) {
      bool flag = false;
      for (int j = 0; j < currIdx; j++) {
        if (nums[j] < nums[currIdx]) {
          currIdx = j;
          flag = true;
          break;
        }
      }
      if (turn % 2 == 1 && !flag) {
        cnt++;
      }
      if (!flag) {
        break;
      }
      turn++;
    }
  }

  if (cnt == n) {
    cout << "1/1" << endl;
  } else if (cnt == 0) {
    cout << "0/1" << endl;
  } else {
    doFmt(cnt, n);
  }

  return 0;
}
