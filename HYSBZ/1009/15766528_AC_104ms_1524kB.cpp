#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 233 + 11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0, f=1; register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,MOD;
int nxt[MAXN];
char str[MAXN];
int cnt[MAXN][MAXN];
void init(){
    nxt[1]=0;
    for(int i=2,j=0;i<=m;i++){
        while(j&&str[i]!=str[j+1]) j=nxt[j];
        if(str[i]==str[j+1]) j++;
        nxt[i]=j;
    }
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<m;i++){//f[i]->f[i+1]
        for(int k='0';k<='9';k++){
            int j=i;
            while(j&&str[j+1]!=k) j=nxt[j];
            if(str[j+1]==k) cnt[i][j+1]++;//对于每个k来说,能匹配上的位置有很多，但j+1匹配得上的肯定只有一个
            else cnt[i][0]++;
        }
    }
}
struct Matrix{
    int mt[33][33];
    Matrix(){memset(mt,0,sizeof m);}
    Matrix(int k){
        memset(mt,0,sizeof mt);
        if(k==1) rep(i,0,m-1) mt[i][i]=1;
    }
    int* operator[](int k){return mt[k];}
    Matrix operator*(Matrix rhs){
        Matrix ans;
        memset(ans.mt,0,sizeof ans.mt);
        rep(i,0,m-1){
            rep(j,0,m-1){
                rep(k,0,m-1){
                    ans[i][j]=ans.mt[i][j]+(mt[i][k]*rhs[k][j])%MOD;
                    if(ans[i][j]>=MOD) ans[i][j]%=MOD;
                }
            }
        }
        return ans;
    }
};
Matrix fpw(Matrix a,int n){
    Matrix res(1);
    while(n){
        if(n&1) res=res*a;
        a=a*a; n>>=1;
    }
    return res;
}
int main(){
    while(cin>>n>>m>>MOD){
        scanf("%s",str+1);
        init();
        Matrix b;
        rep(i,0,m-1) rep(j,0,m-1) b[i][j]=cnt[i][j];
        Matrix res=fpw(b,n);
        ll ans=0;
        rep(i,0,m-1) ans=(ans+res[0][i])%MOD;
        println(ans);
    }
    return 0;
}