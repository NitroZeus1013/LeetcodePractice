#include<iostream>
using namespace std;


char toUpper(char ch){

	if(ch>=97 and ch<=122){
		return  (char)(ch-32);
	}

	return ch;
}



void permwithcasechange(int s, int n , string ip ,string op){


	if(s==n){
		cout<<op<<'\n';
		return ;
	}


	permwithcasechange(s+1,n,ip,op+ip[s]);//include as it is.

	permwithcasechange(s+1,n,ip,op+toUpper(ip[s])); // include with case change


}





int main(){

	string s = "ab";

	permwithcasechange(0,2,s,"");

	return 0;
}