class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int n = s.size();
        int cnt = 0;
        string tmp = "";
        for (int i = 0; i < n; i++) {
            tmp += s[i];
            cnt = cnt + (s[i] == '(' ? 1 : -1);
            if (cnt == 0) {
                // v.push_back(tmp);
                res += tmp.substr(1, tmp.size() - 2);
                tmp.clear();
            }
        }

        return res;
    }
};