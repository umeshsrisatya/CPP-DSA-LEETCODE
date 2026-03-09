class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int f = 0;
        int r = 0;
        int n = nums.size();
        while(r<n){
            if(nums[f] != nums[r]){
                f++;
                nums[f] = nums[r];
            }
            r++;
        }
        return f+1;
    }
};