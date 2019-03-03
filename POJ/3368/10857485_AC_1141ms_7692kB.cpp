#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath> 
using namespace std;
const int maxn = 1e5+11;
struct RMQ{
	int st[20][maxn]; 
	void init(int a[],int n){
		for(int i = 1; i <= n; i++) st[0][i]=a[i];
		for(int j = 1; (1<<j) <= n; j++){
			for(int i = 1; i+(1<<j)-1 <= n; i++){
				st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
	}
	int query(int l,int r){
		if(l>r)return 0; //NOTE
		int k=log2(r-l+1);
		return max(st[k][l],st[k][r-(1<<k)+1]);
	}
}rmq;
int a[maxn],f[maxn],n,q,l,r,t;
int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0) break; else scanf("%d",&q);
		memset(f,0,sizeof f);
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
			if(a[i]==a[i-1]) f[i]=f[i-1]+1;
			else f[i]=1;
		}
		rmq.init(f,n);
		for(int i = 1; i <= q; i++){
			scanf("%d%d",&l,&r);
			t=l;
			while(t<=r&&a[t]==a[t-1]) t++;
			printf("%d\n",max(rmq.query(t,r),t-l));//完整部分+不完整补全 
		}
	}
	return 0;
}