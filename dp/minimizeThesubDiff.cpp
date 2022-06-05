#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<set>
#include<list>
#include<stack>
#include<climits>
using namespace std;

int dp[101][101] = {{0}};

int minimize(int arr[],int n,int total){

	int sum = total/2;
	for(int i = 0;i<n+1;i++){
		dp[i][0] = 1;
	}

	for(int j =1 ;j<sum+1;j++){
		dp[0][j] = 0;
	}

	for(int i = 1;i<n+1;i++){
		for(int j = 1 ;j<sum+1;j++){
				if(arr[i-1]<=j){
		dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];

	}else{
		dp[i][j] = dp[i-1][j];
	}

		}
	}


	int mn = INT_MAX;
	for(int j = 0;j<sum+1;j++){
		if(dp[n][j]){
			int s2 = total-j;
			mn = min(mn,(s2-j));
		}
	}

	return mn;

}

int main(){
	
	int arr[4] = {1,6,11,5};
	int total = 23;
	int n = 4;
	cout<<minimize(arr,n,total);	

return 0;
}