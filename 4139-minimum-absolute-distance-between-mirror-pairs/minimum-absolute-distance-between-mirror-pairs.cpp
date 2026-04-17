class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int mini = INT_MAX;
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            string r = to_string(nums[i]);
            reverse(r.begin(),r.end());
            int reverse = stoi(r);
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[reverse] = i;
            }else{
                mini = min(mini, abs(i - mpp[nums[i]]));
                mpp[reverse] = i ;
            }
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};