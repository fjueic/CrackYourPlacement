class Solution {
  public:
    void solve(int i, vector<int> &t, vector<int> &nums,
               vector<vector<int>> &ans) {
        if (i >= nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[i]);
        solve(i + 1, t, nums, ans);
        t.pop_back();
        solve(i + 1, t, nums, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> t;
        solve(0, t, nums, ans);
        return ans;
    }
};
