#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int maxn=1e5+5;
const int inf=1e9;
const int ra=10;
int ten[4]= {1,ra,ra*ra,ra*ra*ra};
int radix=ra*ra*ra*ra;
const int NV=80;
struct integer
{
    int d[NV];
    integer()
    {
        *this=integer(0);
    }
    integer(int x)
    {
        for (int i=0; i<NV; i++) d[i]=0;
        if (!x) d[0]=1;
        while(x)
        {
            d[++d[0]]=x%radix;
            x/=radix;
        }
    }
    integer(long long x)
    {
        for (int i=0; i<NV; i++) d[i]=0;
        if (!x) d[0]=1;
        while(x)
        {
            d[++d[0]]=x%radix;
            x/=radix;
        }
    }
    integer(const char s[])
    {
        int len=strlen(s),i,j,k;
        d[0]=(len-1)/4+1;
        for (i=1; i<NV; i++) d[i]=0;
        for (i=len-1; i>=0; i--)
        {
            j=(len-i-1)/4+1;
            k=(len-i-1)%4;
            d[j]+=ten[k]*(s[i]-'0');
        }
        while(d[0]>1&&d[d[0]]==0) d[0]--;
    }
    string tostring()
    {
        string s;
        int i,j,temp;
        for (i=3; i>=1; i--) if (d[d[0]]>=ten[i]) break;
        temp=d[d[0]];
        int cnt=0;
        for (j=i; j>=0; j--)
        {
            s+=(char) (temp/ten[j]+'0');
            if(cnt++>41)return s;
            temp%=ten[j];
        }
        for (i=d[0]-1; i>0; i--)
        {
            temp=d[i];
            for (j=3; j>=0; j--)
            {
                s+=(char) (temp/ten[j]+'0');
                if(cnt++>41)return s;
                temp%=ten[j];
            }
        }
        return s;
    }
    void output()
    {
        int k=d[0];
        printf("%d",d[k--]);
        while(k) printf("%04d",d[k--]);
        putchar('\n');
    }
} d,mid1[15];
bool operator <(const integer &a,const integer &b)
{
    if (a.d[0]!=b.d[0]) return a.d[0]<b.d[0];
    for (int i=a.d[0]; i>0; i--)
        if (a.d[i]!=b.d[i])
            return a.d[i]<b.d[i];
    return 0;
}
integer operator +(const integer &a,const integer &b)
{
    integer c;
    c.d[0]=max(a.d[0],b.d[0]);
    int i,x=0;
    for (i=1; i<=c.d[0]; i++)
    {
        x+=a.d[i]+b.d[i];
        c.d[i]=x%radix;
        x/=radix;
    }
    while(x)
    {
        c.d[++c.d[0]]=x%radix;
        x/=radix;
    }
    return c;
}
void init(int b) ///将大数切换至任意<=10进制
{
    for (int i=1; i<=3; i++)
        ten[i]=ten[i-1]*b;
    radix=b*b*b*b;
}
integer F[1006];
int main(){
	F[0]=0;F[1]=1;F[2]=1;
	for(int i = 3; i <= 1003; i++){
		F[i]=F[i-1]+F[i-2];
	}
	int n,x; scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		F[x].output();
	}
	return 0;
} 