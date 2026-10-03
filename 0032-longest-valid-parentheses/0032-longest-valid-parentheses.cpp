/*
my thoughts:
- keep tracking, and once i find close brackets and when opencount=0, we reach
one valid string, so we keep it as a result
- we do the same moving forward and keep taking the max value
- umm, even a better one is keeping track of close and open brackets, so when
close == open it means we found one valid string.
- but )( is not valid, yet it is open==close, so maybe if close > open at any
time it means that the string is not valid.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0;
        int i = 0;
        int res = 0;

        // left to right
        while (i < n) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (open == close) {
                res = max(res, open + close);
            } else if (close > open) {
                // it means the str is not valid, hence we reset it
                open = 0;
                close = 0;
            }

            i++;
        }
        i = n - 1;
        open=close=0;
        while (i >= 0) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (open == close) {
                res = max(res, open + close);
            } else if (open > close) {
                // it means the str is not valid, hence we reset it
                open = 0;
                close = 0;
            }

            i--;
        }
        // cout << left << " " << right << endl;
        return res;
    }
};