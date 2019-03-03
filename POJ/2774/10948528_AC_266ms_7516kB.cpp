#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#define F(x) ((x)/3+((x)%3==1?0:tb))  
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)  
using namespace std;  
const int MAXN = 3e6+10;  
const int N = MAXN;  
int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];  
char s[MAXN],t[MAXN];  
int a[MAXN];  
int sa[MAXN],height[MAXN],RANK[MAXN];  
int len[MAXN];  
int c0(int *r,int a,int b)  
{  
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];  
}  
int c12(int k,int *r,int a,int b)  
{  
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);  
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];  
}  
void sort(int *r,int *a,int *b,int n,int m)  
{  
    int i;  
    for(i=0;i<n;i++) wv[i]=r[a[i]];  
    for(i=0;i<m;i++) ws[i]=0;  
    for(i=0;i<n;i++) ws[wv[i]]++;  
    for(i=1;i<m;i++) ws[i]+=ws[i-1];  
    for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];  
    return;  
}  
void dc3(int *r,int *sa,int n,int m) //涵义与DA 相同  
{  
    int i,j,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;  
    int *rn=r+n;  
    r[n]=r[n+1]=0;  
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;  
    sort(r+2,wa,wb,tbc,m);  
    sort(r+1,wb,wa,tbc,m);  
    sort(r,wa,wb,tbc,m);  
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)  
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;  
    if(p<tbc) dc3(rn,san,tbc,p);  
    else for(i=0;i<tbc;i++) san[rn[i]]=i;  //
    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;  
    if(n%3==1) wb[ta++]=n-1;  
    sort(r,wb,wa,ta,m);  
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;  
    for(i=0,j=0,p=0;i<ta && j<tbc;p++)  
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];  
    for(;i<ta;p++) sa[p]=wa[i++];  
    for(;j<tbc;p++) sa[p]=wb[j++];  
    return;  
}  
void calheight(int *r,int *sa,int n)  
{   // 此处N为实际长度  
    int i,j,k=0;  
    // height[]的合法范围为 1-N, 其中0是结尾加入的字符  
    for(i=1;i<=n;i++)  
        RANK[sa[i]]=i;  
    // 根据SA求RANK  
    for(i=0;i<n; height[RANK[i++]] = k )  
        // 定义：h[i] = height[ RANK[i] ]  
        for(k?k--:0,j=sa[RANK[i]-1];  
            r[i+k]==r[j+k]; k++);  
    //根据 h[i] >= h[i-1]-1 来优化计算height过程  
}  
char str[MAXN];
int main(){
    while(scanf("%s",str)!=EOF){
        int lena=strlen(str);
        scanf("%s",str+lena+1);
        int lenb=strlen(str+lena+1);
        int n=lena+lenb+1;
        int i,ans=0;
        for(i=0;i<n;i++) a[i]=str[i];a[lena]=1;a[n]=0;
        dc3(a,sa,n+1,200);
        calheight(a,sa,n);
        for(i=1;i<n+1;i++){
            if(sa[i]<lena&&sa[i-1]<lena)continue;
            if(sa[i]>lena&&sa[i-1]>lena)continue;
            ans=max(ans,height[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}