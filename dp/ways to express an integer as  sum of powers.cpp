/////////////////     /recursion       /////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(int n, int x) {
        // Step 1: store all i^x values ≤ n
        vector<int> powers;
        for (int i = 1; ; i++) {
            long long val = 1;
            for (int j = 0; j < x; j++) val *= i;
            if (val > n) break;
            powers.push_back(val);
        }

        // Step 2: recursive function
        return countWays(powers, 0, n);
    }

private:
    int countWays(vector<int>& powers, int idx, int remaining) {
        if (remaining == 0) return 1; // found valid set
        if (idx >= powers.size() || remaining < 0) return 0;

        // include current power
        long long include = countWays(powers, idx + 1, remaining - powers[idx]) % MOD;
        // skip current power
        long long exclude = countWays(powers, idx + 1, remaining) % MOD;

        return (include + exclude) % MOD;
    }
};



///////////////////// memo //////////////////////////
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int numberOfWays(int n, int x) {
        // Step 1: Build vector of i^x <= n
        vector<int> powers;
        for (int i = 1; ; i++) {
            long long val = 1;
            for (int j = 0; j < x; j++) val *= i;
            if (val > n) break;
            powers.push_back(val);
        }

        // Step 2: Initialize dp with -1 (uncomputed)
        dp.assign(powers.size(), vector<int>(n + 1, -1));

        // Step 3: Count ways with recursion + memoization
        return countWays(powers, 0, n);
    }

private:
    int countWays(vector<int>& powers, int idx, int remaining) {
        if (remaining == 0) return 1;   // found valid set
        if (idx >= powers.size() || remaining < 0) return 0;

        if (dp[idx][remaining] != -1) return dp[idx][remaining];

        // include current power
        long long include = countWays(powers, idx + 1, remaining - powers[idx]) % MOD;
        // skip current power
        long long exclude = countWays(powers, idx + 1, remaining) % MOD;

        return dp[idx][remaining] = (include + exclude) % MOD;
    }
};


/////////////////  dp ///////////////////
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfWays(int n, int x) {
        // Step 1: Build vector of i^x <= n
        vector<int> powers;
        for (int i = 1; ; i++) {
            long long val = 1;
            for (int j = 0; j < x; j++) val *= i;
            if (val > n) break;
            powers.push_back(val);
        }

        // Step 2: Bottom-up DP
        // dp[i] = number of ways to make sum i
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // 1 way to make sum 0 (pick nothing)

        // Step 3: Process each power once (ensures uniqueness)
        for (int p : powers) {
            for (int sum = n; sum >= p; sum--) {
                dp[sum] = (dp[sum] + dp[sum - p]) % MOD;
            }
        }

        return dp[n];
    }
};
