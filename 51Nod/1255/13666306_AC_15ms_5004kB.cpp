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
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int tot;
char str[MAXN],tmp[MAXN];
char biao[55];
bool C[28][MAXN];
bool vis[129];
bool havenxt(int i,int j){
	return C[i][j+1];
}
bool mustadd(int i,int j){
	return C[i][j]==1&&C[i][j+1]==0;
}
bool better(int ii,int jj){
	rep(i,1,ii-1){
		if(C[i][jj+1]) return 1; 
	}
	return 0;
}
int pos[129];
int nxtsame[MAXN],cur[30];
int main(){
	while(~s1(str)){
		strcpy(tmp+1,str+1);
		int len=strlen(str+1);
		sort(tmp+1,tmp+1+len);
		int llen=unique(tmp+1,tmp+1+len)-tmp-1;
		tot=llen;
		rep(i,1,llen) pos[biao[i]=tmp[i]]=i;
		memset(C,0,sizeof C);
		rep(i,1,llen) rrep(j,len,1){
			C[i][j]=C[i][j+1]|bool(biao[i]==str[j]);
		}
//		string s;
//		int nxt=0;
//		memset(vis,0,sizeof vis);
//		rep(i,1,len){
//			if(!vis[str[i]]&&mustadd(pos[str[i]],i)==0){
//				if(!better(pos[str[i]],i)){
//					s.push_back(str[i]);
//					vis[str[i]]=1;
//				}
//			}else if(!vis[str[i]]&&(mustadd(pos[str[i]],i))||nxt+1==pos[str[i]]){
//				s.push_back(str[i]);
//				if(nxt+1==pos[str[i]]) nxt++;
//				vis[str[i]]=1;
//			}
//		}
		memset(vis,0,sizeof vis);
		stack<char> stk;
		rep(i,1,len){
			if(stk.empty()){
				stk.push(str[i]);
				vis[str[i]]=1;
				continue;
			}
			if(!vis[str[i]]){
				while(!stk.empty()&&stk.top()>str[i]){
					if(havenxt(pos[stk.top()],i)){
						vis[stk.top()]=0;
						stk.pop();
					}else break;
				}
				stk.push(str[i]);vis[str[i]]=1;
			}
		}
		stack<char> sstk;
		while(!stk.empty()){
			sstk.push(stk.top());
			stk.pop();
		}
		while(!sstk.empty()){
			printf("%c",sstk.top());
			sstk.pop();
		}enter;
	}
	return 0;
} 