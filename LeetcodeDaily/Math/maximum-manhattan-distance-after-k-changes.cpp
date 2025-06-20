class Solution {
public:
    int maxDistance(string s, int k) {
        int mhd=0;
        int east=0;
        int west=0;
        int north=0;
        int south=0;
         int extras=0;
         int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='E')east++;
            else if(s[i]=='W')west++;
            else  if(s[i]=='N')north++;
            else  if(s[i]=='S')south++;

            mhd=abs(east-west)+abs(north-south);
            int steps=i+1;
            int wasted=abs(steps-mhd);
           
            if(wasted!=0){
               extras=min(2*k,wasted);
            }
       int final=extras+mhd;
        maxi=max(final,maxi);

        }
        return maxi;
    }
};


////observation 1:starts from origin so only x+y
//observation 2:vertical +horizontal  logic
//observation 3:we can get extra 2*k steps
//observation 4:calculating wasted
