class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n , 0); // Difference array with size n + 1
        
        // Step 1: Populate the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) { // Forward shift
                diff[start] += 1;
                if(end+1 < n)
                    diff[end + 1] -= 1;
            } else { // Backward shift
                diff[start] -= 1;
                if(end+1 < n)
                    diff[end + 1] += 1;
            }
        }
        
        // Step 2: Compute the prefix sum to get the net shifts for each character
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1]; // Add the value from the previous index
        }
        
        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = diff[i] % 26; // Ensure shift is within the range [0, 25]
            if (shift < 0)
                shift += 26; // Handle negative shifts (backward)
            
            // Apply the shift to character
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
            /*
                Note : s[i]-'a' gives the corresponding number of character s[i]
                       +shift adds the shift
                       %26 is to wrap around (0-25)
                       'a' + in the end converts back the number to character
            */
        }
        
        return s;
    }
};

class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[List[int]]
        :rtype: str
        """
        n=len(s)
        diff=[0]*n
        for i in shifts:
           start,end,direction=i
           if direction==1:
              diff[start]+=1
              if end+1<n:
                diff[end+1]-=1
           else:    
                diff[start]-=1
                if end+1<n:
                      diff[end+1]+=1


        for j in range(1,n):
            diff[j]+=diff[j-1]


        s=list(s)
        for i in range(n):
            shift=diff[i]%26
            if shift<0:
                shift+=26
            s[i]=chr((ord(s[i])-ord('a')+shift) %26 + ord('a'))        

        return ''.join(s) 
