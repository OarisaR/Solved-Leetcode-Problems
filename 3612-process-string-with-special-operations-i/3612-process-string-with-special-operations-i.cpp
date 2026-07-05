class Solution {
public:
    string processStr(string s) {
        string res = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (islower(s[i]))
                res += s[i];
            if (s[i] == '*') {
                if (res != "")
                    res.pop_back();
            }
            if (s[i] == '#') {
                res += res;
            }
            if (s[i] == '%') {
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};