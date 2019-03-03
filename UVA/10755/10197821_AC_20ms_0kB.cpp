#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 30;
ll sum[maxn][maxn][maxn];
ll sum1(int x,int y,int z){//第k层1...x至1...y的总和 
	return sum[x][y][z]-sum[x][y][z-1];
}
ll Sum(int i1,int i2,int j1,int j2,int k){//第k层i1...i2至j1...j2的总和 
	return sum1(i2,j2,k)-sum1(i2,j1-1,k)-sum1(i1-1,j2,k)+sum1(i1-1,j1-1,k);
}
int x,y,z;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&x,&y,&z);
		memset(sum,0,sizeof sum);
		for(int i = 1; i <= x; i++){
			for(int j = 1; j <= y; j++){
				for(int k = 1; k <= z; k++){
					scanf("%lld",&sum[i][j][k]);
					sum[i][j][k] += sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]
									-sum[i-1][j-1][k]-sum[i-1][j][k-1]-sum[i][j-1][k-1]
									+sum[i-1][j-1][k-1]; 
				}
			}
		}
		ll ans = 1ll<<63; ans=-ans;
		for(int i1 = 1; i1 <= x; i1++) for(int j1 = 1; j1 <= y; j1++)
			for(int i2 = i1; i2 <= x; i2++) for(int j2 = j1; j2 <= y; j2++){
				ll t = 0;
				for(int k = 1; k <= z; k++){
					t+=Sum(i1,i2,j1,j2,k);
					ans = max(ans,t);
					if(t<0) t=0;
				}
			}
		if(T) printf("%lld\n\n",ans);
		else printf("%lld\n",ans);
	}
	return 0;
} 