class Solution {
public:
    bool checkString(string s) {
        string tmp = s;
        sort(s.begin(),s.end());
        return tmp == s;
    }
};