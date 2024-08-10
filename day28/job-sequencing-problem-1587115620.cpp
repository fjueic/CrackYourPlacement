class Solution {
  public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        // your code here
        sort(arr, arr + n,
             [](Job a, Job b) -> bool { return a.profit > b.profit; });
        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, arr[i].dead);
        }
        vector<int> ans(m + 1, 0);
        for (int i = 0; i < n; i++) {
            int t = arr[i].dead;
            while (t > 0 && ans[t] != 0)
                t--;
            if (t != 0) {
                ans[t] = arr[i].profit;
            }
        }
        int fre = 0;
        int a = 0;
        for (int i : ans) {
            if (i != 0) {
                fre++;
                a += i;
            }
        }
        return vector<int>{fre, a};
    }
};
