#include "utils.h"

/*计数问题*/
class Solution {
public:
  vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
    vector<int> queries_idx(queries.size()), words_idx(words.size()), result(queries.size());

    for (int i = 0; i < queries.size(); i++)queries_idx[i] = count(queries[i]);
    for (int i = 0; i < words.size(); i++)words_idx[i] = count(words[i]);

    int nums[11] = {}, sums[11] = {};
    for (auto i:words_idx)nums[i]++;
    for (int i = 0; i < 11; i++) {
      for (int j = i + 1; j < 11; j++)sums[i] += nums[j];
    }

    for (int i = 0; i < queries.size(); i++) result[i] = sums[queries_idx[i]];
    return result;
  }

  static inline int count(string &s) {
    char c = s[0];
    int n = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == c)n++;
      else if (s[i] < c) {
        c = s[i];
        n = 1;
      }
    }
    return n;
  }
};

int main() {
  vector<string> queries = {"bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab",
                            "bbabbaabb"};
  vector<string> words = {"aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab", "aa"};

  Solution solution;
  solution.numSmallerByFrequency(queries, words);
  return 0;
}