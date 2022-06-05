#include<iostream>
#include<string>
using namespace std;

void subset(string ip, string op){

	if(ip.length() == 0){
		cout<<"\""<<op<<"\""<<'\n';
		return ;
	}

	char ch = ip[0];

	ip.erase(ip.begin()+0);
	subset(ip,op);
	subset(ip,op+ch);



}





int main(){

	subset("abc","");


	return 0;
}