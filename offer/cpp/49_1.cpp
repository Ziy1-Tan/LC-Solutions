// 超时了
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int nthUglyNumber(int n) {
    int cnt = 1;
    int curr = 1;
    while (cnt < n) {
      //迭代
      //对于小于等于curr的每一个质因子，判断一下
      int prime = 5;
      bool b = false;

      // 先判断2,3,5是否是质因子
      for (const auto f : factors) {
        if (curr % f == 0) {
          b = true;
          break;
        }
      }

      bool flag = true;
      // 判断是否有大于5的质数因子
      while (prime != -1 && prime <= curr) {

        prime = getNextPrimeNum(prime, curr);
        if (prime > 5 && curr % prime == 0) {
          flag = false;
          break;
        }
      }
      // 有质因子2、3或5且没有大于5的质因子
      if (b && flag) {
        cnt++;
      }
      curr++;
    }
    return n == 1 ? 1 : curr - 1;
  }

private:
  vector<int> factors{2, 3, 5};
  unordered_map<int, int> dict;
  int getNextPrimeNum(int prime, int num) {
    if (dict.count(prime) != 0)
      return dict.at(prime);
    int i;
    for (i = prime + 1;; i++) {
      if (isPrime(i)) {
        dict[prime] = i;
        break;
      }
    }
    return i > num ? -1 : i;
  }

  bool isPrime(int num) {
    for (int i = 2; i < num; i++) {
      if (num % i == 0)
        return false;
    }
    return true;
  }
};

int main(int argc, const char *argv[]) {
  // 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
  auto num = Solution().nthUglyNumber(11);
  cout << num << endl;
  return 0;
}