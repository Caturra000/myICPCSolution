#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn  = 1e4+11;
struct Trie{
	int ch[maxn<<5][2],sz[maxn<<5],val[maxn<<5],tot,root;
	void init(){
		ch[0][0]=ch[0][1]=0;
		tot=1;root=0;
	}
	void insert(int x){
		int now=root;
		for(int k = 30; k >= 0; k--){
			int c=((x>>k)&1);
			if(!ch[now][c]){
				ch[tot][0]=ch[tot][1]=0;
				val[tot]=0;sz[tot]=0;
				ch[now][c]=tot++;
			}
			now=ch[now][c];
			sz[now]++;
		}
		val[now]=x;
	}
	void update(int x,int d){
		int now=root;
		for(int k = 30; k >= 0; k--){
			int c=((x>>k)&1);
			now=ch[now][c];
			sz[now]+=d;//NOTE!!
		}
		//val[now]+=d;
	} 
	int query(int x){
		int now=root;
		for(int k = 30; k >= 0; k--){
			int c=((x>>k)&1);
			if(ch[now][c^1]&&sz[ch[now][c^1]]) now=ch[now][c^1];
			else now=ch[now][c]; 
		}
		return x^val[now];
	}
}trie;
int n,a[maxn];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		trie.init();
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		for(int i = 0; i < n; i++){
			trie.insert(a[i]);
		}
		int ans=0;
		for(int i = 0; i < n; i++){
			trie.update(a[i],-1);
			for(int j = i+1; j < n; j++){
				trie.update(a[j],-1);
				ans=max(ans,trie.query(a[i]+a[j]));
				trie.update(a[j],1);
			}
			trie.update(a[i],1);
		}
		printf("%d\n",ans);
	}
	return 0;
}