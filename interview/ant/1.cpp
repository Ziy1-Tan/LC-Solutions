#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      a++;
    } else if (s[i] == 'b') {
      b++;
    } else if (s[i] == 'c') {
      c++;
    }
  }

  if (a >= (b + c))
    cout << ((a - b - c) / 2) << endl;
  else
    cout << ((b + c - a) / 2) << endl;

  return 0;
}
