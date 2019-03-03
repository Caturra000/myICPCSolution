#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 5e6+11;
struct Hash{
    int val,cnt;
}hash[maxn];bool used[maxn];
int k[200],p[200];
int n,m,mid,ans;
int fastpow(int a,int n){
    int ans=1;
    while(n){
        if(n&1) ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}
int search(int x){
    int tmp=x;
    while(tmp<0) tmp+=maxn;
    while(tmp>=maxn) tmp-=maxn;
    while(used[tmp]&&hash[tmp].val!=x){//用过但相等则无妨
        tmp++;
        if(tmp>=maxn) tmp-=maxn;//少用模
    }
    return tmp;
}
void insert(int x){
    int pos = search(x);
    hash[pos].val=x;
    used[pos]=true;
    hash[pos].cnt++;
}
void lefthash(int t,int x){
    if(t==mid){//枚举左边的和 
        insert(x);
        return ;
    }
    for(int i = 1; i <= m; i++){
        lefthash(t+1,x+k[t]*fastpow(i,p[t]));
    }
}
void righthash(int t,int x){
    if(t==n){//枚举右边的和,等式取反 
        x=-x;
        int pos=search(x);
        if(hash[pos].val==x){
            ans+=hash[pos].cnt;//解的个数 
        }
        return;
    }
    for(int i = 1; i <= m; i++){
        righthash(t+1,x+k[t]*fastpow(i,p[t]));
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(used,0,sizeof used);
        memset(hash,0,sizeof hash);
        for(int i = 0; i < n; i++){
            scanf("%d%d",&k[i],&p[i]);
        }
        mid=n/2;
        ans=0;
        lefthash(0,0);
        righthash(mid,0);
        printf("%d\n",ans);
    }
    return 0;
}