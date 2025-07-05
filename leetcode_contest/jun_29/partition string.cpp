class Solution {
public:
    vector<string> partitionString(string s) {
        set<string>st;
       vector<string>vec;
        string result;
        int n=s.length();
            int j=0;
        while(j<n){
            result+=s[j];
            if(st.find(result)==st.end()){
             st.insert(result);
             vec.push_back(result);
            result="";
          
            }
           j++;
            
            
        }
        
       return vec;

    }
};
