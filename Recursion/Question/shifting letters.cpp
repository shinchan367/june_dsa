class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<long long> suffix(n, 0);  // initialize with size `n` and value `0`

        // build suffix sum from right to left
        suffix[n - 1] = shifts[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = shifts[i] + suffix[i + 1];
        }

        // apply shifts to each character
        for (int i = 0; i < n; ++i) {
            s[i] = (s[i] - 'a' + suffix[i]) % 26 + 'a';
        }

        return s;
    }
};

//////////////////
class Solution {
public:
    void shiftRec(string &s, vector<int> &shifts, int i, int &accShift) {
        if (i < 0) return;

        // Add current shifts to accumulated shift
        accShift = (accShift + shifts[i]) % 26;

        // Apply the accumulated shift to the current character
        s[i] = (s[i] - 'a' + accShift) % 26 + 'a';

        // Recurse for previous character
        shiftRec(s, shifts, i - 1, accShift);
    }

    string shiftingLetters(string s, vector<int>& shifts) {
        int accShift = 0;
        shiftRec(s, shifts, (int)s.size() - 1, accShift);
        return s;
    }
};
