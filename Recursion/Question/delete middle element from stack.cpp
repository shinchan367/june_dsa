#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int k) {
    // Base case: if we've reached the kth element
    if (k == 1) {
        s.pop(); // Delete the middle element
        return;
    }

    int temp = s.top();
    s.pop();

    // Recursive call for next element
    solve(s, k - 1);

    // Push the element back after deleting middle
    s.push(temp);
}

void deleteMiddle(stack<int>& s) {
    int size = s.size();
    int k = (size / 2) + 1; // 1-based indexing for kth element

    solve(s, k);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);  // Top -> 5

    deleteMiddle(s); // Deletes 3 (middle of 5 elements)

    // Print remaining stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    // Output: 5 4 2 1
}
