class Solution {
private:
    int dp[301][7][7][7][7];
    int dist(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y2 - y1);
    }
    pair<int, int> getCoOrdinates(char c) {
        int rc = c - 'A';
        return {rc / 6, rc % 6};
    }
    int solve(string& word, int i, int x1, int y1, int x2, int y2) {
        if (i >= word.size()) {
            return 0;
        }
        if (dp[i][x1 + 1][x2 + 1][y1 + 1][y2 + 1] != -1)
            return dp[i][x1 + 1][x2 + 1][y1 + 1][y2 + 1];
        // lets find the co-ordinates of a char;
        auto [x, y] = getCoOrdinates(word[i]);

        // both f1, f2 are not used, tasking first finger
        if (x1 == -1 && y1 == -1 && y2 == -1 && x2 == -1) {
            return dp[i][x1 + 1][x2 + 1][y1 + 1][y2 + 1] =
                       0 + solve(word, i + 1, x, y, x2, y2);
        }
        // both  f2 is not used
        if (x2 == -1 && y2 == -1) {
            // if f2 not used
            int f2 = 0 + solve(word, i + 1, x1, y1, x, y);
            // if f2 not used but i want to use f1 again
            int f1 = dist(x1, y1, x, y) + solve(word, i + 1, x, y, x2, y2);

            return dp[i][x1 + 1][x2 + 1][y1 + 1][y2 + 1] = min(f2, f1);
        }
        // if both are used
        int f1 = dist(x1, y1, x, y) + solve(word, i + 1, x, y, x2, y2);

        int f2 = dist(x2, y2, x, y) + solve(word, i + 1, x1, y1, x, y);

        return dp[i][x1 + 1][x2 + 1][y1 + 1][y2 + 1] = min(f2, f1);
    }

public:
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        int indx = 0;
        int x1, x2, y1, y2;
        x1 = x2 = y1 = y2 = -1;

        return solve(word, indx, x1, y1, x2, y2);
    }
};