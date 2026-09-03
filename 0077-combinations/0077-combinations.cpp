/*
- a backtracking problem
- k numbers from [1,n]
*/

class Solution {
public:
    vector<vector<int>> comb;
    void back(int &n, int k, int i, vector<int>& vec) {
        // base case

        if (k == 0) {
            comb.push_back(vec);
            return;
        }

        for (int j = i; j <= n; j++) {
            vec.push_back(j);
            back(n, k - 1, j + 1, vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        back(n, k, 1, vec);
        return comb;
    }
};