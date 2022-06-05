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

int dp[101][101] = {{0}};
//top-down


int unbounded(int arr[],int wt[],int C ,int n){

//initialization already done on line 12;

for(int i = 1; i<n+1;i++){
	for(int j = 1;j<C+1;j++){
		if(arr[i-1]<=j){
			dp[i][j] = max(arr[i-1]+dp[i][j-wt[i]],dp[i-1][j]);
		}else{
			dp[i][j] = dp[i-1][j];
		}
	}
}



}




int main(){
	

return 0;
}