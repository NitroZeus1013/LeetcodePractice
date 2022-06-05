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

// top-down
int dp[101][101];
int count(int arr[],int sum,int n){

	for(int i = 0 ;i<n+1;i++){
		dp[i][0] = 1;
	}
	//if n == 0 any j >0 is not possible.
	for(int j = 1;j<sum+1;j++){
		dp[0][j] = 0;
	}

for(int i = 1 ;i<n+1;i++){
	for(int j = 1 ;j<sum+1;j++){
		if(arr[i-1]<=j){

		dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];

	}else{
		dp[i][j] = dp[i-1][j];
	}
	}
}
	
return dp[n][sum];
}



int main(){
	int arr[5] = {2,3,7,8,10};
	int sum  = 10;
	int n = 5;
	cout<<count(arr,sum,n);
	cout<<'\n';



	for(int i = 0 ;i<n+1;i++){
		for(int j = 0 ;j<sum+1;j++){
			cout<<dp[i][j]<<"_|_";	
		}
		cout<<'\n';
	}

return 0;
}