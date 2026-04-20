class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = INT_MIN;
        int first = 0;
        int last = n-1;
        while(first <= last){
            if(colors[first] != colors[last]){
                maxi = max(maxi, abs(first-last));
                break;
            }
            if(colors[first] == colors[last]){
                first++;
            }
        }
        first = 0;
        last = n-1;
        while(first <= last){
            if(colors[first] != colors[last]){
                maxi = max(maxi, abs(first-last));
                break;
            }
            if(colors[first] == colors[last]){
                last--;
            }
        }
        return maxi;
    }
};