void subset(vector<string> ip, vector<string> op, vector<vector<string>>& ans) {
    if (ip.size() == 0) {
        ans.push_back(op);
        return;
    }

    vector<string> op1 = op;       // excluding current element
    vector<string> op2 = op;       
    op2.push_back(ip[0]);          // including current element

    ip.erase(ip.begin());          // remove the current element from input

    subset(ip, op1, ans);          // recursive call for exclude
    subset(ip, op2, ans);          // recursive call for include
}
