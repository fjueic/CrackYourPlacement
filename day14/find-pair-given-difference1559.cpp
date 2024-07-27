class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        unordered_set<int> m;
        for(int i:arr){
            if(m.find(x+i)!=m.end() || m.find(i-x)!=m.end())return 1;
            m.insert(i);
        }
        return -1;
    }
};

