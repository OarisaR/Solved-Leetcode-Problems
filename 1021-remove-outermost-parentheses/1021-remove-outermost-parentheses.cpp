class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> v;
        int n = s.size();
        int cnt = 0;
        string tmp = "";
        for (int i = 0; i < n; i++) {
            tmp += s[i];
            cnt = cnt + (s[i] == '(' ? 1 : -1);
            if (cnt == 0) {
                v.push_back(tmp);
                tmp.clear();
            }
        }
        string res = "";

        for (int i = 0; i < v.size(); i++) {
            string s = v[i];
            res += s.substr(1, s.size() - 2);
        }
        return res;
    }
};