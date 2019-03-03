#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n>=0&&n<=9)
        cout<<1<<endl;
        else if(n>=10&&n<=99)
            cout<<(n/10+1)*10-n<<endl;
        else if(n>=100&&n<=999)
            cout<<(n/100+1)*100-n<<endl;
        else if(n>=1000&&n<=9999)
            cout<<(n/1000+1)*1000-n<<endl;
        else if(n>=10000&&n<=99999)
            cout<<(n/10000+1)*10000-n<<endl;
        else if(n>=100000&&n<=999999)
            cout<<(n/100000+1)*100000-n<<endl;
        else if(n>=1000000&&n<=9999999)
            cout<<(n/1000000+1)*1000000-n<<endl;
        else if(n>=10000000&&n<=99999999)
            cout<<(n/10000000+1)*10000000-n<<endl;
        else if(n>=100000000&&n<=999999999)
            cout<<(n/100000000+1)*100000000-n<<endl;
        else if(n>=1000000000&&n<=9999999999)
            cout<<(n/1000000000+1)*1000000000-n<<endl;
    }
    return 0;
}