#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int sudo[66][66];
char str[666];
int usedr[66][11];
int usedc[66][11];
int rsum[66],csum[66];
typedef pair<int,int> P;
P pos(int i,int j){
	if(i>=1&&i<=3){
		if(j>=1&&j<=3) return P(1,1);
		if(j>=4&&j<=6) return P(1,4);
		if(j>=7&&j<=9) return P(1,7);
	}
	if(i>=4&&i<=6){
		if(j>=1&&j<=3) return P(4,1);
		if(j>=4&&j<=6) return P(4,4);
		if(j>=7&&j<=9) return P(4,7);
	}
	if(i>=7&&i<=9){
		if(j>=1&&j<=3) return P(7,1);
		if(j>=4&&j<=6) return P(7,4);
		if(j>=7&&j<=9) return P(7,7);
	}
}
int check2;
bool cal2(int nowr,int nowc,int num){
	int sum=0;
	if(rsum[nowr]+num>45||csum[nowc]+num>45)return 0;
	P p=pos(nowr,nowc);
	int sr=p.first,sc=p.second;
	check2=0;
	rep(i,1,9) if(sudo[nowr][i]==num){
		++check2;
		if(check2>=1)return 0;
	}
	check2=0;
	rep(i,1,9) if(sudo[i][nowc]==num){
		++check2;
		if(check2>=1)return 0;
	}
	check2=0;
	rep(i,sr,sr+2){
		rep(j,sc,sc+2){
			if(sudo[i][j]==num){
				++check2;
				if(check2>=1)return 0;
			}
		}
	}
	return 1;
}
int cnt=0;
bool dfs(int r,int c){
	if(r==9&&c==10)return 1;
	else if(c==10){
		c=1;
		r++;
		if(r==10)return 1;
	}
	while(sudo[r][c]){
		c++;
		if(c==10){
			c=1;
			r++;
			if(r==10)return 1; 
		}
	}
	rep(i,1,9){
		if(usedr[r][i]||usedc[c][i]||cal2(r,c,i)==0){
			continue;
		}
		if(!cal2(r,c,i))continue;
		usedr[r][i]++;usedc[c][i]++;
		rsum[r]+=i;csum[c]+=i;
		sudo[r][c]=i;
		if(dfs(r,c+1))return 1;
		else{
			usedr[r][i]--;usedc[c][i]--;
			rsum[r]-=i;csum[c]-=i;
			sudo[r][c]=0;
		}
		
	}
	return 0;
}
int main(){
	int T=read();
	while(T--){
		memset(usedr,0,sizeof usedr);
		memset(usedc,0,sizeof usedc);
		memset(rsum,0,sizeof rsum);
		memset(csum,0,sizeof csum);
		rep(i,1,9){
			s1(str);
			rep(j,1,9) sudo[i][j]=str[j]-'0';
		}
		bool flag=0;
		rep(i,1,9){
			rep(j,1,9){
				if(!sudo[i][j])continue;
				if(++usedr[i][sudo[i][j]]>1){
					flag=1;
				}
				if(++usedc[j][sudo[i][j]]>1){
					flag=1;
				}
				rsum[i]+=sudo[i][j];
				csum[j]+=sudo[i][j];
			}
		}
		dfs(1,1);
		rep(i,1,9){
			rep(j,1,9){
				print(sudo[i][j]);
			}
			enter;
		}
	}
	return 0;
} 