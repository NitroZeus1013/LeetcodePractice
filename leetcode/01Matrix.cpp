/*
 * This approach is desined by me. Doesn't work for some cases.
 * The same approach with some tweaks works for all the cases but gives TLE.
 class Solution {
public:
    bool isInside(int r, int c, int n ,int m){
       
        return r>=0 and r<n and c>=0 and c<m;
    }
        
    int dfs(int row ,int col ,int n ,int m,vector<vector<int>>&ans,vector<vector<int>>&mat,vector<vector<int>>&vis){
  
       
        // cout<<row<<" "<<col<<endl;
       
        if(ans[row][col]!=0)return ans[row][col]+1;
        vis[row][col] = 1;
        int val  = 99999;   
   vector<pair<int,int>>directions = {{-1,0},{0,1},{1,0},{0,-1}};
       
        for(pair<int,int>dir:directions){
        
                    int nextRow = row+dir.first;
                    int nextCol = col+dir.second;
                
             if(isInside(nextRow,nextCol,n,m) and ans[nextRow][nextCol] !=0){
               val = min(val, ans[nextRow][nextCol]+1);
            }    
            
            else if(isInside(nextRow,nextCol,n,m) and vis[nextRow][nextCol] == 0){
               
                        if(mat[nextRow][nextCol] == 1){
                             val =min(val,1+dfs(nextRow,nextCol,n,m,ans,mat,vis));
                        }else if(mat[nextRow][nextCol] == 0){
                             return ans[row][col] = 1;
                             
                        }
                        
            }
           
            
                }
        // vis[row][col] = 0;
        ans[row][col] = val;
        return val;
   
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     
        int n = mat.size();
        int m = mat[0].size();
 
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                
                if(mat[i][j] == 1 and vis[i][j] == 0){
                     
                     ans[i][j] = dfs(i,j,n,m,ans,mat,vis);
                     vis[i][j] = 1;
                }
            }
        }
        
        return ans;
    }
};
*/
