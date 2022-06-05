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


//we make an matrix of size+1 and sum+1 to respresent when x size of array is taken and y is sum required then what is the answer;
//int dp[size_of_array+1][sum+1];
int dp[101][101] = {{0}};
// top-down approach
int subsetsum(int arr[],int sum,int n){

	for(int j = 1;j<sum+1;j++){
		dp[0][j] = 0;
	}
	for(int i = 0 ;i<n+1;i++){
		dp[i][0] = 1;
	}


	for(int i = 1 ;i<n+1;i++){
		for(int j = 1 ;j<sum+1;j++){

			if(arr[i-1] <= j){
				// here we're saying if we've the answer as T for j-arr[i-1] then it'll true in matrix
				//like arr[2] = {2,3} and j = 4 i = 2, so 4-3 == 1 so if we are having the set of numbers that can make a sum 1 then it is also true for 4 as 3+that 1 is 4
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}

		}
	}

	return dp[n][sum];

}


int main(){

	int arr[5] = {2,3,7,8,10};
	int sum  = 11;
	int n = 5;
	cout<<subsetsum(arr,sum,n);
	cout<<'\n';

	for(int i = 0 ;i<n+1;i++){
	for(int j = 0 ;j<sum+1;j++){
		cout<<dp[i][j]<<"_|_";
		
	}
	cout<<'\n';
}

	return 0;
}