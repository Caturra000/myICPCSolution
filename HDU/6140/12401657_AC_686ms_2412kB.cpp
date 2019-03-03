#include<bits/stdc++.h>
using namespace std;
#define MEM(a,b) memset(a,b,sizeof(a))
#define bug puts("bug");
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef unsigned long long LL;
typedef pair<int,int> pii;
const int maxn=1e6+10;
const int mod=1e9+7;
using namespace std;
int t,m,n,k;
bitset<2000003> B;
int a[maxn];
const int p=1000001;
char s[maxn][1];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i) scanf("%d",&a[i]);
        for(int i=0;i<n;++i) scanf("%s",&s[i]);
        B.reset();
        B.set(p);
        int sum1=0,sum2=0;
        for(int i=0;i<n;++i){
            if(s[i][0]!='L') sum2-=a[i];
            if(s[i][0]!='D') sum1+=a[i];
        }
        if(sum2>k||sum1<k)goto ge;
        for(int i=0;i<n;++i){
            if(s[i][0]!='L') B|=(B>>a[i]);
            if(s[i][0]!='D') B|=(B<<a[i]);
            if(B.test(k+p)) goto ge;
        }
        ge:
        if(B.test(k+p)) puts("yes");
        else puts("no");
    }
    return 0;
}
//test