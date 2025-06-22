class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
       vector<string>vec;
        int n=s.length();
        int to_add=n%k;
        int count=n-to_add;
       
        for(int i=0;i<n;i+=k){
           if(i==count && to_add!=0){
             string combined =  s.substr(i,to_add) +string(k - to_add, fill);
              vec.push_back(combined);
              }
            else{
               vec.push_back(s.substr(i,k));
            }
        }
    
        return vec;
    }
};

////////////////////////// python //////////////////////////////////
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> list[str]:
        vec = []
        n = len(s)
        to_add = n % k
        count = n - to_add

        i = 0
        while i < n:
            if i == count and to_add != 0:
                combined = s[i:] + fill * (k - to_add)
                vec.append(combined)
            else:
                vec.append(s[i:i+k])
            i += k

        return vec
