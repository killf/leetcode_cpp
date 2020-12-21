#include "utils.h"

/*数学问题*/
class Solution {
public:
  int dayOfYear(string date) {
    vector<string> ss = split(date, '-');
    int year = atoi(ss[0].c_str());
    int month = atoi(ss[1].c_str());
    int day = atoi(ss[2].c_str());

    for (int i = 0; i < month - 1; i++)day += months[i];
    if (month > 2) {
      if (year % 100 == 0) {
        if (year % 400 == 0)day++;
      } else if (year % 4 == 0) day++;
    }
    return day;
  }

private:
  int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};