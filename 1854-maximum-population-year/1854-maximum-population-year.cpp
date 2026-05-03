class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        // Difference array technique

        // creation of diff array
        vector<int> diff(2051, 0);
        for (int i = 0; i < logs.size(); i++) {
            int start = logs[i][0];
            int end = logs[i][1] - 1; // as person is counted within [birth, death - 1]

            // core concepts
            diff[start] += 1;
            diff[end + 1] -= 1;
        }

        // cumulative sum
        // [2000,2010] ; start = 2000, end = 2009
        // if there is 1 in 2000 and 1 in 2010 in prefix sum it becomes 1 1 1 1
        // 0 ..... there remains 0 in death
        int yr = 0;
        int mx = 0;
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
            if (diff[i] > mx) {
                yr = i;
                mx = diff[i];
            }
        }
        return yr;
    }
};