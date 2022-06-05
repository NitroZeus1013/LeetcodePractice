#include<iostream>
using namespace std; 


void reverseArray(int arr[],int l , int r){
	if(l>=r){
		return ;
	}
	cout<<"swapping "<<arr[l]<<" "<<arr[r]<<endl;
	swap(arr[l],arr[r]);
	reverseArray(arr,l+1,r-1);
}

void reverseArray2(int arr[], int l , int n ){

	if(l>= n/2){//l>=n-l-1
		return ;
	}

	cout<<"swapping "<<arr[l]<<" "<<arr[n-l-1]<<endl;
	swap(arr[l],arr[n-l-1]);
	reverseArray2(arr,l+1,n);

}


int main(){

	int arr [5] = {1,2,3,4,5};
	// reverseArray(arr,0,4);
	reverseArray2(arr,0,5);
	for(int i =0 ;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0 ;
}