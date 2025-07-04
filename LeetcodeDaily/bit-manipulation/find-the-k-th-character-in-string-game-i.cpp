/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (Simulation)
//T.C : O(k)
//S.C : O(k)
class Solution {
public:

    char kthCharacter(int k) {
        int idx = k-1;
        string result = "a";

        while(result.length() < k) {
            int n = result.length();
            for(int i = 0; i < n; i++) {
                char ch = result[i] == 'z' ? 'a' : result[i]+1;
                result.push_back(ch);
            }
        }

        return result[idx];
    }
};


//Approach-2 (bit observation to find shift)
//T.C : O(log(k-1))
//S.C : O(1)
class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k-1);

        return 'a' + shift;
    }
};
///////////////////                  python        //////////////////////////////////
class Solution(object):
    def kthCharacter(self, k):
        """
        :type k: int
        :rtype: str
        """
        shift = bin(k - 1).count('1')   # Count 1-bits in binary of (k - 1)
        result = chr(ord('a') + shift) 
        return result
        
        /*Python Character & Binary Conversion Cheat Sheet

ord(char)

Converts a character to its Unicode integer value.

Example:
ord('a') → 97
ord('z') → 122

chr(int)

Converts an integer (Unicode code point) to its corresponding character.

Example:
chr(97) → 'a'
chr(122) → 'z'

Shift a character forward

Example:
chr(ord('a') + 3) → 'd'

bin(num)

Converts an integer to its binary representation as a string.

Example:
bin(5) → '0b101'

Count set bits (1s) in binary

Use .count('1') on the result of bin()

Example:
bin(13).count('1') → 3 (because 13 in binary is 1101)

Putting it all together

python
Copy
Edit
k = 5
shift = bin(k - 1).count('1')      # Count 1s in binary of (k - 1)
result = chr(ord('a') + shift)     # Shift 'a' by that number
print(result)                      # Output: 'b'*/
