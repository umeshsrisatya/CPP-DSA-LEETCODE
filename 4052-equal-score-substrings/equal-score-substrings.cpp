class Solution {
public:
    bool scoreBalance(string s) {
        int i = 0;
        int sum = 0;
        for(char ch: s){
            sum += ch-'a' +1;
        }
        int prefixSum = 0;
        for(char ch: s){
            prefixSum += ch-'a' +1;
            if(prefixSum *2 == sum) return true;
            else if (prefixSum *2 > sum) return false;
        }
        return false;
    }
};