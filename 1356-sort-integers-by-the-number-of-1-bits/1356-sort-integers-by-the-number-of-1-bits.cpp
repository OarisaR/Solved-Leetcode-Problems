/*
- Sort numbers based on the count of 1's in its bin representation
- If the count of two num is equal, sort in ascending.
*/
class Solution {
public:
   static bool cmp(int a, int b) {
    int ca = __builtin_popcount(a);
    int cb = __builtin_popcount(b);

    if (ca == cb)
        return a < b;   // ascending when popcounts are equal

    return ca < cb;     // fewer set bits comes first
}
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }   
};