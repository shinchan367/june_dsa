class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        bool newWord = true;
        bool firstWord = true;

        for (char c : caption) {
            if (isalpha(c)) {
                if (firstWord) {
                    res += tolower(c);
                    firstWord = false;
                    newWord = false;
                } else if (newWord) {
                    res += toupper(c);
                    newWord = false;
                } else {
                    res += tolower(c);
                }
            } else {
                newWord = true;
            }
        }

        if (res.length() > 100)
            res = res.substr(0, 100);

        return res;
    }
};

