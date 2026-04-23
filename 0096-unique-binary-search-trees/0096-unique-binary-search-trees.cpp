class Solution {
public:
    // We can simply choose each number as root to create valid BST
    // However, the numbers to the left and right can be arranged differently.
    // so for X nodes -> X arrangements
    // for Y nodes -> Y arrangements
    // Total Possibilities = X * Y
    // Sum across all root choices = answer
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1; // 0 node has 1 possibility = empty tree
        dp[1] = 1;
        for(int i = 2; i <= n ; i++){
            for(int j = 1; j <= i ; j++){
                dp[i] += dp[i-j] * dp[j-1] ; 
                // with j as root
                // j-1 nodes on left side, remaining j+1....i on other side
            }
        }
        return dp[n];
        
    }
};