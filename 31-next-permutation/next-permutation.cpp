class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int dip = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                dip = i;
                break;
            }
        }
        if (dip == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }

        for (int i = n-1; i > dip; i--) {
            if (arr[dip] < arr[i] ) {
                swap(arr[dip], arr[i]);
                break;
            }
        }
        sort(arr.begin()+dip+1,arr.end());
    }
};