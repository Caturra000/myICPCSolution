#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 2e4+11;
const int MAXN = 1e6+11;
#define rep(i,j,k) for((i)=(j);(i)<(k);(i)++)
#define rrep(i,j,k) for((i)=(j);(i)>=(k);(i)--)
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
#define rr register

int wa[maxn],wb[maxn],wc[maxn],wd[MAXN];
int a[maxn];
int sa[maxn],ra[maxn],he[maxn];
int c0(int *r,int a,int b){
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b){
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    return r[a]<r[b]||r[a]==r[b]&&wc[a+1]<wc[b+1];
}
void sort(int *r,int *a,int *b,int n,int m){
    rr int i;
    rep(i,0,n) wc[i]=r[a[i]];
    rep(i,0,m) wd[i]=0;
    rep(i,0,n) wd[wc[i]]++;
    rep(i,1,m) wd[i]+=wd[i-1];
    rrep(i,n-1,0) b[--wd[wc[i]]]=a[i];
}
void dc3(int *r,int *sa,int n,int m){
    rr int i,j,p,ta=0,tb=(n+1)/3,tbc=0;
    int *rn=r+n,*san=sa+n;
    r[n]=r[n+1]=0;
    rep(i,0,n) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    p=1;rn[F(wb[0])]=0;
    rep(i,1,tbc) rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else rep(i,0,tbc) san[rn[i]]=i;
    rep(i,0,tbc) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    rep(i,0,tbc) wc[wb[i]=G(san[i])]=i;
    for(i=j=p=0;i<ta&&j<tbc;p++) sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
}
void cal(int *r,int *sa,int n){
    rr int i,j,k=0;
    rep(i,1,n+1) ra[sa[i]]=i;
    for(i=0;i<n;he[ra[i++]]=k) for(k?k--:0,j=sa[ra[i]-1];r[i+k]==r[j+k];k++);
}
int k,n;
bool C(int mid){
    rr int i,s=1;
    rep(i,1,n+1){
        if(he[i]>=mid){
            s++;
            if(s>=k) return 1;
        }
        else s=1;
    }
    return 0;
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        rr int i;rep(i,0,n){scanf("%d",&a[i]);a[i]++;}a[n]=0;
        dc3(a,sa,n+1,(int)1e6+11);cal(a,sa,n);
        int lx=1,rx=n,mid;
        while(lx<rx){
            mid=lx+(rx-lx+1)/2;
            if(C(mid)) lx=mid;
            else rx=mid-1;
        }
        printf("%d\n",lx);
    }
    return 0;
}