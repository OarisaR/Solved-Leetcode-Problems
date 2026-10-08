class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {

                if (cnt > 0)
                    res += s[i]; // it means the pointer is at the mid way somewhere as if cnt==0 it means it is either at the first or last letter.
                cnt++;
            } else {
                cnt--;
                if (cnt > 0)
                    res += s[i];
             
            }
        }

        return res;
    }
};