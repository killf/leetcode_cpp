#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <hash_map>
#include <map>
#include <sstream>
#include <type_traits>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset>
#include <set>

using namespace std;

vector<string> get_all_domains(const string &s) {
  vector<string> result = {s};

  int start = 0, pos = s.find('.');
  while (pos != -1) {
    result.push_back(s.substr(start = pos + 1));
    pos = s.find('.', start);
  }

  return result;
}

class Solution {
public:
  vector<string> subdomainVisits(vector<string> &lines) {
    map<string, int> map;
    for (const auto &line:lines) {
      int pos = line.find(' ');
      int count = atoi(line.substr(0, pos).c_str());
      auto domains = get_all_domains(line.substr(pos + 1));
      for (const auto &key:domains) map[key] += count;
    }

    vector<string> result;
    stringstream ss;
    for (auto[k, v]:map) {
      ss.str("");
      ss << v << " " << k;
      result.push_back(ss.str());
    }
    return result;
  }
};

int main() {
  get_all_domains("www.killf.info");
  return 0;
}