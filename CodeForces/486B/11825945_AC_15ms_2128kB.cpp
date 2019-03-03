#include<iostream>
#define rep(i,j,k) for(int i = j; i <= k; i++) 
using namespace std;
const int maxn = 233;
bool G[maxn][maxn];
bool G2[maxn][maxn];
int R,C;
bool judge(int r,int c){
	int t=0;
	rep(i,1,R) t|=G2[i][c];
	rep(i,1,C) t|=G2[r][i];
	return t==G[r][c];
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>R>>C){
		rep(i,1,R)rep(j,1,C)cin>>G[i][j],G2[i][j]=1;
		rep(i,1,R)rep(j,1,C)if(!G[i][j]){
			rep(k,1,R)G2[k][j]=0;
			rep(k,1,C)G2[i][k]=0;
		}
		bool flag=0;
		rep(i,1,R)rep(j,1,C)if(judge(i,j)^1){flag=1;break;}
		if(flag)cout<<"NO\n";
		else{
			cout<<"YES\n";
			rep(i,1,R)rep(j,1,C)if(j==C)cout<<G2[i][j]<<endl;else cout<<G2[i][j]<<" "; 
		}
	}
	return 0;
}