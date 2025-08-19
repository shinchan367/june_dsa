class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        
        long long count=0;
        while(j<n){
            long long zeros=0;
            if(nums[j]==0){
               while(j<n && nums[j]==0){
                j++;
                zeros++;
               }
            }
            else{
                j++;
            }
            count+=(zeros)*(zeros+1)/2;
            
        }
       return count;
       
    }
};



class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long total=0;
        long long count=0;
        int j=0;
        while(j<n){
            if(nums[j]==0){
                count=0;
                while(j<n && nums[j]==0){
                    count++;
                    total+=count;
                    j++;
                }
            }
           
            j++;
        }
        return total;
    }
};
