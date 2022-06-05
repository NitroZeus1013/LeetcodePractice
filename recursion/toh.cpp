#include<iostream>
using namespace std;

void toh(int n , int s ,int d){

	if(n == 1){
		cout<<s<<" -> "<<d<<'\n';
		return ;
	}

	int other = 6 -(s+d);
	toh(n-1,s,other);

	cout<<s<<" -> "<<d<<'\n';


	toh(n-1,other,d);

}



int main(){

	toh(64,1,3);

	return 0;
}