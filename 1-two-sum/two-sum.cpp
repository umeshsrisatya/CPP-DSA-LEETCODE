class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp; // need , index
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                auto it =  mp.find(nums[i]) ;
                return {i,it->second};
            }else{
                mp.insert({target-nums[i], i});
            }
        }
        return{-1,-1};
    }
};