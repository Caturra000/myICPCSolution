#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long T,n; cin>>T;
	while(T--){
		cin>>n;
		if(n==1||n==4) cout<<"False"<<endl;
		else{
			if(n%4==0||n%2==1) cout<<"True"<<endl;
			else cout<<"False"<<endl; 
		}
	}
	return 0;
}