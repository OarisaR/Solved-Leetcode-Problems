/*
- t.len > s.len since it has an extra character in any pos
- initial thought is bitwise xor.
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        // map the string to numbers
        int num = 0;
        for (char c : s)
            num ^= c;
        for (char c : t)
            num ^= c;

        cout << num << endl;
       return (char)num;
    }
};