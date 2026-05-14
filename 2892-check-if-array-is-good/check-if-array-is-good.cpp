class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size()==1)return false;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int prev = nums[0];
        for(int i = 1; i < n-1; i++){
            if(prev == nums[i]){
                return false;
            }
            prev = nums[i];
        }
        if(nums[n-1]==nums[n-2] && nums[n-1] == n-1){
            return true;
        }
        return false;
    }
};