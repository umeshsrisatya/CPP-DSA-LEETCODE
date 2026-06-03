class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, prev = 0;
        int n = nums.size();
        int maxi = 0;
        int majority = nums[0];
        sort(nums.begin(), nums.end());
        for(int i =0; i < n; i++){
            if(i!=0 && prev == nums[i]){
                cnt++;
                if(maxi<cnt){
                    maxi = cnt;
                    majority = nums[i];
                }
            }
            else{
                cnt = 1;
                prev = nums[i];

            }
        }
        return majority;
    }
};