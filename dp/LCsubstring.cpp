#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<set>
#include<list>
#include<stack>
using namespace std;

int dp[1001][1001];
//bottom up dp
int LCsubstring(string x,string y , int m , int n){

	for(int i = 0 ;i<n+1;i++){
		dp[i][0] = 0;
	}

	for(int j = 0 ;j<m+1;j++){
		dp[0][j] = 0;
	}

	for(int i = 1;i<m+1;i++){
		for(int j = 1;j<n+1;j++){

			if(x[i-1] == y[j-1]){

				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = 0 ;
			}

		}
	}

	int maxLen = -1;
	for(int i = 0;i<m+1;i++){
		for(int j = 0;j<n+1;j++){
			maxLen =max(maxLen,dp[i][j]);
		}
	}

	return maxLen;
}


int main(){
	
	cout<<LCsubstring("abcef","abaxy",5,5);
		cout<<endl;
		for(int i = 0 ;i<6;i++){
	for(int j = 0 ;j<6;j++){
		cout<<dp[i][j]<<"_|_";
		
	}
		cout<<'\n';
	}

return 0;
}