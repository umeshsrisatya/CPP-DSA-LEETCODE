class NumArray {
public:
    vector<int> nums;
    vector<int> pleft;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        vector<int> lsum(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            lsum[i] = sum;
        }
        
        this->pleft = lsum;
    }

    int sumRange(int left, int right) {
        if(left == 0){
            return pleft[right];
        }
        return pleft[right]-pleft[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */