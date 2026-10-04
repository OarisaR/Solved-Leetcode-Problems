/*
- valid string here means : normal rules + * as wild card
- by wild card i mean it can be treated as anything whenever needed like how ppl
treats me lol
- so normally keep checking basic validity, and at the end see if there is any
brackets left, so we can balance it out with the stars we have counted, if it is
already balanced then we dont need that, it means we will be treating the star
like an empty string.

- this has an issue, i am not considering the order of the stars
- i saw the first hint, its abt backtracking, lets see now :))
*/

class Solution {
public:
    int dp[101][101];
    bool backtrack(string& s, int i, int balance) {

        // BASE CASE
        if (i == s.size()) {
            if (balance == 0)
                return true;
            return false;
        }

        if (balance < 0) {
            return false;
        }
        if(dp[i][balance]!=-1) return dp[i][balance] ;
        if (s[i] == '(') {
            return backtrack(s, i + 1, balance + 1);
        }

        if (s[i] == ')') {
            return dp[i][balance] =  backtrack(s, i + 1, balance - 1);
        }

        // '*'
        // Three possibilities:
        bool treatLeft = backtrack(s, i + 1, balance + 1);
        bool treatRyt = backtrack(s, i + 1, balance - 1);
        bool treatNone = backtrack(s, i + 1, balance);
        return dp[i][balance] =  treatLeft || treatRyt ||
               treatNone; // if any branch is valid, ,it is true
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return backtrack(s, 0, 0);
    }
};