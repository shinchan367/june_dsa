#include <iostream>
#include <cctype> // for toupper
using namespace std;

void solve(string ip, string op) {
    if (ip.length() == 0) {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    // Append as-is
    op1.push_back(ip[0]);

    // Append uppercase
    op2.push_back(toupper(ip[0]));  // Correct use of toupper()

    ip.erase(ip.begin());  // Remove first char from input

    solve(ip, op1);  // Recurse without changing case
    solve(ip, op2);  // Recurse with uppercase
}

int main() {
    string input = "ab";
    string output = "";

    solve(input, output);

    return 0;
}
