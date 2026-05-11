/*
- we must find overlapping ballons to kill them with one arrow.
-If current balloon overlaps with window → shrink the window
If it doesn't overlap → shoot a new arrow, reset window to current balloon
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int arrows = 1;
        int currend = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] <= currend) {
                // overlaps -> adjust window
                currend = min(currend, points[i][1]);

            } else {
                // does not overlaps
                arrows++; // new arrow
                // new window.
                currend = points[i][1];
            }
        }
        return arrows;
    }
};