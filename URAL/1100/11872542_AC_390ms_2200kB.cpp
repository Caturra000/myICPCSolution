#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define clr(a,b) memset(a,b,sizeof a);
using namespace std;
const int maxn = 2e5+11;
struct node{
    int a,b,c;
}a[maxn];
bool cmp(node a,node b){
    if(a.c!=b.c) return a.c>b.c;
    return a.a<b.a;
}
int main(){
    int n;
    while(scan(n)!=EOF){
        rep(i,1,n){
            a[i].a=i;
            scan(a[i].b);scan(a[i].c);
        }
        sort(a+1,a+n+1,cmp);
        rep(i,1,n) printf("%d %d\n",a[i].b,a[i].c);
    }
    return 0;
}