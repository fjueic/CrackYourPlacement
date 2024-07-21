class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line,ans;
        int l=0;
        for(int i=0;i<words.size();i++){
            if(l!= 0 && l+words[i].size()+1>maxWidth){
                string t=line[0];
                int totalspaces=line.size()-1+maxWidth-l;
                int p=line.size()-1;
                for(int j=1;j<line.size();j++){
                    t+=string(totalspaces/p+(j<=(totalspaces%p)),' ')+line[j];
                }
                t+=string(maxWidth-t.size(),' ');
                ans.push_back(t);
                line.clear();
                l=0;
                i--;
            }else{
                l+=(line.size()!=0)+words[i].size();
                line.push_back(words[i]);
            }
        }
        string t=line[0];
        int totalspaces=line.size()-1+maxWidth-l;
        int p=line.size()-1;
        for(int j=1;j<line.size();j++){
            t+=string(1,' ')+line[j];
        }
        t+=string(maxWidth-t.size(),' ');
        ans.push_back(t);
        return ans;
    }
};
