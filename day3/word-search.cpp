class Solution {
public:
    bool check(vector<vector<char>>& board, string word,int i,int j,int c){
        if(c==word.size())return 1;
        if(i<0||j<0||i>=board.size()||j>=board[0].size())return 0;
        if(board[i][j]!=word[c])return 0;
        char t=board[i][j];
        board[i][j]='0';
        bool a= check(board,word,i-1,j,c+1)||check(board,word,i,j-1,c+1)||check(board,word,i+1,j,c+1)||check(board,word,i,j+1,c+1);
        board[i][j]=t;
        return a;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(check(board,word,i,j,0))return 1;
            }
        }
        return 0;
    }
};
