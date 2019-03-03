#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

int main()
{
    LL n,k;
    scanf("%lld%lld",&n,&k);
    LL ans = (LL)n * k;
    if(n > k) n = k; // if i>k  k/i=0

    for(LL i = 1,l,r,w;i <= n;i = r + 1)
    {
        w = k / i;
        l = i; r = k / w;
        if(r > n) r = n;
        ans -= (r - l + 1) * w * (l + r) / 2;
    }
    printf("%lld",ans);
    return 0;
}
//test 