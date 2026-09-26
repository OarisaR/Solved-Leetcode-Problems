class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // for fast lookup map works
        unordered_map<string, string> mp;
        for (auto& vec : knowledge) {
            mp[vec[0]] = vec[1];
        }
        int n = s.size();
        char q = '?';
        int i = 0;
        string tmp;
        string res = "";
        while (i < n) {
            if (s[i] == '(') {
                i++;
                while (s[i] != ')' && i < n) {
                    tmp.push_back(s[i]);
                    i++;
                }
                if (s[i] == ')') {
                    if (mp.find(tmp) == mp.end())
                        res += q;
                    else
                        res += mp[tmp];

                    tmp = "";
                }
            } else {
                res += s[i];
            }
            i++;
        }
        return res;
    }
};