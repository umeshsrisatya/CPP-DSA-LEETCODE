class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int, int> mpp; // to store frequencies of sum;
        //why <= means cbrt(4104) = 16.0104 but int only takes 16 so we need to calculate the a value which cbrt = 0.0104
        int limit = cbrt(n);
        for(int a = 1; a <= limit; a++){ 
            int a3 = a * a * a;

            for(int b = a ; b <= limit; b++){
                int b3 = b * b * b;

                int sum = a3 + b3;
                if(sum > n){
                    break;
                }
                mpp[sum]++;
            }
        }
        vector<int> ans;
        for(auto m : mpp){
            if(m.second >= 2){
                ans.push_back(m.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};