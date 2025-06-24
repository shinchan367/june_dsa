class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
       set<int> vec;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            int value=abs(i-j);
            if(value<=k && nums[j]==key){
              vec.insert(i);
            }
        }
    }
    vector<int> temp(vec.begin(),vec.end());
    return temp;  
    }
};
///
//🧠 Time Complexity:
//Outer loop: O(n)
//Inner loop: O(n)
//Inside inner loop: most expensive part is set.insert() → O(log n)
//So total time complexity is:
//𝑂(n*n*logn)
//O(n⋅n⋅logn)=O(n^2logn) 

//📦 Space Complexity:
//You store at most n indices in a set, so:
//Space = O(n)

/////////////////////////////////////////////////////two pointer//////////////////////////////////////////


class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        int overlap = 0; // Pointer to avoid re-adding the same index
        vector<int> vec;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {

                // 📌 Observation 1: For every key, find the valid index range [start, end]
                int start = max(0, i - k);
                int end = min(i + k, n - 1);

                // 📌 Observation 2: Only add indices that haven’t been added yet using 'overlap'
                // This ensures each index is added only once
                while (overlap <= end) {
                    if (start <= overlap)
                        vec.push_back(overlap);
                    overlap++;
                }
            }
        }

        return vec;
    }
};

🧠 Summary
Observation 1: For every occurrence of key, calculate [i - k, i + k] bounded by array size.

Observation 2: Use overlap to avoid re-inserting already-added indices for overlapping ranges.

⏱️ Time Complexity:
O(2*n) overall, because each index is visited at most once by the overlap pointer.

Space: O(n) in the worst case (when all indices are valid).
