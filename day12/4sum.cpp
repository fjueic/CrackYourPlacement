class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums,int tar,int start) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int x=start;x<n-2;x++){
            if(x!=start&&nums[x]==nums[x-1])continue;
            int i=x+1,j=n-1;
            while(true){
                if(i>=j)break;
                if(1LL*nums[x]+nums[i]+nums[j]==tar){
                    ans.push_back(vector<int>{nums[x],nums[i],nums[j]});
                    i++;j--;
                    while(i< j && nums[i]==nums[i-1])i++;
                    while(i< j && nums[j]==nums[j+1])j--;
                }else if(1LL*nums[x]+nums[i]+nums[j]<tar){
                    i++;
                }else j--;
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int x=0;x<n-3;x++){
            if(x!=0&&nums[x]==nums[x-1])continue;
            vector<vector<int>> cal=threeSum(nums,target-nums[x],x+1);
            for(auto i:cal){
                i.insert(i.begin() , nums[x]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};
