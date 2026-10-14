/*
- for maximum score, better to take square of larger numbers
- place larger nums in left as we need a max val
- if sum <= 9 putting the remaining sum into the leftmost digit and filling the
other positions with zeros.
- for 'nums' digits, max value can be '9' placed in those pos. lets say for n =
2, 99. so sum is 18 . it cant exceed this ever.
*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return ""; // no valid num
        string res(num,0);
        for(int i = 0; i < num ; i++){
            if(sum == 0) res[i] = '0';
            if (sum > 9) {
                sum -= 9;
                res[i] = '9';

            } else {
                char sumstr = sum + '0';
                res[i] = sumstr;
                sum = 0; // we took the entire sum;
            }
        }
        return res;
    }
};