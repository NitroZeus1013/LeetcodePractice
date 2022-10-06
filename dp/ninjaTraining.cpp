
int solve(int day , int last, vector<vector<int>>&points,vector<vector<int>>&dp){
    // on last day you don't have to anything to decide for future so choose max from available options
    if(day == 0){
        int maxi = 0;
        for(int i =0 ;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    // if on this day == day , we've already performed the activity last and we know the ans then just return it.
    if(dp[day][last] != -1){
        return dp[day][last];
    }
    int maxi = 0 ;
    // for current day you've to try all possible options available i.e. except what you've performed on last day. 
    // why not max for this days also , because if took max on current day for taks1 and next day you've greater reward for the same task1 then you'll lose it.
    // so try all possible for current day.
    // you cannot just try to take only one decision for current day and move on , may be if you've taken some other decision , the end result in future would be better.
    // may be maine kal 2nd task kiya hota to aaj situation kuch aur hoti.
    for(int i = 0 ;i<3;i++){
        if(i!=last){
            int pointsForDay = points[day][i]+solve(day-1,i,points,dp);
            maxi = max(maxi,pointsForDay);
        }
    }
    
    //dp[day][last] says if I performed the taks === last on the prev day of day then maxi is the optimal ans.
    return dp[day][last] = maxi;
    
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve(n-1,3,points,dp);
}
