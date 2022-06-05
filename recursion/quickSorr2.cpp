#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void subsetSum(int index, int N, int sum , int arr[],vector<int>&ds){

	if(index==N){
		ds.push_back(sum);
		return ;
	}

	subsetSum(index+1,N,sum,arr,ds);
	subsetSum(index+1,N,sum+arr[index],arr,ds);
}




int main(){
	int arr[3] = {3,1,2};
	int n = 3;
	vector<int>ds;

	subsetSum(0,n,0,arr,ds);
	sort(ds.begin(),ds.end());

	for(int i : ds){
		cout<<i<<" ";

	}

	return 0 ;
}