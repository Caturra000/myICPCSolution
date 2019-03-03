#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 5e5;
const int dep = 27;
struct TRIE{
	int son[maxn][dep],flag[maxn],id[maxn],tot,root,cnt;
	int node(){
		memset(son[tot],0,sizeof son[tot]);
		flag[tot]=id[tot]=0; 
		return tot++;
	}
	void init(){
		tot=0;cnt=0;
		root=node();
	}
	int getid(char str[]){
		int now=root,idx;
		for(int i = 0; str[i]; i++){
			idx=str[i]-'a';
			if(!son[now][idx]){
				son[now][idx]=node();
			}
			now=son[now][idx];
		}
		if(flag[now]) return id[now];
		flag[now]=1;  return id[now]=++cnt;
	}
}trie;
struct UF{
	int p[maxn];
	void init(){
		for(int i = 0; i < maxn; i++) p[i]=i;
	}
	int find(int x){
		return p[x]==x?x:p[x]=find(p[x]);
	}
	void link(int a,int b){
		a=find(a);b=find(b);
		if(a!=b) p[a]=b;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
}uf;
int degree[maxn],n;
char str1[100],str2[100];
int main(){
	trie.init();uf.init();
	while(scanf("%s%s",str1,str2)!=EOF){
		n++;
		int a=trie.getid(str1),b=trie.getid(str2);
		degree[a]++;degree[b]++;
		uf.link(a,b);
	}
	if(trie.flag[trie.root]||trie.tot<2){
		printf("Possible\n");
		return 0;
	}
	int anc=uf.find(1),num=0;
	bool flag=0;
	for(int i = 1; i <= trie.cnt; i++){
		if(!uf.same(i,anc)){
			flag=1;
			break;
		}
		if(degree[i]%2==1) num++;
		if(num>2){
			flag=1;
			break;
		}
	}
	if(num==1) flag=1;
	if(flag) printf("Impossible\n");
	else printf("Possible\n");
	return 0;
}