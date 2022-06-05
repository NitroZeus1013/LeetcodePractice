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


int dp[1001][1001] = {{0}};

string printLCS(string x,string y ,int n ,int m){

	string ans = "";
	for(int i = 1;i<n+1;i++){
		for(int j =1;j<m+1;j++){
			if(x[i-1] == y[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}

		}
	}

	int i=n,j=m;

	while(i>=0 and j>=0){

			if(x[i-1]==y[j-1]){
				ans.push_back(x[i-1]);
				i--;
				j--;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					ans.push_back(x[i-1]); // this lines are for shortest super sequence
					i--;
				}else{
					ans.push_back(y[j-1]); //this lines are for shortest super sequence
					j--;
				}
			}
	}
	//this lines are for shortest super sequence
	while(j>=0){
		ans.push_back(y[j-1]);
		j--;
	}

	while(i>=0){
		ans.push_back(x[i-1]);
		i--;
	}

	reverse(ans.begin(),ans.end());
	return ans;

}



int main(){
		
	string x = "abac";
	string y = "cab";

	int n = x.length();
	int m = y.length();

	cout<<printLCS(x,y,n,m);

return 0;
}
