#include<iostream>

using namespace std; 

bool is_palindrome(int l , int r, string s){


	if(l>=r){
		// we came to middle of string without returning false i.e it is palindrome
		return true;
	}

	// I'll check for 1st and last 
	if(s[l]!=s[r]){
		return false;
	}	

	// I trust my function that it'll check for rest and return the answer;

	return is_palindrome(l+1,r-1,s);
}




int main(){


	cout<<is_palindrome(0,3,"abba")<<endl;

	cout<<is_palindrome(0,4,"nakul")<<endl;

	cout<<is_palindrome(0,4,"MADAM")<<endl;


}