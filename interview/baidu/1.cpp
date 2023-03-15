#include <iostream>
using namespace std;

bool solve(const string& s) {
  if (s.size() != 5) {
    return false;
  }
  if (s.find('B') == string::npos) return false;
  if (s.find('a') == string::npos) return false;
  if (s.find('i') == string::npos) return false;
  if (s.find('d') == string::npos) return false;
  if (s.find('u') == string::npos) return false;

  return true;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (solve(s))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
