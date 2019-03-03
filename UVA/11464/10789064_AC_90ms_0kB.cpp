#include<bits/stdc++.h>
using namespace std;
const int maxn = 23;
const int INF = 0x3f3f3f3f;
int mt[maxn][maxn];
int tmp[maxn][maxn];
int C(int s,int n){
	int cnt=0;
	memcpy(tmp,mt,sizeof mt);
	for(int i = 0; i < n; i++)
		if(s&(1<<i))
			if(tmp[0][i]==0) tmp[0][i]=1,cnt++;
			else return INF;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++){
			int c=0;
			if(j>0)c+=tmp[i-1][j-1];
			if(j<n-1)c+=tmp[i-1][j+1];
			if(i>1)c+=tmp[i-2][j];
			if((c+tmp[i][j])%2==1){
				if(tmp[i][j]) return INF;
				tmp[i][j]=1;cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	int T,kase; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d",&mt[i][j]);
			}
		}
		int ans=INF;
		for(int i = 0; i < (1<<n); i++){
			ans=min(ans,C(i,n));
		}
		printf("Case %d: %d\n",++kase,ans==INF?-1:ans);
	}
	return 0;
}