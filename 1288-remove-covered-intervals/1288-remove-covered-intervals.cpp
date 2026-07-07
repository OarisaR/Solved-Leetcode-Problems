class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto lambda = [](vector<int> vec1, vector<int> vec2) {
            if (vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
                // if start is same, we choose the one with farthest endpoint
                // for a longer interval
            }
            return vec1[0] < vec2[0];
        };
        sort(intervals.begin(), intervals.end(), lambda);
        int cnt = 1; // one is always taken.
        int lastEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= lastEnd) {
                continue;
            }
            lastEnd = intervals[i][1]; // new end updated
            cnt++;
        }
        return cnt;
    }
};