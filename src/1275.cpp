#include "utils.h"

/*博弈问题*/
class Solution {
public:
  string tictactoe(vector<vector<int>> &moves) {
    Mat<char> m(3, 3);
    char c = 0;
    for (int i = 0; i < moves.size(); i++) {
      m(moves[i][0], moves[i][1]) = i & 1 ? 'B' : 'A';
      if ((c = judge(m)))return string(1, c);
    }
    return moves.size() < 9 ? "Pending" : "Draw";
  }

  inline char judge(Mat<char> &m) {
    char c;
    for (int i = 0; i < 3; i++) {
      if ((c = m(i, 0)) && m(i, 1) == c && m(i, 2) == c)return c;
      if ((c = m(0, i)) && m(1, i) == c && m(2, i) == c)return c;
    }

    if ((c = m(0, 0)) && m(1, 1) == c && m(2, 2) == c)return c;
    if ((c = m(0, 2)) && m(1, 1) == c && m(2, 0) == c)return c;

    return 0;
  }
};