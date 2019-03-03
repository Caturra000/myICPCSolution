#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 4e5+5;
struct trie{
	int ch[maxn<<5][2],sz[maxn<<5],val[maxn<<5],tot,root;
	void init(){
		ch[0][0]=ch[0][1]=0;
		sz[0]=0;val[0]=0;
		tot=1;root=0;
	}
	void insert(int x){
		int c,now=root;
		for(int k = 30; k >= 0; k--){
			c=((x>>k)&1);
			if(!ch[now][c]){
				ch[tot][0]=ch[tot][1]=0;
				sz[tot]=0;val[tot]=0;
				ch[now][c]=tot++;
			}
			now=ch[now][c];
			sz[now]++;
		}
		val[now]=x;
	}
	void update(int x,int d){
		int c,now=root;
		for(int k = 30; k >= 0; k--){
			c=((x>>k)&1);
			now=ch[now][c];
			sz[now]+=d;
		}
	}
	int query(int x){
		int c,now=root;
		for(int k = 30; k >= 0; k--){
			c=((x>>k)&1);
			if(ch[now][c^1]&&sz[ch[now][c^1]]) now=ch[now][c^1];
			else now=ch[now][c];
		}
		return x^val[now];
	}
}trie;
int n,ans,a[maxn],pre[maxn],suf[maxn],mpre[maxn],msuf[maxn];
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
		}
		pre[0]=suf[n+1]=0;
		for(int i = 1; i <= n; i++){
			pre[i]=pre[i-1]^a[i];
		}
		for(int i = n; i > 0; i--){
			suf[i]=suf[i+1]^a[i];
		}
		memset(mpre,0,sizeof mpre);trie.init();trie.insert(0);
		for(int i = 1; i <= n; i++){
			mpre[i]=max(mpre[i-1],trie.query(pre[i-1]));
			trie.insert(pre[i]);
		}
		memset(msuf,0,sizeof msuf);trie.init();trie.insert(0);
//		for(int i = n; i > 0; i--){
//			msuf[i]=max(msuf[i+1],trie.query(suf[i+1]));
//			trie.insert(suf[i]);
//		}
//		ans=0;
//		for(int i = n; i > 0; i--){
//			ans=max(ans,msuf[i]+mpre[i-1]);
//		}
		for(int i = n ; i > 0; i--){
			ans=max(ans,trie.query(suf[i])+mpre[i-1]);
			trie.insert(suf[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}