class Solution {
public:
    int frogJump(vector<int>& heights, int ind) {
        if (ind == 0) return 0;

        int jumpOne = frogJump(heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
        int jumpTwo = INT_MAX;
        if (ind > 1) jumpTwo = frogJump(heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);

        return min(jumpOne, jumpTwo);
    }

    int frogJump(vector<int>& heights) {
        return frogJump(heights, heights.size() - 1);
    }
};


///////////////////////////
class Solution {
    int t[100001];
public:
    Solution() {
        memset(t, -1, sizeof(t));
    }

    int frogJumpRec(vector<int>& heights, int ind) {
        if (ind == 0) return 0;
        if (t[ind] != -1) return t[ind];

        int jumpOne = frogJumpRec(heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
        int jumpTwo = INT_MAX;
        if (ind > 1) jumpTwo = frogJumpRec(heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);

        return t[ind] = min(jumpOne, jumpTwo);
    }

    int frogJump(vector<int>& heights) {
        return frogJumpRec(heights, heights.size() - 1);
    }
};
///////////
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            int jumpOne = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int jumpTwo = INT_MAX;
            if (i > 1) jumpTwo = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            dp[i] = min(jumpOne, jumpTwo);
        }

        return dp[n - 1];
    }
};
