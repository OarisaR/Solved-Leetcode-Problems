/*
- FOR 4 DIGIT --> 1 COMMA , EG. 1,000
- FOR 5 DIGIT --> 1 COMMA E.G 24,000
- FOR 6 DIGIT --> 1 COMMA E.G. 324,000 ---> 1,000 - 324,000 ; 325000 zeroes!
*/


class Solution {
public:
    int countCommas(int n) {
        // count any remainder
        if(n < 1000) return 0;


        int rem = n % 1000; // 19
        n-=rem; // 2000

        // answer is remainder + n + 1
        return (n - 1000) + 1 + rem;
    }
};