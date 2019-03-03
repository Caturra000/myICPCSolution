#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
int x1[maxn],y1[maxn],x2[maxn],y2[maxn];
int color[2505],area[2505];
int now,n,m,c;
void solve(int xx1,int xx2,int yy1,int yy2,int z){
    while(z<=c&&(xx1>=x2[z]||xx2<=x1[z]||yy1>=y2[z]||yy2<=y1[z]))z++;
    if(z>c){
        area[now]+=(xx2-xx1)*(yy2-yy1);
        return;
    }
    if(xx1<x1[z]){
        solve(xx1,x1[z],yy1,yy2,z+1);
        xx1=x1[z];
    }
    if(xx2>x2[z]){
        solve(x2[z],xx2,yy1,yy2,z+1);
        xx2=x2[z];
    }
    if(yy1<y1[z]) solve(xx1,xx2,yy1,y1[z],z+1);
    if(yy2>y2[z]) solve(xx1,xx2,y2[z],yy2,z+1);
}
int main(){
    while(scanf("%d%d%d",&n,&m,&c)!=EOF){
        memset(area,0,sizeof area);
        x1[0]=y1[0]=0;x2[0]=n;y2[0]=m;color[0]=1;
        for(int i = 1; i <= c; i++) scanf("%d%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i],&color[i]);
        for(int i = c; i >= 0; i--){
            now=color[i];
            solve(x1[i],x2[i],y1[i],y2[i],i+1);
        }
        for(int i = 1; i <= 2501; i++){
            if(area[i]) printf("%d %d\n",i,area[i]);
        }
    }
    return 0;
}