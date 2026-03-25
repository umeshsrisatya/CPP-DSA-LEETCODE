class Solution {
private:
    int maxRange(vector<int>& arr){
        int prev2 = 0;
        int prev = arr[0];

        int n = arr.size();

        for(int i = 1; i < n; i++){
            int take = arr[i] + prev2;
            int not_take = 0 + prev;
            int curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);
        
        vector<int> leavefirst(nums.begin()+1,nums.end());
        vector<int> leavelast(nums.begin(),nums.end()-1);
        return max(maxRange(leavefirst), maxRange(leavelast));
    }
};