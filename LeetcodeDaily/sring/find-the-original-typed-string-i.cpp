//Approach (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;

        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1])
                count++;
        }

        return count+1; //+1 for when Alice does no long press
    }
};

/////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
         int dup=0;
         int count=1;
        for(int i=0;i<n;i++){
          
           if(i+1<=n && word[i]!=word[i+1]  ){
            dup=0;
           }
           else{
              dup++;
              count+=1;
         
           }
        }
        return count;
    }
};
