class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int x=0;x<n-2;x++){
            if(x!=0&&nums[x]==nums[x-1])continue;
            int i=x+1,j=n-1;
            while(true){
                if(i>=j)break;
                if(nums[x]+nums[i]+nums[j]==0){
                    ans.push_back(vector<int>{nums[x],nums[i],nums[j]});
                    i++;j--;
                    while(i< j && nums[i]==nums[i-1])i++;
                    while(i< j && nums[j]==nums[j+1])j--;
                }else if(nums[x]+nums[i]+nums[j]<0){
                    i++;
                }else j--;
            }
        }
        return ans;
    }
};
