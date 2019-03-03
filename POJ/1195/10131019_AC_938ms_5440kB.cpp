#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#define lowbit(b) (b)&(-b)
using namespace std;
int ft[1100][1100];
int n,x,y,m,l,b,r,t;
void init(){
	memset(ft,0,sizeof ft);
}
int rsq(int x,int y){
	int sum = 0;
	for(int i = x; i; i -= lowbit(i)){
		for(int j = y; j; j -= lowbit(j)){
			sum+=ft[i][j];
		}
	}
	return sum;
}
int rsq(int l,int b,int r,int t){
	return rsq(r,t)-rsq(r,b-1)-rsq(l-1,t)+rsq(l-1,b-1);
}
//int rsq(int i,int a,int b){
//	if(a==1) return rsq(i,b);
//	return rsq(i,b)-rsq(i,a-1);
//}
void update(int x,int y,int v){
	for(int i = x; i <= n; i += lowbit(i)){
		for(int j = y; j <= n; j += lowbit(j)){
			ft[i][j] += v;
		}
	}
}
int main(){
	int op;
	while(scanf("%d",&op)!=EOF){
		if(op==3) continue;
		else if(op==0){
			scanf("%d",&n);
			init();
		}
		else if(op==1){
			scanf("%d%d%d",&x,&y,&m); x++;y++;
			update(x,y,m);
		}
		else{
			scanf("%d%d%d%d",&l,&b,&r,&t); l++;r++;b++;t++;
			printf("%d\n",rsq(l,b,r,t));
		}
	}
	return 0;
}