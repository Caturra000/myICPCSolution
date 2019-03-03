#include<iostream>
#include<algorithm> 
#include<cmath>
using namespace std;
const int maxn = 5e4+11;
int a[maxn],n,m,l,r;
int mn[maxn][20],mx[maxn][20];
void init(){
	for(int i = 1; i <= n; i++) mn[i][0]=mx[i][0]=a[i];
	for(int j = 1; (1<<j) <= n; j++){
		for(int i = 1; i+(1<<j)-1 <= n; i++){
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	} 
}
int query(int l,int r){
	int k=log2(r-l+1);
	return max(mx[l][k],mx[r-(1<<k)+1][k])-min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>m){
		for(int i = 1; i <= n; i++) cin>>a[i];
		init();
		for(int i = 1; i <= m; i++){
			cin>>l>>r;
			cout<<query(l,r)<<endl;
		}
	}
	return 0;
}