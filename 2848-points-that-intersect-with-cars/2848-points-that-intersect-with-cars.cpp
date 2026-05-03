class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        // line sweep method --> reacts only on start and end points

        // STEP 1: create events vector with start, +1 and end, -1
        vector<pair<int, int>> events;
        for (auto& num : nums) {
            events.push_back({num[0], +1});
            events.push_back({num[1] + 1, -1});
        }

        // STEP 2 : Sort based on the first point
        sort(events.begin(), events.end());
        // [(1,+1),(3,+1),(4,+1),(6),-1),(7,-1),(8,-1)];

        int curr = 0;
        int prev = events[0].first; // 1
        int ans = 0;
        for (auto& e : events) {
            int tmp = e.first;
            if (curr > 0) {
                // at least one car present
                ans += (tmp - prev);
            }
            curr += e.second;
            prev = tmp;
        }
        return ans;
    }
};