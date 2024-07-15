class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int prefix=0,a=0;
        for(int i=0;i<nums.size();i++){
            prefix=((prefix+nums[i])%k+k)%k;
            if(prefix==0)a++;
            if(m.find(prefix)!=m.end()){
                a+=m[prefix];
            }
            m[prefix]++;
        }
        return a;
    }
};
