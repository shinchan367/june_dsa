class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
       int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=0;
        int count=0;
        while(low<n ){
            high=low;
           while(high<n && (nums[high]-nums[low])<=k){
               high++;
            }
            count++;
            low=high;
            }
            return count;
    }
};
/////////////////////////////////////////////      python        /////////////////////////////////////////////
class Solution(object):
    def partitionArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        n=len(nums)
        low=0
        high=0
        count=0
        while low<n:
            high=low
            while high<n and nums[high]-nums[low]<=k:
                high+=1
            count+=1
            low=high
        return count    
