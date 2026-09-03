/*
- a backtracking problem
- k numbers from [1,n]
*/

class Solution {
public:
    vector<vector<int>> comb;
    void back(int n, int k, int i, vector<int>& vec) {
        // base case

        if (k == 0) {
            comb.push_back(vec);
            return;
        }
        if (i > n)
            return;
        // take
        vec.push_back(i);
        back(n, k - 1, i + 1, vec);

        // not take
        vec.pop_back();
        back(n, k, i + 1, vec);
    }
    vector<vector<int>> combine(int n, int k) {
        int i = 1;
        vector<int> vec;
        back(n, k, i, vec);
        return comb;
    }
};