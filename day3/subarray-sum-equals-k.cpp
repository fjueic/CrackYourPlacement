class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int p=0;
        int a=0;
        for(int i:nums){
            p+=i;
            if(p==k)a++;
            if(m.find(p-i)!=m.end()){
                a+=m[p-k];
            }
            m[p]++;
        }
        return a;
    }
};
