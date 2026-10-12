class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < n ; i++) {
            if (s[i] == '(')
                cnt++;
            else {
                if (cnt > 0) {
                    // did we even have any opening bracket
                    cnt--;
                } else
                    res++; // if not we need to add one (
                
               if ( i + 1 < n && s[i+1] == ')')  {
                    i ++; // the loops i++, would count it i+=2 in total, so the )) are treated as one unit
                } else
                    res++;
            
            }
        }
        // if(cnt!) {
        //     // means some open bracket remains, so we need two closing bracket for each
        //     res+=cnt*2;
        // }
        return res+cnt*2;
    }
};