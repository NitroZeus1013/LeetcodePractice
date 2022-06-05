#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<set>
#include<list>
#include<stack>
#include<cstring>
using namespace std;

//pure recursive approach 
int lcs(string x, string y, int n ,int m){

	//if either of the string is empty;
	if(n == 0 or m == 0)return 0;

	//if the current/last character is equal then we add 1 to the total length and ask recursion find the lcs of rest
	if(x[n-1]==y[m-1]){
		return 1+lcs(x,y,n-1,m-1); // as both of the chars match we'll consider them as processed.
	}else{
		//if the chars don't match then we'll check for the current char in x for all the chars in y and also do the same thing for y.and return max of both choices.
		return max(lcs(x,y,n,m-1),lcs(x,y,n-1,m)) ;

		// "acd" and "ced" // ans = "cd"
		// as both chars at end match we'll add 1 and ask recursion to find the lcs of rest.
		//"ac" and "ce"
		//as both chars don't match it can happen we'll get "e" in rest of the string of x and also it can happen 
		//we'll get "c" in rest of the string in y, so perform both choices and return max of both.
	}
}

int dp[1001][1001];

//memoization or top-down approach

int memo_lcs(string x, string y, int n ,int m){

	//if either of the string is empty;
	if(n == 0 or m == 0)return 0;

	if(dp[n][m]!=-1)
		{	cout<<"in if "<<endl;
			return dp[n][m];

		}
	//if the current/last character is equal then we add 1 to the total length and ask recursion find the lcs of rest
	if(x[n-1]==y[m-1]){
		return dp[n][m] =  1+memo_lcs(x,y,n-1,m-1); // as both of the chars match we'll consider them as processed.
	}else{
		//if the chars don't match then we'll check for the current char in x for all the chars in y and also do the same thing for y.and return max of both choices.
		return dp[n][m] =  max(memo_lcs(x,y,n,m-1),memo_lcs(x,y,n-1,m)) ;

		// "acd" and "ced" // ans = "cd"
		// as both chars at end match we'll add 1 and ask recursion to find the lcs of rest.
		//"ac" and "ce"
		//as both chars don't match it can happen we'll get "e" in rest of the string of x and also it can happen 
		//we'll get "c" in rest of the string in y, so perform both choices and return max of both.
	}
}

// bottom up 

int dp_lcs(string x ,string y, int n, int m){

	for(int i = 0 ;i<n+1;i++){
		dp[i][0] = 0;
	}

	for(int j = 0 ;j<m+1;j++){
		dp[0][j] = 0;
	}

	for(int i = 1;i<n+1;i++){
		for(int j = 1;j<m+1;j++){
			if(x[i-1] == y[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	return dp[n][m];
}


int main(){

	memset(dp,-1,sizeof(dp));
	int n = 5;
	int m = 5;
	// cout<<memo_lcs("ayxt","axzy",4,4);
	cout<<dp_lcs("axyt","axzy",4,4);
	cout<<endl;
	// for(int i = 0 ;i<n;i++){
	// for(int j = 0 ;j<m;j++){
	// 	cout<<dp[i][j]<<"_|_";
		
	// }
	cout<<'\n';


	

return 0;
}