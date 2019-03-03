#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct qwert{
	int x,y,z;
};
qwert a[123];
int sz,dp[555];
bool cmp(qwert a,qwert b){
	return a.x>b.x;
}
void add(int x,int y,int z){
	a[++sz].x = x;
	a[sz].y = y;
	a[sz].z = z;
}
int main(){
	ios::sync_with_stdio(false);
	int n,kase=0;
	while(cin >> n){
		if(n==0) break;
		memset(dp,0,sizeof dp);
		sz=0;
		int q,w,e;
		for(int i = 1; i <= n; i++){
			cin >> q >> w >> e;
//			do{
//				add(b[0],b[1],b[2]);
//			}while(next_permutation(b));
			add(q,w,e);add(q,e,w);add(w,q,e);add(w,e,q);add(e,q,w);add(e,w,q);
		}
		sort(a+1,a+sz+1,cmp); //排除变量x 
		dp[1] = a[1].z;
		for(int i = 1; i <= sz; i++){
			dp[i] = a[i].z; //dp[宽度] = maxH 
			for(int j = i-1; j >= 1; j--){
				if(a[j].x > a[i].x && a[j].y > a[i].y){
					dp[i] = max(dp[i],dp[j]+a[i].z);
				}
			}
		}//感觉和背包一个套路 
		int ans = 0;
		for(int i = 1; i <= sz; i++){
			ans = max(ans,dp[i]);
		}
		cout << "Case " << ++kase << ": maximum height = " << ans << endl;
	}
	return 0;
}