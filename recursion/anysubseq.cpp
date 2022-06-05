#include<iostream>
#include<vector>
using namespace std; 
// print any subsequence whose sum is k
bool anysubseq(int s,vector<int>v,int arr[],int n,int k,int sum){

	if(s == n){
		if(sum == k){
			for(int i : v){
				cout<<i<<" ";
			}
			return true;
		}
		return false;
	}

	// if by taking the current element we got the required subseq then it'll return true so when it returns true we'll check it and directly return from that point only.no need to execute further calls . Same for not taking current elements
	v.push_back(arr[s]);
	sum+=arr[s];
	if(anysubseq(s+1,v,arr,n,k,sum) == true ){
		return true;
	};

	v.pop_back();
	sum-=arr[s];
	if(anysubseq(s+1,v,arr,n,k,sum)==true)return true;

	return false;
}




int main(){
	
	int arr[3] = {1,2,1};
	int k = 2; 
	int n = 3;
	int sum = 0;
	vector<int>v;
	anysubseq(0,v,arr,n,k,sum);


	return 0;
}