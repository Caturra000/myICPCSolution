#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
using namespace std;
typedef long long ll;
const int maxn = 200;
int ft[maxn][maxn][maxn];
#define lowbit(b) (b)&(-b)
void init(){memset(ft,0,sizeof ft);}
void add(int x,int y,int z,int v){
    for(int i = x; i < maxn; i+=lowbit(i)){
        for(int j = y; j < maxn; j+=lowbit(j)){
            for(int k = z; k < maxn; k+=lowbit(k)){
                ft[i][j][k]+=v;
            }
        }
    }
}
ll rsq(int x,int y,int z){
    ll sum=0;
    for(int i = x; i>0; i-=lowbit(i)){
        for(int j = y; j>0; j-=lowbit(j)){
            for(int k = z; k>0; k-=lowbit(k)){
                sum+=ft[i][j][k];
            }
        }
    }
    return sum;
}
ll rsq(int x2,int y2,int z2,int x1,int y1,int z1){
    return  rsq(x2,y2,z2)
            -rsq(x2,y1-1,z2)-rsq(x1-1,y2,z2)-rsq(x2,y2,z1-1)
            +rsq(x1-1,y1-1,z2)+rsq(x2,y1-1,z1-1)+rsq(x1-1,y2,z1-1)
            -rsq(x1-1,y1-1,z1-1);
}
int main(){
    int op,k,x,y,z,x1,y1,z1,x2,y2,z2,n,m;
    while(scan(n)!=EOF){
        init();
        while(1){
            scan(op);
            if(op==3) break;
            else if(op==1){
                scan(x);scan(y);scan(z);scan(k);
                x+=2;y+=2;z+=2;
                add(x,y,z,k);
            }
            else{
                scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
                x1+=2;x2+=2; y1+=2;y2+=2; z1+=2;z2+=2;
                printf("%lld\n",rsq(x2,y2,z2,x1,y1,z1));
            }
        }
    }
    return 0;
}