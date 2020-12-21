#include "utils.h"

/*数学问题*/
class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
    int sum = 4; // 1971年1月1日是周五
    for (int i = 1971; i < year; i++) {
      sum += 365;
      if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)sum += 1;
    }
    for (int i = 0; i < month - 1; i++)sum += months[i];
    if (month > 2) {
      if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)sum += 1;
    }
    sum += day;

    sum %= 7;
    return names[sum];
  }

private:
  int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};;
  string names[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
};