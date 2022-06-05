#include<iostream>
using namespace std;


int partition(int arr[],int l ,int r){

	int pivot = arr[r];
	int k = l-1;
	for(int i =  l ;i<=r-1;i++){
		if(arr[i] < pivot){
			k++;
			swap(arr[i],arr[k]);
		}
	}
	swap(arr[k+1],arr[r]);

	return k+1;
}


void quick(int arr[],int l ,int r){

	if(l<r){
	
		int part = partition(arr,l,r);
		quick(arr,l,part-1);
		return ;
		quick(arr,part+1,r);
	}
}





int main(){

	int arr[5] = {10,70,20,60,90};
	int n = 5;
	int l = 0 ;
	int r = n-1;
	quick(arr,l,r);
	
	for(int i = l ;i<=r;i++){
		cout<<arr[i]<<" ";
		}
		cout<<endl;
	
	return 0;
}