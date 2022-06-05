#include<iostream>
#include<vector>
using namespace std;
// void merge(vector<int>&,int,int,int);
// void mergeSort(vector<int>&arr,int l ,int r){

// 	if(l<r){

// 		int mid = l+r/2;

// 		mergeSort(arr,l,mid);
// 		mergeSort(arr,mid+1,r);
// 		merge(arr,l,mid,r);
// 	}

// }


// void merge(vector<int>&arr,int l ,int mid ,int r){
// 	int i = l; 
// 	int j = mid+1;
// 	vector<int> temp;
	

// 	while(i<=mid && j<=r ){
// 		if(arr[i]<=arr[j]){
// 			temp.push_back(arr[i]);
// 			i++;
// 		}else{
// 			temp.push_back(arr[j]);
// 			j++;
// 		}
// 	}

// 	while(i<=mid){
// 		temp.push_back(arr[i]);
// 		i++;

// 	}

// 	while(j<=r){
// 		temp.push_back(arr[j]);
// 		j++;

// 	}

// 	arr= temp;
// }



void merge(int*,int,int,int);
void mergeSort(int arr[],int l ,int r){

	if(l<r){

		int mid = (l+r)/2;

		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}

}


void merge(int arr[] , int l ,int mid ,int r){
	int i = 0; 
	int j = 0;

	int* left = new int[mid-l+1];
	int* right = new int[r-mid];

	for(int k = 0 ;k<mid-l+1;k+=1){
		left[k] = arr[l+k];
	}


	for(int k = 0 ;k<r-mid;k+=1){
		right[k] = arr[mid+1+k];
	}

	int x = l;
	while(i<mid-l+1 && j<r-mid ){
		if(left[i]<=right[j]){
			arr[x++] = left[i];
			i++;
		}else{
			arr[x++] = right[j];
			j++;
		}
	}

	while(i<mid-l+1){
		arr[x++] = left[i];
		i++;

	}

	while(j<r-mid){
		arr[x++] = right[j];
		j++;

	}
}




int main(){

	int arr[5] = {5,6,1,12,4};
	int n = 5;

	mergeSort(arr,0,4);
	for(int i  =0 ;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}