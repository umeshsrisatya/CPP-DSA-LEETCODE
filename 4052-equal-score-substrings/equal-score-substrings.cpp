class Solution {
public:
    bool scoreBalance(string s) {
        vector<int> arr(s.size());
        int i = 0;
        int sum = 0;
        for(char ch: s){
            sum += ch-'a' +1;
            arr[i] = sum;
            i++;
        }
        int totalScore = arr[s.size()-1];
        for(int i : arr){
            if((i*2) == (totalScore)){
                return true;
            }else if((i*2) >(totalScore)){
                return false;
            }
        }
        return false;
    }
};