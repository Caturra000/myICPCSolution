#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 1e3+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
const double EPS = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
double a[MAXN],b[MAXN],f[MAXN][MAXN];
int main(){
    while(cin>>n>>m){
        int x=read();
        int y=read();
        if(m==1){
            printf("%.4lf\n",(double)(n-x)*2.0);
            continue;
        }
        rep(i,0,m) f[n][i]=0;
        rrep(i,n-1,1){
            a[1]=(double)(3.0+f[i+1][1])/2.0;b[1]=0.5;
            rep(j,2,m-1){
                a[j]=(double)(4.0+a[j-1]+f[i+1][j])/(3.0-b[j-1]);
                b[j]=(double)1.0/(3.0-b[j-1]);
            }
            f[i][m]=(double)(3.0+a[m-1]+f[i+1][m])/(2.0-b[m-1]);
            rrep(j,m-1,1){
                f[i][j]=a[j]+b[j]*f[i][j+1];
            }
        }
        printf("%.10lf\n",f[x][y]);
    }
    return 0;
}