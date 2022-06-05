#include<iostream>
using namespace std;


int partition(int arr[],int l, int r){

	int pivot = arr[l+(r-l)/2];
	while(l<=r){

		while(arr[l]<pivot)l++;
		while(arr[r]>pivot)r--;

		if(l<=r){
			swap(arr[l],arr[r]);
			l++;
			r--;
		}
	}
	return l;

}

void quick2(int arr[],int l , int r){

	if(l<r){
		int ind = partition(arr,l,r);
		quick2(arr,l,ind-1);
		quick2(arr,ind,r);
	}
}




int main(){
	int arr[5] = {10,70,20,60,90};
	int n = 5;
	int l = 0 ;
	int r = n-1;

	quick2(arr,l,r);
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}