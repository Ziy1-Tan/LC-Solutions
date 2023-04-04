#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[]) {
  string src;
  cin >> src;
  int q;
  cin >> q;
  unordered_map<string, string> map;
  stringstream ss(src);
  string kv;
  while (getline(ss, kv, ';')) {
    int idx = kv.find('=');
    string key = kv.substr(0, idx);
    string val = kv.substr(idx + 1);
    map.insert({key, val});
  }


  for (int i = 0; i < q; i++) {
    string str;
    cin >> str;
    if (!map.count(str)) {
      cout << "EMPTY" << endl;
    } else {
      cout << map[str] << endl;
    }
  }

  return 0;
}
