#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
const int maxn = 1e6;
map<string,int> trie;
string str; 
char ch,sstr[233];
int cnt;
int main(){
	//ios::sync_with_stdio(false);
	trie.clear();cnt=0;
//	while(scanf("%c",&ch)==1){
//		if(cnt>1) break;
//		if(ch=='\n'){
//			str.clear();
//			cnt++;
//			continue;
//		}
//		
//	}
	while(1){
		str.clear();
		if(cnt>1) break;
		while(scanf("%c",&ch)==1&&ch!='\n'){
			cnt=0;
			str+=ch;
//			cout<<str<<endl; 
			trie[str]++; 
		}
		cnt++;
	}
	while(scanf("%s",sstr)!=EOF){
		string sss(sstr);
		printf("%d\n",trie[sss]);
	}
	return 0;
} 