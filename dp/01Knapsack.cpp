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

//we make an matrix of size+1 and sum+1 to respresent when x size of array is taken and y is Capacity then what is the answer;
//int dp[size_of_array+1][Capacity+1];
int dp[101][101] = {{0}};

//pure recursive approach
int knapsack(int val[],int wt[],int n,int C){
	//if there are not items or the capacity of KS is 0 then profit is 0;
	if(n==0 or C==0){
		return 0;
	}

	//we can add an item only if the wt of the item is <= capacity of KS
	if(wt[n-1]<=C){
		//either we can decide to take an item(val) or we can decide to not take an item.
		// if take it it's value is added and we take the maximum result of the both calls.
		int added = val[n-1]+knapsack(val,wt,n-1,C-wt[n-1]);
		// move to next item without considering the value of current item and bring the ans;
		int didnt = knapsack(val,wt,n-1,C);
		return max(added,didnt);

	}else{
		// if the wt of an item in > the capacity we just ignore that item and move to next item
		return knapsack(val,wt,n-1,C);
	}
}

// recursion + memoization 

int knapsack1(int val[],int wt[],int n,int C){

	if(n == 0 or C == 0)return 0;
	//if we have already calculated the answer for a subproblem (n,C) then just return the ans;
	if(dp[n][C])return dp[n][C];

	if(wt[n-1]<=C){

		return dp[n][C] =  max(val[n-1]+knapsack1(val,wt,n-1,C-wt[n-1]),knapsack1(val,wt,n-1,C));
	}else{
		return dp[n][C] = knapsack1(val,wt,n-1,C);
	}
}

int knapsack2(int val[],int wt[],int n, int C){

	//base case == initialization 
	for(int i = 0 ;i<n+1;i++){
		for(int j = 0 ;j<C+1;j++){
			if(i == 0 or j ==0){
				dp[i][j] = 0;
			}
		}
	}


	for(int i = 1 ;i<n+1;i++){

		for(int j = 1 ;j<C+1;j++){

			//if wt of current item is <= current capacity then take decision whether to add or not.
			if(wt[i-1]<=j){

				//if we take it then add the value and get the ans for the subproblem,or just ignore and get answer for subproblem and store it .
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}else{
				// store the ans of the current subproblem ignore the element and get the answer for the next subproblem;
				dp[i][j] = dp[i-1][j];
			}


		}
	}



	return dp[n][C];

}

int main(){
	
int val[4]= {1,4,5,7};
int wt[4] = {1,3,4,5};
int C = 7;
int n = 3;

int ans = knapsack2(val,wt,n,C);
cout<<ans<<'\n';
for(int i = 0 ;i<n+1;i++){
	for(int j = 0 ;j<C+1;j++){
		cout<<dp[i][j]<<"_|_";
		
	}
	cout<<'\n';
}

return 0;
}