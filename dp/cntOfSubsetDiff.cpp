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


// top-down // gives the count of subsets whose difference is equal to given diff; 
// this problem is just subset sum;
int dp[101][101] = {{0}};
int countofSubsetDiff(int arr[],int diff,int n){

	int total = 0;
	for(int i=0;i<n;i++){
		total+=arr[i];
	}

	int sum = total+diff;
	if(sum%2!=0)return -1;//if sum is odd return -1 since it is not possible.
	//we've to find a subset s1 whose sum == total+diff/2;
	sum =sum/2;
	//initialization
	for(int i = 0; i<n+1;i++){
		dp[i][0] = 1; // a sum == 0 is always possible.
	}

	for(int j = 1;j<sum+1;j++){
		dp[0][j] = 0;//sum with 0 elements is 0;
	}


	for(int i = 1;i<n+1;i++){
		for(int j = 1;j<sum+1;j++){

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
	
	int n = 4;
	int arr[4] = {1,1,2,3};
	int diff = 2;

	cout<<countofSubsetDiff(arr,diff,n);
	cout<<'\n';


return 0;
}