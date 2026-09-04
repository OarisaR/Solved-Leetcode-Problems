/*
Observations :
- sub*k <= n --> sub.len <= n/k
- explore only freq[letter] >= k
- check if sub*k is subsequence of string s
- find all possible such sub
- however, concatenating sub and checking again and again is a waste.
- so, cleverly find if sub is present k times in string s

*/

class Solution {
public:
    string res = "";
    bool isSubseq(string& s, string& curr, int k) {
        // check if curr  is present k times in s
        int i = 0;
        int j = 0;
        int l = curr.size(); // substr size
        int n = s.size();
        while (i < n && j < k * l) {
            if (s[i] == curr[j % l]) {
                // j%l because "letlet" no need to check all, just "let" and go
                // back to beginning hence we do modulo
                j++; // found so move
            }
            i++;
        }
        return j == k * l; // reached end then true!
    }
    bool backtrack(string& s, string& curr, vector<bool>& canuse,
                   vector<int>& req, int k, int mx) {
        if (curr.size() == mx) {
            if (isSubseq(s, curr, k)) {
                res = curr; // blind assign because we handled the largest one and lexico greater one
                return true;
            }
            return false;
        }

        // generate more
        for (int i = 25; i >= 0; i--) {
            // starting from reverse will enable to find the larger one first
            if (canuse[i] == false || req[i] == 0)
                continue;
            // take
            char ch = i + 'a';
            curr.push_back(ch);
            req[i]--;

            // explore
            if(backtrack(s, curr, canuse, req, k, mx)) return true;

            // undo
            curr.pop_back();
            req[i]++;
            
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int freq[26] = {};
        int n = s.size();
        for (char& c : s) {
            freq[c - 'a']++;
        }
        vector<bool> canuse(26, false);
        vector<int> req(
            26, 0); // each letter can be used at max this value in each sub
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canuse[i] = true;
                req[i] = freq[i] / k; // atmost this
            }
        }
        int mx = n / k;
        string curr;
        for (int l = mx; l >= 0; l--) {
            vector<int> tempfreq = req;
            if (backtrack(s, curr, canuse, tempfreq, k, l))
                return res;
        }
        return res;
    }
};