class Solution {
public:
   unordered_set<string>exact;
   unordered_map<string,string>capitalcase;
   unordered_map<string,string>vowelcase;
   vector<string>result;
  
  string Tolower(string word){
    
    for(char &ch:word){
        ch=tolower(ch);
    }
    return word;
  }
  string tovowel(string lowercase){

    for(char &ch:lowercase){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            ch='*';
        }
    }
    return lowercase;
  }

    string checkquery(string s){
        if(exact.count(s)){
            return s;
        }
        string slower=Tolower(s);
        if(capitalcase.count(slower)){
             return capitalcase[slower];
        }

        string sgaped=tovowel(slower);
        if(vowelcase.count(sgaped)){
            return vowelcase[sgaped];
        }
        return "";
    }



    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exact.clear();
        capitalcase.clear();
        vowelcase.clear();
        result.clear();
        for(string word:wordlist){
            exact.insert(word);

            string lowercase=Tolower(word);
            if(capitalcase.find(lowercase)==capitalcase.end()){
                capitalcase[lowercase]=word;
            }

            string gaped=tovowel(lowercase);
            if(vowelcase.find(gaped)==vowelcase.end()){
                vowelcase[gaped]=word;
            }

            
            

        }
        for(string s:queries){
            result.push_back(checkquery(s));
        }
        return result;
    }
};
