class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int make = nums[nums.size() / 2];
        int move = 0;
        for (int i = 0; i < nums.size(); i++) {
            move += abs(nums[i] - make);
        }
        return move;
    }
};