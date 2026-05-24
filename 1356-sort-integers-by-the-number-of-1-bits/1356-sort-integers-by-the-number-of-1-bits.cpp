/*
- Sort numbers based on the count of 1's in its bin representation
- If the count of two num is equal, sort in ascending.
*/
class Solution {
public:
    int count_of_one(int a) {
        int cnt = 0;
        while (a != 0) {
            cnt += (a & 1);
            a = a >> 1;
            
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        // using lamda
        //  return_type name = [capture_clause](params){};

        // capture clause is able to capture any variable declared outside (by
        // reference, not copy)

        // here & captures all func outside lambda!, without using this , it causes error.
        auto lamda = [&](int &a, int &b) {
            int ca = count_of_one(a);
            int cb = count_of_one(b);
            if (ca == cb)
                return a < b;
            
            return ca < cb;
        };
        sort(arr.begin(), arr.end(), lamda);
        return arr;
    }
};