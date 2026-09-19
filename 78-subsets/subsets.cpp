class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& ans, int indx, vector<int>& arr){
        if(indx>=nums.size()){
            ans.push_back(arr);
            return ;
        }
        // take 
        arr.push_back(nums[indx]);
        solve(nums,ans,indx+1,arr);
        // not take 
        arr.pop_back();
        solve(nums,ans,indx+1,arr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> ans;
        solve(nums,ans,0,arr);
        return ans;
    }
};