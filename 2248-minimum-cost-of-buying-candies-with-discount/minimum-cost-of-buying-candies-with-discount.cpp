class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int cnt = 0;
        int purchased = 0;
        int n = cost.size();
        for(int i = n-1; i >= 0; i--){
            if(purchased == 2){
                purchased = 0;
                continue;
                // ignore 
            }
            else if(purchased <2){
                purchased++;
                cnt+=cost[i];
            }
        }
        return cnt;
    }
};