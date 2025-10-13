#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]); // first word is always kept

        for (int i = 1; i < words.size(); i++) {
            string prev = words[i - 1];
            string curr = words[i];
            sort(prev.begin(), prev.end());
            sort(curr.begin(), curr.end());

            // if not an anagram, add to result
            if (prev != curr) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
