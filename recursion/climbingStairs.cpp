class Solution {
public:
    int dp[100] = {0};
    int solve(int i, int &n){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=0)return dp[i];
        // for any current i the result of the both function sum is the answer
        // so if we are trying to recalculate the number of ways from some stair i
        // and if it is already calcualted as we can see the from 0 , 
        // 2 will be reached by 0+1+1 and 0+2 so at 2 this solve calls will go 
        // once for 0+1+1 steps and again for 0+2 steps so don't do same task again. 
        return dp[i] = solve(i+1,n) + solve(i+2,n);
    }
    int climbStairs(int n) {
        return solve(0,n);
    }
};

