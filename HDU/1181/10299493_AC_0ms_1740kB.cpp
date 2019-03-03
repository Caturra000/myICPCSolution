#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
//vector<char> G[30];
int G[30][30];
int flag,fflag;
bool vis[30][30]; 
queue<int> q; 
string str;

int main(){
	ios::sync_with_stdio(false);
	while(cin>>str){
		if(str[0]=='0'){
			//deal
			while(!q.empty()) q.pop();
			q.push('b'-'a');
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int v = 0; v < 26; v++){
					if(/*v==u || */G[u][v]==0) continue;
					if(vis[u][v]) continue;
					if(v=='m'-'a') fflag = 1;
					vis[u][v] = 1;
					q.push(v);
				}
			}
			if(vis['b'-'a']['m'-'a']==1) printf("Yes.\n");
			else{
//				for(int i = 0; i < 26; i++) if(vis['b'-'a'][i]==1) flag+=1;
//				for(int i = 0; i < 26; i++) if(vis[i]['m'-'a']==1) flag+=1;
				if(fflag==1) printf("Yes.\n");
				else printf("No.\n");
			}
			memset(vis,0,sizeof vis);
			memset(G,0,sizeof G);
			fflag = 0;
			continue;
			//deal
		}
		G[str[0]-'a'][str[str.length()-1]-'a'] = 1;
		
	}
	return 0;
}