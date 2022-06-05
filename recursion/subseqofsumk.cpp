#include<iostream>
#include<vector>
using namespace std; 

void subseq(int index,vector<int>v,int arr[],int n,int sum,int k){

	if(index == n){
		if(sum == k){
			for(int a:v){
				cout<<a<<" ";

			}
			cout<<endl;
			
		}
		return;
	}



	// pick the element 
	v.push_back(arr[index]);
	sum = sum + arr[index];
	subseq(index+1,v,arr,n,sum,k);

	// not pick the element basically we picked up in this call only so we have remove it
	v.pop_back();
	sum = sum - arr[index];
	// now calling the function without picking the element at current index;
	subseq(index+1,v,arr,n,sum,k);
}





int main(){



	int arr [3] = {1,2,1};
	int k = 2;
	std::vector<int> v;
	subseq(0,v,arr,3,0,k);
}