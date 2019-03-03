#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+2000+5000+1;
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define rep2(i,j,k) for(int i = j; i <= k; i+=2)
#define rep3(i,j,k) for(int i = j; i <= k; i+=5)
int coin[3][maxn];
int main(){
	ios::sync_with_stdio(0);
	int a,b,c;
	while(cin>>a>>b>>c){
		if(!a&&!b&&!c) break;
		memset(coin,0,sizeof coin);
		rep(i,0,a) coin[0][i]=1;
		rep(i,0,a) rep2(j,0,2*b) coin[1][i+j]+=coin[0][i];
		rep(i,0,a+2*b) rep3(j,0,5*c) coin[2][i+j]+=coin[1][i];
		bool flag=0;
		rep(i,0,a+2*b+5*c) if(coin[2][i]==0){
			cout<<i<<endl;
			flag=1;
			break;
		}
		if(flag==0) cout<<a+2*b+5*c+1<<endl;
	}
	return 0;
}