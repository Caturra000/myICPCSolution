#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long n;
int main(){
	ios::sync_with_stdio(false);
	long long ans,p;
	while(cin>>n){
		p = 5,ans=0;
		while(n>=p){
			ans+=n/p;
			p*=5;
		}
		cout<<ans<<endl;
	}
	return 0;
}