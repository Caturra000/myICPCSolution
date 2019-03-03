#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e6+11;
typedef long long ll;
int left1[maxn];//_1_1_0 num
int n,m;
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>m){
		memset(left1,0,sizeof left1);
		bool flag=0;
		rep(i,2,n){
			if(m>0) left1[i]++,m--;
			else flag=1;
		}
		rep(i,2,n){
			if(m>0) left1[i]++,m--;
		}
		if(m>4) flag=1;
		else{
			if(m==0||m==1||m==2) left1[1]=m;
			else{
				left1[1]=2;
				left1[n+1]=m-2;
			}
		}
		if(flag) cout<<-1<<endl;
		else{
			rep(i,1,n+1){
				if(left1[i]==1) cout<<1;
				if(left1[i]==2) cout<<11;
				if(i!=n+1) cout<<0;
			}
			cout<<endl;
		}
	}
	return 0;
}