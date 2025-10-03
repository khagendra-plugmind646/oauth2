class Solution {
public:
    vector<vector<int>> dp;
    
    int burst(vector<int>& nums, int i, int j) {
        if (i+1 == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int minCoins = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int coins = nums[i] * nums[k] * nums[j]
                        + burst(nums, i, k)
                        + burst(nums, k, j);
            if (k == i + 1) {
                minCoins = coins;
            } else {
                minCoins = min(minCoins, coins);
            }
        }

        return dp[i][j] = minCoins;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n < 3) return 0;
        
        // Initialize DP table
        dp.assign(n, vector<int>(n, -1));
        
        return burst(values, 0, n - 1);
    }
};
