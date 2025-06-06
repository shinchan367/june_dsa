#include <iostream>
using namespace std;

void solve(string ip, string op) {
    if (ip.size() == 0) {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(ip[0]);           // Add without space
    op2.push_back('_');             // Add space
    op2.push_back(ip[0]);           // Then add character

    ip.erase(ip.begin());           // Remove first character from input

    solve(ip, op1);                 // Recurse without space
    solve(ip, op2);                 // Recurse with space
}

int main() {
    string input = "ABC";
    string op = "";
    op.push_back(input[0]);         // First character goes to output directly
    input.erase(input.begin());     // Remove first char from input

    solve(input, op);

    return 0;
}



