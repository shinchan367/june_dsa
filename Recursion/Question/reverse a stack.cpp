#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert element at the bottom of stack
void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(temp);
}

// Main function to reverse the stack
void reverse(stack<int>& s) {
    if (s.size() == 1) return;

    int temp = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, temp);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);  // Top -> 5

    reverse(s); // After reversing: Top -> 1

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    // Output: 1 2 3 4 5
}
