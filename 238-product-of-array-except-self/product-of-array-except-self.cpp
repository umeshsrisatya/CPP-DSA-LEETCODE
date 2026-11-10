class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixMul(n, 0);
        vector<int> sufixMul(n, 0);
        int p = 1;
        int s = 1;
        for (int i = 0; i < n; i++) {
            p = p * nums[i];
            s = s * nums[n - 1 - i];
            prefixMul[i] = p;
            sufixMul[n - 1 - i] = s;
        }
        vector<int> ans(n, 0);
        ans[0] = sufixMul[1];
        ans[n - 1] = prefixMul[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = prefixMul[i - 1] * sufixMul[i + 1];
        }
        return ans;
    }
};