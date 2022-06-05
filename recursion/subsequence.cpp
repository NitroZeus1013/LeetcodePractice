#include<iostream>
#include<vector>
using namespace std;


void subseq(int ind , vector<int> v , int arr[],int n ){

	//if you've decided for last element then stop and print the result;
	if(ind >= n){
		cout<<"[ ";
		for(int i : v){
			cout<<i<<" ";
		}
		cout<<"]";
		cout<<endl;
		return ;
	}



	// pick the current element and add to subsequence

	v.push_back(arr[ind]);
	//call for the next index 
	subseq(ind+1, v, arr,n);

	// not pick or remove the element which you'd picked in previous step.
	v.pop_back();
	//call for the next index;
	subseq(ind+1,v,arr,n);

	

	// subseq(ind+1, v, arr,n);

		// 	v.push_back(arr[ind]);

	// subseq(ind+1,v,arr,n);

}

void subseq2(int ind , vector<int> v , int arr[],int n ){

	//if you've decided for last element then stop and print the result;
	if(ind >= n){
		cout<<"[ ";
		for(int i : v){
			cout<<i<<" ";
		}
		cout<<"]";
		cout<<endl;
		return ;
	}


	//if you've not changed the state of the data structure (here v) while making the next-1 call (here first call at line 62)
	// then you don't have to make any changes to state of DS before making the next-2 call (here second call)
	// as it was not changed in the above lines we don't need to make any changes before the 2nd call . 

	// dont pick the current element and call for the next element

	subseq2(ind+1,v,arr,n);
	//pick the current element
	v.push_back(arr[ind]);
	//call for the next index 
	subseq2(ind+1, v, arr,n);

	//if you've not picked up the element in this call then you don't need to remove it.
	// remove the element you just picked and return to previous state 
	v.pop_back();

}



int main(){

	int arr[3] =  {3,1,2};
	std::vector<int> v;
	subseq2(0,v,arr,3);


}