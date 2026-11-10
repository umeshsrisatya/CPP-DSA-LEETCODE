class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int f = 0;
        int l = n-1;
        int maxWater = INT_MIN;
        while(f<l){
            int totalWater = min(height[f],height[l]) * (l-f);

            if(height[f] < height[l]){
                f++;
            }else{
                l--;
            }

            maxWater = max(totalWater, maxWater);
        }
        return maxWater;
    }
};