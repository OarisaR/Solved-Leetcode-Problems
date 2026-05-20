class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int tot = 1 << k ; // total codes = 2*k
        unordered_set<string> st;
        for(int i = k ; i<= s.size() ; i++){
            st.insert(s.substr(i-k,k)) ; // substr -> start idx,sz of substring
            if (st.size() == tot) return true;
        }
        return false;
    }
};