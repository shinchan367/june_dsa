typedef long long ll;
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        ll ans = LLONG_MIN;

        // If m == 1, return the maximum square of any number
        if (m == 1) {
            for (auto it : nums) {
                ll v = (ll)it * it;
                ans = max(ans, v);
            }
            return ans;
        }

        // Initialize max and min of first elements in window
        ll maxi = LLONG_MIN;
        ll mini = LLONG_MAX;

        // Sliding window of size m
        for (int j = m - 1; j < n; j++) {
            int i = j - m + 1; // start of the window
            maxi = max(maxi, (ll)nums[i]);
            mini = min(mini, (ll)nums[i]);

            ll prod1 = maxi * nums[j];
            ll prod2 = mini * nums[j];
            ans = max(ans, max(prod1, prod2));
        }

        return ans;
    }
};



from typing import List

class Solution:
    def maximumProduct(self, nums: List[int], m: int) -> int:
        n = len(nums)
        ans = float('-inf')
        
        # Case 1: If m == 1, return the max square of any number
        if m == 1:
            for num in nums:
                ans = max(ans, num * num)
            return ans

        # Case 2: For m > 1, track max and min of first elements in each window
        maxi = float('-inf')
        mini = float('inf')

        for j in range(m - 1, n):
            i = j - m + 1  # Start index of the window
            maxi = max(maxi, nums[i])
            mini = min(mini, nums[i])

            prod1 = maxi * nums[j]
            prod2 = mini * nums[j]
            ans = max(ans, prod1, prod2)

        return ans
