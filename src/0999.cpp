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
#include <set>
#include <list>
#include <cstring>
#include <bitset>

using namespace std;

class Solution {
public:
  int numRookCaptures(vector<vector<char>> &board) {
    int x = 0, y = 0;
    for (; x < 8; x++) {
      for (y = 0; y < 8; y++) {
        if (board[x][y] == 'R')goto next_step;
      }
    }

    next_step:
    int count = 0;
    for (int i = x + 1; i < 8; i++) {
      if (board[i][y] == '.')continue;
      if (board[i][y] == 'B')break;
      if (board[i][y] == 'p') {
        count++;
        break;
      }
    }

    for (int i = x - 1; i >= 0; i--) {
      if (board[i][y] == '.')continue;
      if (board[i][y] == 'B')break;
      if (board[i][y] == 'p') {
        count++;
        break;
      }
    }

    for (int i = y + 1; i < 8; i++) {
      if (board[x][i] == '.')continue;
      if (board[x][i] == 'B')break;
      if (board[x][i] == 'p') {
        count++;
        break;
      }
    }

    for (int i = y - 1; i >= 0; i--) {
      if (board[x][i] == '.')continue;
      if (board[x][i] == 'B')break;
      if (board[x][i] == 'p') {
        count++;
        break;
      }
    }

    return count;
  }
};