class Solution {
public:
    long long countCommas(long long n) {
        long long c = 0;
        for (int i = 3; i <= 15; i += 3) {
            long long p = pow(10, i);
            if (n >= p) {
                c += max(n-(p - 1), 0LL);
            }
        }
        return c;
    }
};