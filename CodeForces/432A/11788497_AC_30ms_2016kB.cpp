#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int main(){
	int n,k,m,t;
	while(cin>>n>>k){
		m=0;
		for(int i = 1; i <= n; i++){
			cin>>t;
			if(5-t>=k)m++;
		}
		cout<<((int)(m/3))<<endl;
	}
	return 0;
}