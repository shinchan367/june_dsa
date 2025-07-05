class Solution {
public:
    int solve(string a, string b) {
        int len = min(a.size(), b.size());
        int cnt = 0;
        while (cnt < len && a[cnt] == b[cnt]) cnt++;
        return cnt; // Returns LCP length of two strings
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n, 0);
        if (n <= 1) return ans;

        // Step 1: Calculate LCPs between adjacent words
        vector<int> lcp(n - 1, 0);
        for (int i = 0; i + 1 < n; i++)
            lcp[i] = solve(words[i], words[i + 1]);

        // Step 2: Compute prefix max
        vector<int> prefmax(n - 1);
        prefmax[0] = lcp[0];
        for (int i = 1; i < n - 1; i++)
            prefmax[i] = max(prefmax[i - 1], lcp[i]);

        // Step 3: Compute suffix max
        vector<int> sufmax(n - 1);
        sufmax[n - 2] = lcp[n - 2];
        for (int i = n - 3; i >= 0; i--)
            sufmax[i] = max(sufmax[i + 1], lcp[i]);

        // Step 4: Final answer computation
        for (int i = 0; i < n; i++) {
            int best = 0;
            if (i >= 2) best = max(best, prefmax[i - 2]);          // left part
            if (i + 1 <= n - 2) best = max(best, sufmax[i + 1]);   // right part
            if (i > 0 && i < n - 1)
                best = max(best, solve(words[i - 1], words[i + 1])); // new adjacent
            ans[i] = best;
        }

        return ans;
    }
};
///
