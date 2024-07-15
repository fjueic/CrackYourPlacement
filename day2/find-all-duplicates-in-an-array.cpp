class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int>s,ans;
        vector<int> a;
        for(int i:nums){
            if(s.find(i)!=s.end()){
                if(ans.find(i)==ans.end()){
                    a.push_back(i);
                    ans.insert(i);
                }
            }else{
                s.insert(i);
            }
        }
        return a;
    }
};
