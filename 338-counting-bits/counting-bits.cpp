class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        if(n==1) return {0,1};

        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i&(i-1)]+1;
        }
        return dp;
    }
};