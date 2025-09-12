class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        for(char ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')count++;
        }
        return (count>0);
    }
};
