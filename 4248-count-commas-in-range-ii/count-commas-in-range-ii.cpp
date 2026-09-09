class Solution {
public:
    long long countCommas(long long n) {
        long long c = 0;
        if (n > 999999999999999)
            c+=max(n - 999999999999999, 0LL);
        if (n > 999999999999)
            c+=max(n - 999999999999, 0LL);
        if (n > 999999999)
            c+=max(n - 999999999, 0LL);
        if (n > 999999)
            c+=max(n - 999999, 0LL);
        if (n > 999)
            c+=max(n - 999, 0LL);
        return c;
    }
};