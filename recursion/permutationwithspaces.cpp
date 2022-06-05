#include<iostream>
using namespace std;

void permwithspaces(int s, int n,string ip ,string op){

	if(s==n){
		cout<<op<<'\n';
		return;
	}

	//choose whether you want to add the next character with underscore or without underscore . but you cannot skip it you've to add it.
	permwithspaces(s+1,n,ip,op+"_"+ip[s]);
	permwithspaces(s+1,n,ip,op+ip[s]);

}





int main(){

	string s  = "ABC";
	string op = "A";
	permwithspaces(1,3,s,op);

	return 0;



}