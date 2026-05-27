/*
- special character means which has both lowercase and uppercase
- and lowercase appears first!
- so all lowercase must appear to the left of first uppercase
- so find first occurence of uppercase letter
 - find last occurence of lowercase
 - if upper one > lower  = then cnt++;
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        vector<int> firstupp(26, -1);
        vector<int> lastlow(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                lastlow[word[i] - 'a'] = i;
            } else {
                if (firstupp[word[i] - 'A'] == -1) {
                    firstupp[word[i] - 'A'] = i;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (firstupp[i] != -1 && lastlow[i] != -1 &&
                firstupp[i] > lastlow[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};