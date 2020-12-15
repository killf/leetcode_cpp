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

using namespace std;


// Definition for Employee.
class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
};


class Solution {
public:
  int getImportance(vector<Employee *> employees, int id) {
    map<int, Employee *> map;
    for (const auto &iter:employees)map[iter->id] = iter;
    return visit(map, id);
  }

  int visit(map<int, Employee *> &map, int id) {
    auto *employee = map[id];

    int sum = employee->importance;
    for (auto i:employee->subordinates)sum += visit(map, i);
    return sum;
  }
};