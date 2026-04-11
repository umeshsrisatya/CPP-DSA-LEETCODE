class Solution {
private:
    int absolute(vector<int>& v) {
        int distance = INT_MAX;
        sort(v.begin(),v.end());
        int n = v.size();
        for (int i = 0; i < n-2; i++) {
            int a = v[i];
            int b = v[i+1];
            int c = v[i+2];
            distance = min(distance, abs(a-b)+ abs(b-c)+ abs(c-a));
        }
        return distance;
    }

public:
    int minimumDistance(vector<int>& nums) {
        map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        map<int, vector<int>> indexes;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (freq[nums[i]] >= 3) {
                indexes[nums[i]].push_back(i);
            }
        }
        if (indexes.size() == 0)
            return -1;

        int mini = INT_MAX;
        for (auto i : indexes) {
            vector<int> v = i.second;
            int dist = absolute(v);
            mini = min(dist, mini);
        }
        return mini;
    }
};