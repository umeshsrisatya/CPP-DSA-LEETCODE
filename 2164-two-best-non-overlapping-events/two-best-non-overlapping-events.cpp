class Solution {
public:
    vector<int> nextInt;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& events, int k, int indx, int n) {
        if (indx >= n || k == 0) {
            return 0;
        }

        if (dp[indx][k] != -1) {
            return dp[indx][k];
        }

        // Take
        int nextIndx = nextInt[indx];

        int takeSum = events[indx][2] + solve(events, k - 1, nextIndx, n);

        // Not Take
        int notTakeSum = solve(events, k, indx + 1, n);

        return dp[indx][k] = max(takeSum, notTakeSum);
    }

    int nextIntervalStart(vector<vector<int>>& intervals, int endPoint) {
        int low = 0;
        int high = intervals.size() - 1;
        int ans = intervals.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (intervals[mid][0] <= endPoint) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        // Sort by start time
        sort(events.begin(), events.end(),
             [](const auto& a, const auto& b) { return a[0] < b[0]; });

        nextInt.resize(n, -1);

        // Find next non-overlapping event for every event
        for (int i = 0; i < n; i++) {
            nextInt[i] = nextIntervalStart(events, events[i][1]);
        }

        int k = 2;

        dp.assign(n, vector<int>(k + 1, -1));

        return solve(events, k, 0, n);
    }
};