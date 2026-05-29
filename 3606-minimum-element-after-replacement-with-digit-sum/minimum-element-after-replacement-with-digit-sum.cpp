class Solution {
private:
    int sumOfDigits(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            mini = min(sumOfDigits(nums[i]), mini);
        }
        return mini;
    }
};