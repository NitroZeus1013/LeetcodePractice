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


int dp[13][10001]={{0}};

//minimum number of coins required for the given amount.
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        for(int j = 1 ;j<amount+1;j++)dp[0][j]=INT_MAX-1;
        
        for(int j = 1;j<amount+1;j++){
            if(j%coins[0] == 0){
                dp[1][j]=j/coins[0];
            }else{
                dp[1][j] = INT_MAX-1;
            }
        }
        
        for(int i = 2;i<n+1;i++){
            for(int j = 1;j<amount+1;j++){
                if(coins[i-1]<=j)
                dp[i][j] = min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][amount];
	}

// number of ways you can achieve the amount;
int coinChange1(vector<int>& coins, int amount){
	int n = coins.size();

	for(int i = 0;i<n+1;i++)dp[i][0] = 1;

	for(int i = 1;i<n+1;i++){
		for(int j = 1;j<amount+1;j++){
			if(coins[i-1]<=j){
				//total ways are the sum of the ways if I consider that coin and if I don't consider that coin;
				dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];

			}else{

				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][amount];
}

int main(){
	vector<int>coins ={2,5,10,1};
	int amount = 27;
	int n = 4;
	cout<<coinChange(coins,amount);
	cout<<'\n';


	for(int i = 0 ;i<n+1;i++){
	for(int j = 0 ;j<amount+1;j++){
		cout<<dp[i][j]<<"_|_";
		
	}
		cout<<'\n';
	}
	return 0;
}