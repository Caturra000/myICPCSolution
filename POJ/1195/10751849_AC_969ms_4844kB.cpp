#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define lowbit(b) (b)&(-b)
using namespace std;
const int maxn = 1025;
int ft[maxn][maxn],n,x,y,m,l,b,r,t;;
void init(){
	memset(ft,0,sizeof ft);
}
void update(int x,int y,int v){
	for(int i = x; i <= n; i+=lowbit(i))
		for(int j = y; j <= n; j+=lowbit(j))
			ft[i][j]+=v;
}
int rsq(int x,int y){
	int sum = 0;
	for(int i = x; i; i-=lowbit(i)){
		for(int j = y; j; j-=lowbit(j)){
			sum+=ft[i][j];
		}
	}
	return sum;
}
int rsq(int l,int r,int b,int t){
	return rsq(r,t)-rsq(l-1,t)-rsq(r,b-1)+rsq(l-1,b-1);
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
            scanf("%d%d%d%d",&l,&b,&r,&t); l++;b++;r++;t++;
            printf("%d\n",rsq(l,r,b,t));
        }
    }
    return 0;
}