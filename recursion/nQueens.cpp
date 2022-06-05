class Solution {
public:
    
    // in this type of recursion/backtracking you'll either hit base cond or exhaust all the possibilities
    // you're almost guaranteed to have at least one  solution or no solution.
    void solve(int index ,int n,vector<string>&board,vector<int>&leftRow,vector<int>&rightUpDiag,vector<int>&rightDownDiag,vector<vector<string>>ans){
        if(index == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0 ;row<n;row++){
            
            if(leftRow[row] == 0 and rightUpDiag[(n-row)+col] == 0 and rightDownDiag[row+col] == 0){
                leftRow[row] = 1 ;
                rightUpDiag[(n-row)+col] =1;
                rightDownDiag[row+col] =1 ;
                board[row][col] = 'Q';
                solve(index+1,n,board,leftRow,rightUpDiag,rightDownDiag,ans);
                board[row][col]= '.';
                leftRow[row] = 0 ;
                rightUpDiag[(n-row)+col] =0;
                rightDownDiag[row+col] =0;
            }
            
            
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<int>leftRow(n,0); // to check whether there is already a queen to the left  in the current row
        vector<int>rightUpDiag(2*n-1,0); // there will be 2*n-1 positions combined for all the positions
        vector<int>rightDownDiag(2*n-1,0);
        vector<string>board;
        string s(n,'.');
        for(int i = 0;i<n;i++){
            board.push_back(s);
        }
        
        vector<vector<string>>ans;
        
        
        solve(0,n,board,leftRow,rightUpDiag,rightDownDiag,ans);
        return ans;
    }
};