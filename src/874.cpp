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

class HashSet {
private:
    struct Node {
        int x;
        int y;
        Node *next;
    };
public:
    void insert(int x, int y) {
        size_t loc = hash(x + y) % 1024;
        data[loc] = new Node{x, y, data[loc]};
    }

    bool contain(int x, int y) {
        size_t loc = hash(x + y) % 1024;
        for (auto *p = data[loc]; p; p = p->next)if (p->x == x && p->y == y)return true;
        return false;
    }

private:
    hash<int> hash;
    Node *data[1024] = {};
};


class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        HashSet set;
        for (auto &loc:obstacles)set.insert(loc[0], loc[1]);

        int v = 0, x = 0, y = 0, d = 0;
        for (auto cmd:commands) {
            switch (cmd) {
                case -1:
                    v = (v + 1) % 4;
                    break;
                case -2:
                    v = (v + 3) % 4;
                    break;
                default:
                    auto[v_x, v_y]=directions[v];
                    for (int i = 0; i < cmd; i++) {
                        x += v_x;
                        y += v_y;

                        if (set.contain(x, y)) {
                            x -= v_x;
                            y -= v_y;
                            break;
                        }
                    }
                    d = max(d, x * x + y * y);
                    break;
            }
        }
        return d;
    }

private:
    vector<tuple<int, int>> directions = {{0,  1},
                                          {1,  0},
                                          {0,  -1},
                                          {-1, 0}}; // 顺时针方向为正方向
};