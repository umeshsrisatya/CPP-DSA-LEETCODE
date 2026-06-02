class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        for (int i = m + n - 1; i >= 0; i--) {
            if (m == 0)
                n1[i] = n2[--n];
            else if (n == 0)
                return;
            else if (n1[m - 1] >= n2[n - 1])
                n1[i] = n1[--m];
            else
                n1[i] = n2[--n];
        }
    }
};