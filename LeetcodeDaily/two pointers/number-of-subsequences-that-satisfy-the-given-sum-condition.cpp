class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7, n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0, right = n - 1, result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % mod;
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution(object):
    def numSubseq(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n=len(nums)
        mod=10**9+7
        power=[1]*n
        nums.sort()
        for i in range(1,n):
           power[i]=(power[i-1]*2)%mod

        left=0
        right=n-1
        result=0
        while left<=right:

            if nums[left]+nums[right]<=target:
                diff=right-left
                result =( result + power[diff]) %mod
                left+=1
            else:
                right-=1    
        return result

        
