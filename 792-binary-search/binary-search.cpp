class Solution {
private:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(low>high) return -1;
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>target) return binarySearch(nums,target,low,mid-1);
        if(nums[mid]<target) return binarySearch(nums,target,mid+1,high);
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)return 0;
        return binarySearch(nums,target,0,nums.size()-1);
    }
};