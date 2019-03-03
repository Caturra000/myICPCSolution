#include<stdio.h>
#include<stdio.h>
#define rep(i,j,k) for((i)=(j);(i)<(k);(i)++)
#define rrep(i,j,k) for((i)=(j);(i)>=(k);(i)--)
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
#define rr register
#define  maxn  2000017
#define  N  1000017
int wa[maxn],wb[maxn],wc[maxn],wd[maxn];
char str[N];int a[N];
int sa[N],ra[N],he[N];
int max(int a,int b){
	return a>b?a:b;
}
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
int main(){
    while(scanf("%s",str)!=EOF){
        int lena=strlen(str);
        scanf("%s",str+lena+1);
        int lenb=strlen(str+lena+1);
        int n=lena+lenb+1;
        rr int i,ans=0;
        rep(i,0,n) a[i]=str[i];a[lena]=1;a[n]=0;
        dc3(a,sa,n+1,200);
        cal(a,sa,n);
        rep(i,1,n+1){
            if(sa[i]<lena&&sa[i-1]<lena)continue;
            if(sa[i]>lena&&sa[i-1]>lena)continue;
            ans=max(ans,he[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}