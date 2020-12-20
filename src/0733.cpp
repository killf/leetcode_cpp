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

using namespace std;


class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int row = image.size(), col = image[0].size(), color = image[sr][sc];
    if (color == newColor)return image;

    queue<tuple<int, int>> queue;
    queue.emplace(sr, sc);

    vector<tuple<int, int>> offsets = {{-1, 0},
                                       {1,  0},
                                       {0,  -1},
                                       {0,  1}};

    while (!queue.empty()) {
      auto[r, c]=queue.front();
      queue.pop();

      image[r][c] = newColor;
      for (auto[i, j]:offsets) {
        i = r + i;
        j = c + j;
        if (i >= 0 && i < row && j >= 0 && j < col && image[i][j] == color)queue.emplace(i, j);
      }
    }

    return image;
  }
};