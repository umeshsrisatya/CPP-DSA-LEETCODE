class Solution {
private:
    int reverse(int num){
        int temp =0;
        while(num>0){
            int ld = num%10;
            temp = (temp*10) +ld;
            num = num / 10;
        }
        return temp;
    }
public:
    int mirrorDistance(int n) {
        // |25 - 52| = 27
        // |10 - 01| = 9
        // |7 - 7| = 0
        return abs(n - reverse(n));
    }
};