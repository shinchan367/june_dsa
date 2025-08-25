#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the mimimum 
    energy to reach last stair*/
    int frogJump(vector<int> &heights, int k) {
        int ind = heights.size();

        /*Initialize a memoization array
        to store calculated results*/
        vector<int> dp(ind + 1, -1);

        dp[0] = 0;

        // Loop through the array 
        for (int i = 1; i < ind; i++) {
            int mmSteps = INT_MAX;

            // Loop to try all possible jumps from '1' to 'k'
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    
                    //Update the Minimum energy
                    mmSteps = min(jump, mmSteps);
                }
            }
            dp[i] = mmSteps;
        }
        //Result is stored in the last element of dp
        return dp[ind - 1]; 

    }
};

int main() {
    vector<int> height {15,4,1,14,15};
    int k = 3;

    // Create an instance of Solution class
    Solution sol;

    // Print the answer
    cout << "Minimum energy : " << sol.frogJump(height, k) << endl;

    return 0;
}


class Solution {
public:
   int jump(vector<int>&heights,int ind,int k,vector<int>&dp){
    if(ind==0)return 0;
    int mini=INT_MAX;
    if(dp[ind]!=-1)return dp[ind];
    for(int i=1;i<=k;i++){
      if(ind-i>=0){
      int steps=jump(heights,ind-i,k,dp)+abs(heights[ind]-heights[ind-i]);
        mini=min(mini,steps);
    }
   }
   return dp[ind]=mini;
   }


    int frogJump(vector<int>& heights, int k) {
      int n=heights.size();
      int ind=n-1;
      vector<int>dp(n,-1);
       return jump(heights,ind,k,dp); 
      }
    
};

class Solution {
public:
   int jump(vector<int>&heights,int ind,int k){
    if(ind==0)return 0;
    int mini=INT_MAX;
    
    for(int i=1;i<=k;i++){
      if(ind-i>=0){
      int steps=jump(heights,ind-i,k)+abs(heights[ind]-heights[ind-i]);
      mini=min(mini,steps);
    }
   }
   return mini;
   }


    int frogJump(vector<int>& heights, int k) {
      int n=heights.size();
      int ind=n-1;
       return jump(heights,ind,k); 
      }
    
};
