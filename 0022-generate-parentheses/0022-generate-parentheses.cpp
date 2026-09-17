/*
insights
- total length = 2 * n
- backtracking



*/

class Solution {
public:
    vector<string> res;
    bool valid(string& curr) {
        stack<char> st;
        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] == '(') {
                st.push(curr[i]);
            } else if (curr[i] == ')') {
                if (st.empty()) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
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