class Solution {
public:
    int dp[1001] = {0};
    int solve(int i,int n,vector<int>&cost){
        // if you are already on top of the floor
        if(i >= n)return 0;
        if(dp[i]!=0)return dp[i];
        //pick i+1 
        int f = solve(i+1,n,cost);
        // come back pick i+2
        int s = solve(i+2,n,cost);

        return dp[i] = cost[i] + min(f,s);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // this is new kind of pattern for me 
        // here we make two calls for helper/solve function in main function
        // why??
        // because in usual cases we always start with 0th or last element that means 
        // unlike in backtracking where we have to come and choose any other option
        //here we know i+1 or i+2 
        // so we can skip Backtracking way
        // and call twice for i+1 and i+2 ,but then we can start from 2 different points , if it was BC then we can choose 1st and then come back and choose 2nd .
        // so instead we do it with two calls in main.

        //here we already decide for 0th element we've taken it and then find the result for i+1 and i+2 
        //*******************
        // like from 0th we've option to skip 1st and go to 2nd , but for 0 itself we dont have any option so we put that option in main 
        return min(solve(0,n,cost),solve(1,n,cost));
    }
};
