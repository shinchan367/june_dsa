#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    long long total = 0;

    // Brute-force all subarrays
    for (int i = 0; i < n; ++i) {
        int minVal = a[i], maxVal = a[i];
        for (int j = i; j < n; ++j) {
            minVal = min(minVal, a[j]);
            maxVal = max(maxVal, a[j]);
            total = (total + 1LL * minVal * maxVal) % MOD;
        }
    }

    cout << total << endl;
    return 0;
}
