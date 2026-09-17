/*
insights
- total length = 2 * n
- backtracking



*/

class Solution {
public:
    vector<string> res;
    bool valid(string& curr) {
        int cnt = 0;
        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] == '(') {
                cnt++;
            } else if (curr[i] == ')') {
                cnt--;
            }
            if (cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }
    void solve(string& curr, int n) {
        if (curr.size() == 2 * n) {
            if (valid(curr)) {
                res.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr, n);

        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);

        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return res;
    }
};