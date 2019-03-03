#include<cstdio>
#include<cstring>
const int maxn = 1e3+11;
const int kd = 2;
struct Trie{
	int son[maxn][2],end[maxn],tot,root;
	int node(){
		end[tot]=0; son[tot][0]=son[tot][1]=-1;
		return tot++;
	}
	void init(){
		tot=0;
		memset(son,-1,sizeof son);
		memset(end,0,sizeof end);
		root=node();
	}
	void insert(char str[]){
		end[root]++;
		int now=root,idx;
		for(int i = 0; str[i]!='\0'; i++){
			idx=str[i]-'0';
			if(son[now][idx]==-1){
				son[now][idx]=node();
			}
			end[son[now][idx]]++;
			now=son[now][idx];
			
		}
	} 
	bool check(char str[]){
		int now=root,idx;
		bool flag=1;
		for(int i = 0; str[i]!='\0'; i++){
			idx=str[i]-'0';
			if(end[son[now][idx]]<2){
				return 0;
			}
			now=son[now][idx];
		}
		return 1;
	}
}trie;
char str[1000][100];
int main(){
	int n=0,kase=0;
	while(scanf("%s",str[n])!=EOF){
		if(str[n][0]=='9'){
			trie.init();
			for(int i = 0; i < n; i++) trie.insert(str[i]);
			bool flag=0;
			for(int i = 0; i < n; i++){
				if(trie.check(str[i])){
					flag=1;break;
				}
			}
			if(!flag) printf("Set %d is immediately decodable\n",++kase);
			else printf("Set %d is not immediately decodable\n",++kase);
			n=0;continue;
		}
		n++;
	}
	return 0;
}