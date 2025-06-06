#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate subsets
void subset(vector<int> ip, vector<int> op, set<vector<int>>& ans) {
    if (ip.size() == 0) {
        ans.insert(op);  // Insert into set to avoid duplicates
        return;
    }

    vector<int> op1 = op;     // Exclude current element
    vector<int> op2 = op;     // Include current element

    op2.push_back(ip[0]);     // Include ip[0] in op2
    ip.erase(ip.begin());     // Remove ip[0] from ip

    subset(ip, op1, ans);     // Recursive call without current element
    subset(ip, op2, ans);     // Recursive call with current element
}

int main() {
    vector<int> ip = {1, 2, 2};     // Input with duplicates
    sort(ip.begin(), ip.end());    // Sort input to help with duplicate handling

    vector<int> op;                // Output subset
    set<vector<int>> ans;         // Set to store unique subsets

    subset(ip, op, ans);

    // Print all unique subsets
    cout << "Unique subsets:\n";
    for (auto vec : ans) {
        cout << "{ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;
}
