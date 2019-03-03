#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
using namespace std;
const int maxn = 1e3+11;
int a[maxn],n,m;
int main(){
	while(cin>>n>>m){
		rep(i,1,n)cin>>a[i];
		sort(a+1,a+1+n);
		int sum=0;
		rep(i,1,m)if(a[i]>=0)break;else sum+=a[i];
		cout<<-sum<<endl;
	}
	return 0;
}