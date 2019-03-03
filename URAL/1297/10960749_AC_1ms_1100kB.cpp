#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+11;
const int MAXN = 2e6+11;
#define rep(i,j,k) for((i)=(j);(i)<(k);(i)++)
#define rrep(i,j,k) for((i)=(j);(i)>=(k);(i)--)
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
#define rr register
#define dbg(n) rep(i,0,n+1){cout<<i<<" "<<sa[i]<<" "<<he[i]<<" "<<endl;if(str[sa[i]]=='A')cout<<"wwwwww\n";}
//sa[1...n]:0...n-1
//he[1...n]:lcp(sa[i-1],sa[i])
int wa[maxn],wb[maxn],wc[maxn],wd[MAXN];
int a[maxn];char str[maxn];
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

struct RMQ{
    int rmq[maxn],mm[maxn],best[20][maxn];
    int i,j,a,b,t;
    void init(int n){
        rep(i,1,n+1) rmq[i]=he[i];
        mm[0]=-1;rep(i,1,n+1)mm[i]=(i&(i-1))==0?mm[i-1]+1:mm[i-1];
        rep(i,1,n+1) best[0][i]=i;
        rep(i,1,mm[n]+1) rep(j,1,n+1-(1<<i)+1){
            a=best[i-1][j];
            b=best[i-1][j+(1<<(i-1))];
            if(rmq[a]<rmq[b]) best[i][j]=a;
            else best[i][j]=b;
        }
    }
    int ask(int a,int b){
        t=mm[b-a+1];b-=(1<<t)-1;
        a=best[t][a];b=best[t][b];
        return rmq[a]<rmq[b]?a:b;
    }
}rmq;

int lcp(int a,int b){
    a=ra[a];b=ra[b];
    if(a>b)swap(a,b);
    return he[rmq.ask(a+1,b)];
}
char trs[maxn];


int main(){
    while(scanf("%s",str)!=EOF){
        rr int i,n=strlen(str);
    	strcpy(trs,str);
    	reverse(trs,trs+n);
    	strcat(str+n+1,trs);str[n]=1;//cout<<str<<endl;
    	rr int m=2*n+1;
    	rep(i,0,m)a[i]=str[i];a[n]=1;a[m]=0;
    	dc3(a,sa,m+1,233);cal(a,sa,m);rmq.init(m);
    	rr int ans=0,pos=0,tmp;
    	rep(i,0,n){
            tmp=lcp(i,m-i);
            if(2*tmp>ans)ans=tmp*2,pos=i-tmp;
            tmp=lcp(i,m-i-1);
            if(2*tmp-1>ans)ans=2*tmp-1,pos=i-tmp+1;
        }
        str[pos+ans]=0;printf("%s\n",str+pos);
		memset(str,0,sizeof str);memset(trs,0,sizeof trs);
    }
    return 0;
}