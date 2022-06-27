class Solution {
public:
    bool inside(int r, int c, int n ,int m){
        return r>=0 and r<n and c>=0 and c<m;
    }
    void bfs(vector<vector<char>>&grid,int s ,int e,int n ,int m){

         queue<pair<int,int>>q;
         q.push({s,e});
         grid[s][e] = '2';
         vector<pair<int,int>>directions = {{-1,0},{0,1},{1,0},{0,-1}};
         while(!q.empty()){
             pair<int,int>curr = q.front();
             q.pop();
             for(pair<int,int>dir:directions){
                 int row = curr.first+dir.first;
                 int col = curr.second+dir.second;
                if(inside(row,col,n,m)and grid[row][col]=='1'){
                 grid[row][col] = '2';
                 q.push({row,col});
                }
             }
           
           
            
             
         }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        int i =0 ,j =0;
        int count = 0;
        //iterate over all the elements and mark all the reachable elements from that land i.e. '1'
        // more formally if you got the land then mark all the land reachable from there ,(ans++)
        //and when you've no more reachable land try find another piece of land and mark it as well.
        for(int i =0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    count++;
                    bfs(grid,i,j,n,m);
                }
            }
        }
        
       
        return count;
        
    }
};
/*
 class Solution {
public:
    bool isInside(int r ,int c,int n,int m){
        return r>=0 and r<n and c>=0 and c<m;
    }
    void dfs(int row ,int col,vector<vector<char>>&grid,int n ,int m){
        grid[row][col] = '2';//marking as visited
        
        vector<pair<int,int>>directions = {{-1,0},{0,1},{1,0},{0,-1}};
        for(pair<int,int>dir:directions){
            int r = row+dir.first;
            int c = col+dir.second;
            if(isInside(r,c,n,m) and grid[r][c]=='1'){
                dfs(r,c,grid,n,m);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0 ;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        
        return count;
    }
};
 */
