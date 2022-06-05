#include<iostream>
using namespace std;

void printName(int i, int n){

	if(i>n){
		return ;
	}

	cout<<"Nakul"<<endl;

	printName(i+1,n);
}

void printN(int i , int n){
	if(i>n){
		return ;
	}

	cout<<i<<endl;
	printN(i+1,n);
}

void printNRev(int n){
	if(n==0){
		return ;
	}

	cout<<n<<endl;
	printNRev(n-1);

}

void printNRev2(int i ,int n){
	if(i>n){
		return ;
	}

	printNRev2(i+1,n);
	cout<<i<<endl;
}

void printN2(int i , int n){
	if(i==0){
		return ;
	}
	printN2(i-1,n);
	cout<<i<<endl;
}

int main(){

	// printName(1,3);
	printN2(3,3);

	// printNRev2(1,3);
	return 0;
}