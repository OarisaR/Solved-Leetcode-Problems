/*
- thoughts
- for any number to result a max xor, it would be 1111....  
- when does this actually happen? if all bit pos are exact not of the org one
- how to flip??
- org bit ^ 1111 [mask of that sz] = flipped one
- how to gen mask ? 1 << n - 1 !   e.g : for n=3,  8-1 = 7 = 111

*/
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(); // 4
        vector<int> res(n,0);
        int tot = 0;
        for(int i = 0; i < n ; i++) tot^=nums[i]; // 3
        
        int mask = (1 << maximumBit) - 1;
        for(int i = 0; i < n ; i++){
        
            res[i] = tot ^ mask ; //
            tot^=nums[n - i  - 1]; // 3 ^ 3 = 00
        }
        return res;
    }
};