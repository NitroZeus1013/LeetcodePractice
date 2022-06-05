#include<iostream>
using namespace std;

int countSubseq(int s, int arr[],int n,int k,int sum){

	if(s == n){
		if(k==sum){
			return 1;
		}
		return 0;
	}

	//I select the element and trust my function that it'll make decisions for next elements and give me the answer by adding this particular element.
	sum+=arr[s];
	int l = countSubseq(s+1,arr,n,k,sum); // l is count of subseq whose sum == k with considering current element.

	//I deselect the element and trust my function that it'll make decisions for next elements and give me the answer by not adding this particular element.
	sum-=arr[s];
	int r = countSubseq(s+1,arr,n,k,sum); // r is count of subseq whose sum == k without considering current element.

	return l+r;
}




int main(){

	int arr[3]  = {1,2,1};
	int n = 3;
	int k = 2;
	int sum = 0 ;
	int s = 0 ;

	cout<<countSubseq(s,arr,n,k,sum);
}