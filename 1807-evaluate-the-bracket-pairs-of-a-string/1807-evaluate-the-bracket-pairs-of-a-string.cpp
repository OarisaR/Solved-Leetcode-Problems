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
        
        string res = "";
        while (i < n) {
            if (s[i] == '(') {
                i++;
                string tmp;
                while ( i < n  &&  s[i] != ')' ) {
                    tmp.push_back(s[i]);
                    i++;
                }
                if (s[i] == ')') {
                     auto it = mp.find(tmp);
                    if (it == mp.end())
                        res += q;
                    else
                        res += it->second;

                }
            } else {
                res += s[i];
            }
            i++;
        }
        return res;
    }
};