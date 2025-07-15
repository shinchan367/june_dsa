class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) {
            return false;
        }

        bool hasVowel     = false;
        bool hasConsonant = false;

        for(char ch : word) {
            if(isalpha(ch)) {
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if(!isdigit(ch)) {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};


class Solution {
public:
    bool isValid(string word) {
        unordered_set<char>s={'a','e','i','o','u','A','E','I','O','U'};
        int n=word.size();
        if(n<3) return false;
        bool df=false,lf=false,uf=false,vf=false,cf=false;

        for( auto c:word){
            if(!isdigit(c) && !isalpha(c)) return false;
            if(islower(c)) lf=true;
            if(isupper(c)) uf=true;
            if(isdigit(c))   df=true;
            if(s.count(c)) vf=true;
            else if(!s.count(c) && isalpha(c)) cf=true;
        }
        return ((df||uf||lf)&vf &cf);
    }
};



class Solution:
    def isValid(self, word: str) -> bool:
        vowels = set('aeiouAEIOU')
        n = len(word)
        if n < 3:
            return False

        df = lf = uf = vf = cf = False

        for c in word:
            if not c.isdigit() and not c.isalpha():
                return False
            if c.islower():
                lf = True
            if c.isupper():
                uf = True
            if c.isdigit():
                df = True
            if c in vowels:
                vf = True
            elif c.isalpha():
                cf = True

        return (df or uf or lf) and vf and cf
