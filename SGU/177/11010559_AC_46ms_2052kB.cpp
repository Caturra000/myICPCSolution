#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 5e3+11;
short x1[maxn],y1[maxn],x2[maxn],y2[maxn],color[maxn];
int area[maxn],n,m,now;
char str[10];
int solve(int xx1,int xx2,int yy1,int yy2,int z){
    while(z<=m&&(xx1>=x2[z]||xx2<=x1[z]||yy1>=y2[z]||yy2<=y1[z])) z++;
    if(z>m){
        return (xx2-xx1)*(yy2-yy1);
    }
    int ans=0;
    if(xx1<x1[z]) ans+=solve(xx1,x1[z],yy1,yy2,z+1),xx1=x1[z];
    if(xx2>x2[z]) ans+=solve(x2[z],xx2,yy1,yy2,z+1),xx2=x2[z];
    if(yy1<y1[z]) ans+=solve(xx1,xx2,yy1,y1[z],z+1);
    if(yy2>y2[z]) ans+=solve(xx1,xx2,y2[z],yy2,z+1);
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        area[0]=area[1]=0;
        x1[0]=y1[0]=1;y1[0]=y2[0]=n;color[0]=0;
        for(int i = 1; i <= m; i++){
            scanf("%hd%hd%hd%hd",&x1[i],&y1[i],&x2[i],&y2[i]);
            scanf("%s",str);
            if(str[0]=='b') color[i]=1;
            else color[i]=0;
            if(x1[i]>x2[i]) swap(x1[i],x2[i]);
            if(y1[i]>y2[i]) swap(y1[i],y2[i]);
            x2[i]++;y2[i]++;
        }
        for(int i = m; i >= 0; i--){
            now=color[i];
            area[now]+=solve(x1[i],x2[i],y1[i],y2[i],i+1);
        }
        printf("%d\n",n*n-area[1]);
    }
    return 0;
}