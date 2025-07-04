class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1)return 'a';
        int n=operations.size();
        long long len=1;
        long long newk=0;
        int typeoperation;
        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                typeoperation=operations[i];
                newk=k-len/2;
                break;
            }
          }
          char res= kthCharacter(newk,operations);
          if(typeoperation==0){
            return res;
          }
         if(res=='z')return 'a';
         return res+1;

    }
};
