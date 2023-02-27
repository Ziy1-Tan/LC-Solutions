#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

struct URLObject {
  string protocol;
  string domain;
  string path;
  unordered_map<string, string> querys;
  string hash;
};

URLObject parseURL(string url) {
  URLObject obj;
  std::size_t pos = url.find("://");
  if (pos == string::npos) {
    return obj;
  }
  obj.protocol = url.substr(0, pos);

  url = url.substr(pos + 3);
  pos = url.find('/');
  if (pos == string::npos) {
    obj.domain = url.substr(0);
    return obj;
  }
  obj.domain = url.substr(0, pos);

  url = url.substr(pos + 1);
  pos = url.find('?');
  if (pos == string::npos) {
    obj.path = url.substr(0);
    return obj;
  }
  obj.path = url.substr(0, pos);

  url = url.substr(pos + 1);
  pos = url.find('#');
  if (pos != string::npos) {
    obj.hash = url.substr(pos + 1);
    url = url.substr(0, pos);
  }

  stringstream stream(url);
  string seg;
  while (getline(stream, seg, '&')) {
    std::size_t splitIdx = seg.find('=');
    string key = seg.substr(0, splitIdx);
    string val = seg.substr(splitIdx + 1);
    obj.querys[key] = val;
  }

  return obj;
}

int main(int argc, char const* argv[]) {
  string url =
      "https://www.google.com/"
      "search?q=url+parse&oq=url+parse&aqs=chrome.0.35i39l2j0l4j46j69i60."
      "2026j0j7&sourceid=chrome&ie=UTF-8#title";
  auto obj = parseURL(url);
  cout << "protocol: " << obj.protocol << '\n';
  cout << "domain: " << obj.domain << '\n';
  cout << "path: " << obj.path << '\n';
  cout << "query: " << '\n';
  for (const auto& [key, value] : obj.querys) {
    cout << key << " = " << value << '\n';
  }
  cout << "hash: " << obj.hash << '\n';

  return 0;
}
