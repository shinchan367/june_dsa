class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod=1e9+7;
        int n=nums.size();
        unordered_map<int,int>left;
        unordered_map<int,int>right;
     long long total=0;
        for(auto freq:nums){
            right[freq]++;
        }
        for(int j=0;j<n;j++){
            right[nums[j]]--;
            int target=nums[j]*2;

            long long countleft=left[target];
           long long countright=right[target];

            total=(total+countleft*countright)%mod;
             left[nums[j]]++;
        }
        return static_cast<int>(total);
    }
};



from collections import defaultdict
class Solution(object):
    def specialTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mod=10**9+7
        n=len(nums)
        left=defaultdict(int)
        right=defaultdict(int)

        for num in nums:
            right[num]+=1
        total=0 
        for i in range(n):
            right[nums[i]]-=1
            target=nums[i]*2

            countright=right[target]
            countleft=left[target]

            total=(total+countright*countleft)%mod
            left[nums[i]]+=1
        return total     
