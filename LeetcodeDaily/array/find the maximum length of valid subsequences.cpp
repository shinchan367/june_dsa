class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0, n = nums.size();

        int odd = 0, even = 0, alternate = 1, prev = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1) odd++;
            else even++;

            if(i >= 1 && nums[i] % 2 != prev % 2){
                alternate++;
                prev = nums[i];
            }
        }
        return max({odd, even, alternate});
    }
};

class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        even=0
        odd=0
        both=1
        for i in nums:
            if i%2==0:
                even+=1
            else:
                odd+=1
        parity=nums[0]%2
        for j in range(1,n):
            currparity=nums[j]%2
            if currparity!=parity:
                both+=1
                parity=currparity

        return max(both,even,odd)        

        
