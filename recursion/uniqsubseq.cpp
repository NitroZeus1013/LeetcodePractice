#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

void uniqsubseq(int s ,int n, vector<string>&ans,string ip,string op){

		if(s==n){
			ans.push_back(op);
			return ;
		}


		uniqsubseq(s+1,n,ans,ip,op);
		uniqsubseq(s+1,n,ans,ip,op+ip[s]);

}


int main(){
	string s;
	cin>>s;
	vector<string> ans;
	int n = s.length();
	uniqsubseq(0,n,ans,s,"");

	set<string>un;
	
	for(string s:ans){
		un.insert(s);
	}

	for(string s: un){
		cout<<s<<'\n';
	}

	return 0;
}