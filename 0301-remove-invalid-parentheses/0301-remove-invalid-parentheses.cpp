class Solution {
public:
    int mx;
    void solve(string& s, int i, set<string>& st, int cnt, string& tmp) {

        if (cnt < 0)
            return;
        if (i == s.size()) {
            if (cnt == 0) {
                // string is balanced, needs another checking if it
                // is more than maxlen, because max len string
                // meeans it has least number of elimination

                if (tmp.size() > mx) {
                    mx = tmp.size();
                    st.clear(); // found a better answer, so clearing out}
                }
                if (tmp.size() == mx) {
                    st.insert(tmp);
                }
            }
            return;
        }
        // two options to take or not take, but letter is always taken.
        if (s[i] != '(' && s[i] != ')') {
            tmp.push_back(s[i]);
            solve(s, i + 1, st, cnt, tmp); // take only.
            tmp.pop_back();                // why?? i dont get this cuz
            // need to restore tmp to the state it had before processing a
            return;
        }
        tmp.push_back(s[i]);
        solve(s, i + 1, st, cnt + (s[i] == '(' ? 1 : -1), tmp); // take
        tmp.pop_back();
        solve(s, i + 1, st, cnt, tmp); // nt take
    }

    vector<string> removeInvalidParentheses(string s) {
        int cnt = 0;
        set<string> st; // since there may be duplicate strings
        string tmp = "";

        solve(s, 0, st, cnt, tmp);

        return vector<string>(st.begin(), st.end());
    }
};