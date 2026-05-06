class NumArray {
public:
     vector<int> pre_sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre_sum.resize(n);
        pre_sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre_sum[i] = pre_sum[i-1]+nums[i];
        }
    }
    int sum = 0;
    int sumRange(int left, int right) {
        if(left == 0){
            return pre_sum[right];
        }
        
        return pre_sum[right]-pre_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */