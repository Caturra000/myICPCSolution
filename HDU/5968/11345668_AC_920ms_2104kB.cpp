#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e3+11;
int a[maxn],b[maxn][maxn],x;
inline int myabs(int a){
	return a>0?a:-a;
}
struct node{
	int val,len;
	bool operator < (const node& rhs)const{
		if(myabs(val-x)!=myabs(rhs.val-x)) return myabs(val-x)<myabs(rhs.val-x);
		return len>rhs.len; 
	}
}vec[maxn];
int main(){
	int T,n,m; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		for(int i = 1; i <= n; i++) b[i][i]=a[i];
		for(int l = 1; l <= n; l++) for(int r = l+1; r <= n; r++) b[l][r]=b[l][r-1]^a[r];
		scanf("%d",&m);
		for(int i = 1; i <= m; i++){
			scanf("%d",&x);
			int mn=0x7fffffff;
			int bl=mn,br=mn;
			for(int r = 1; r <= n; r++){
				for(int l = 1; l <= r; l++){
					if(myabs(b[l][r]-x)<mn){
						bl=l;br=r;
						mn=myabs(b[l][r]-x);
					}
					else if(myabs(b[l][r]-x)==mn&&br-bl<r-l){
						br=r;bl=l;
					}
				}
			}
			printf("%d\n",br-bl+1);
		}
		printf("\n");
	}
	return 0;
}
