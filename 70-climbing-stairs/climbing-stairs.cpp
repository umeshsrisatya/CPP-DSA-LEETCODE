class Solution {
private:
    int fun(int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return 1;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        // jump one step;
        if(dp[n-1] == 0){
            dp[n-1] = fun(n-1, dp);
        }
        // jump two step;
        if(n>=2){
            if(dp[n-2] == 0){
                dp[n-2] = fun(n-2, dp);
            }
        }
               
        dp[n] = dp[n-1]+ dp[n-2];
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        return fun(n, dp);
    }
};