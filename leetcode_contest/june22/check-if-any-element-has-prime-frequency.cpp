class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
       for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
       }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        for (auto& [num, freq] : mp) {
            if (isPrime(freq)) {
                return true;
            }
        }

        return false;
    }
};

from collections import defaultdict
class Solution(object):

    def isprime(self,i):
        if i<=1:
            return False
        for j in range(2,int(i**0.5)+1):
         if i%j==0:
            return False
        return True                 




    def checkPrimeFrequency(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        freq_map=defaultdict(int)

        for num in nums:
            freq_map[num]+=1

        for i in freq_map.values():
            if self.isprime(i):
                return True

        return False            

        
