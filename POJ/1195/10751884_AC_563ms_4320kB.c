#include<stdio.h>
#include<string.h>
#define lowbit(b) (b)&(-b)
int ft[1025][1025],n,x,y,m,l,b,r,t;;
void init(){
	memset(ft,0,sizeof ft);
}
void update(int x,int y,int v){
	int i,j;
	for(i = x; i <= n; i+=lowbit(i))
		for(j = y; j <= n; j+=lowbit(j))
			ft[i][j]+=v;
}
int rsq(int x,int y){
	int i,j,sum = 0;
	for(i = x; i; i-=lowbit(i)){
		for(j = y; j; j-=lowbit(j)){
			sum+=ft[i][j];
		}
	}
	return sum;
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
            printf("%d\n",rsq(r,t)-rsq(l-1,t)-rsq(r,b-1)+rsq(l-1,b-1));
        }
    }
    return 0;
}