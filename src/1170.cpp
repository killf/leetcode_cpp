#include "utils.h"

/*计数问题*/
class Solution {
public:
  vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
    vector<int> queries_idx(queries.size()), words_idx(words.size()), result(queries.size());

    for (int i = 0; i < queries.size(); i++)queries_idx[i] = count(queries[i]);
    for (int i = 0; i < words.size(); i++)words_idx[i] = count(words[i]);

    sort(words_idx.begin(), words_idx.end());

    for (int i = 0; i < queries.size(); i++) {
      for (int j = words.size() - 1; j >= 0; j--) {
        if (queries_idx[i] < words_idx[j])result[i]++; else break;
      }
    }
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