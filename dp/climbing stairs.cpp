class Solution {
public:
    int climbStairs(int n) {
        if(n==0)return 1;
        if(n<0)return 0;
        int onestep=climbStairs(n-1);
        int twostep=climbStairs(n-2);
        return onestep+twostep;
    }
};

//////////////////
class Solution {
     int t[46];
public:
Solution() {
        memset(t, -1, sizeof(t));
    }
    int climbStairs(int n) {
        
        
        if(n==0)return 1;
        if(n<0)return 0;
        if(t[n]!=-1)return t[n];
        int onestep=climbStairs(n-1);
        int twostep=climbStairs(n-2);
        return t[n]=onestep+twostep;
    }
};


/////////////////////////////////////////
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        
        vector<int> t(n+1);
        
        //t[i] = total ways to climb i stairs
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;
        
        for(int i = 3; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        
        return t[n];
    }
};
