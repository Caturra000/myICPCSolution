#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
struct trie{
	int id;
	trie *next[12];
	trie(){
		for(int i = 0; i <= 11; i++){
			next[i] = NULL;
		}
		id = -1;
	}
};
trie *root = new trie();
int f[2][1000010];
char fib[52];
void add(char *str,int id){
//	trie *p = root;
//	int len = strlen(str);
//	for(int i = 0; i < len; i++){
//		p = p->next[str[i]-'0'];
//		if(!p){
//			p = new trie();
//		}
//		if(p->id == -1){//
//			p->id = id;
//		}
//		cout << "ID" << p->id << endl;
//	} //哪错了？ 
	int n = strlen(str);
		trie *u = root;
		for(int i = 0; i < n && i <= 40; i++){ //最大40位长度 
			int v = str[i]-'0';
			if(!u->next[v])
				u->next[v] = new trie();
			u = u->next[v];
			if(u->id == -1)
				u->id = id;
		}
}
int query(char *str){
	trie *p = root;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		p = p->next[str[i]-'0'];
		if(!p) return -1;
	}
	return p->id;
} 
int p,q,r,s = 0,e = 1,flag = 0;
int main(){
	//ios::sync_with_stdio(false);
	memset(f,0,sizeof f);
	f[0][0] = f[1][0] = 1; //
	add((char*)"1",0);add((char*)"1",1);
	for(int i = 2;i < 100000; i++){
		p = i&1,q = (i-1)&1,r=(i-2)&1; // init:0 1 //常系数优化 
		for(int j = s; j < e; j++){ //0放个位 1放十位 ... 末位是e-1位 
			f[p][j] = f[q][j]+f[r][j]; 

		}
		for(int j = s; j < e; j++){
			if(f[p][j] >= 10){
				f[p][j] %= 10;
				f[p][j+1]++;
			}
		}
		if(f[p][e]) e++;
		if(e-s > 50) s++;
//		memset(fib,0,sizeof fib);
//		for(int k = 0; k <= e-1; k++){
//			fib[k] = f[p][e-1-k]+'0';
//		} //爆内存 原因...? 
		int r = e-1,cnt = 0;
		memset(fib,0,sizeof fib);
		while(r >= 0 && cnt < 45)
			fib[cnt++] = f[p][r--] +'0';
		add(fib,i);
	}

	memset(fib,0,sizeof fib);
	int n,kase=0; scanf("%d",&n);
	char sss[42];
	for(int i = 0; i < n; i++){
		scanf("%s",&sss);
		printf("Case #%d: %d\n",++kase,query(sss));
	}
	return 0; 
}