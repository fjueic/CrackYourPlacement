class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0,n=heights.size();
        stack<pair<int,int> >s;
        for(int i =0;i<n;i++){
            if(s.empty() || s.top().first<=heights[i]){
                s.push({heights[i],i});
            }else{
                int ele=heights[i],ind=i;
                while(!s.empty() && s.top().first>heights[i]){
                    pair<int,int> t= s.top();s.pop();
                    ans=max(ans,(i-t.second)*t.first);
                    ind=t.second;
                }
                s.push({ele,ind});
            }
        }
        while(!s.empty()){
            pair<int,int> t=s.top();
            ans=max(ans,t.first*(n-t.second));
            s.pop();
        }
        return ans;
    }
};
