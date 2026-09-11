class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> s;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (digits[i] == 0)
                    break;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k)
                        continue;
                    if (digits[k] % 2 == 0) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        s.insert(num);
                    }
                }
            }
        }
        return s.size();
    }
};