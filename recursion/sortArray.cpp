#include<iostream>
#include<vector>
using namespace std;


void insert(vector<int>&v,int ele){

	if(v.size()==0 || v[v.size()-1]<=ele){
		v.push_back(ele);
		return;
	}

	int temp = v[v.size()-1];
	v.pop_back();
	insert(v,ele);
	v.push_back(temp);

}


void sort(vector<int> &v){

	if(v.size()==1){
		return;
	}


	int val = v[v.size()-1];
	v.pop_back();
	sort(v);

	insert(v,val);


}



int main(){

	vector<int> v = {11,53,81,13,2,5};

	sort(v);

	for(int i :v){
		cout<<i<<" ";

	}

	cout<<endl;

	return 0;
}