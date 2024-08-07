class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[1] < b[1];
             });
        int n = intervals.size();
        int ans = 0;
        int end = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            } else {
                ans++;
            }
        }
        return ans;
    }
};
